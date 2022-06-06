/**
 *  Program file name   : binaryTree.c
 *  Description         : definisi dari header file untuk struktur data binary tree pada program kalkulator
 *  Author              : Rachmat Purwa Saputra, 211524054
 *  Compiler            : GCC
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#include <stdbool.h>
#include "binaryTree.h"


addr createNode (double opValue, bool isOperand) {
    addr _newNode = nil;
    AlokasiMemoriNode(&_newNode);

    // Jika alokasi berhasil dilakukan, isi field node baru tersebut
    if (_newNode != nil) {
        opVal(_newNode) = opValue;
        isOperand(_newNode) = isOperand;
        left(_newNode) = right(_newNode) = nil;
    }

    return _newNode;
}


void AlokasiMemoriNode (addr* _newNode) {
    *(_newNode) = (addr)malloc(sizeof(NodeBinTree));
}


addr insertNodeToTree (double opValue, bool isOperand, addr root) {
    addr newNode;

    // jika root tsb. NULL, buat sebuah node dan kembalikan alamat node tsb. berada
    if (root == nil) {
        return createNode(opValue, isOperand);
    }

    // jika pointer right bernilai NULL ataupun right bukan digit/operand
    // kunjungi daerah sub-tree kanan untuk diisi node baru
    if (right(root) == nil || !isOperand(right(root))) {
        newNode = insertNodeToTree(opValue, isOperand, right(root));
        if (newNode != nil) {
            // hubungkan node baru dengan parentnya
            right(root) = newNode;
            return root;
        }
    }

    // jika pointer left bernilai NULL ataupun left bukan digit/operand, 
    // DAN nilai node root bukan karakter '-' ataupun '#'
    // kunjungi daerah sub-tree kiri untuk diisi node baru
    if (opVal(root) != '-' && opVal(root) != '#' && 
        (left(root) == nil || !isOperand(left(root)))) {
        newNode = insertNodeToTree(opValue, isOperand, left(root));
        if (newNode != nil) {
            // hubungkan node baru dengan parentnya
            left(root) = newNode;
            return root;
        }
    }

    // jika tidak memenuhi 3 kriteria di atas, kembalikan nilai NULL
    return nil;
}


void printTree (addr root) {
    if (root != nil) {
        if (isOperand(root)) {
            // use fmod to count the remainders of floating number (instead of using % operator)
            if (fmod(opVal(root), 1.00) != 0.00) {
                printf("%.2f", opVal(root));
            } else {
                // print only number without leading zero if it's a whole number
                printf("%.0f", opVal(root));
            }
        } else {
            // tampilkan langsung karakter operator
            printf("%c", (int)opVal(root));
        }

        printf(" ");
        printTree(left(root));
        printTree(right(root));
    }
}


addr createTreeFromPostfix (char* expression) {
    addr tree = nil;
    int i, index;
    char number[40];
    double temp;

    // read every character in expression array one by one from the end to the very first char
    for (i = strlen(expression) - 1; i >= 0; i--) {
        if (expression[i] == ' ') {
      		continue;
   		}

        // masukkan elemen operand/angka ke dalam tree
        if (isdigit(expression[i]) || expression[i] == '.') {
            index = 0;  // indeks pada array of digit character saja
            do {
                // cari digit angka sampai ditemukan karakter non-angka
                number[index++] = expression[i--];
            } while ((i >= 0 && isdigit(expression[i])) || expression[i] == '.');
            number [index] = '\0'; // beri pembatas terminator karena masih dalam bentuk array

            // ubah string number yang dibalik ke dalam bilangan bertipe double
            temp = strtod(strrev(number), NULL); 
            // masukkan elemen digit pada array temp ke dalam tree (karena bisa jadi digit lebih dari satu)
            tree = insertNodeToTree(temp, true, tree);
        }

        // langsung masukkan elemen operator ke dalam tree
        else {
            tree = insertNodeToTree(expression[i], false, tree);
        }
        
    }
    return tree;
}


double calculateTreeExpression(addr root) 
{	
	double rightNumber, leftNumber;
	
    // Ditemui element node merupakan digit operand
	if (isOperand(root)) {
    	return opVal(root);
	}
	
	// Menelusuri sub-tree kanan secara rekursif hingga ditemui operand
    rightNumber = calculateTreeExpression(right(root));
    
    // Ditemui operator negatif atau akar kuadrat di awal digit
    if (opVal(root) == '-') {
		return rightNumber * -1;
	}
	if (opVal(root) == '#') {
		return sqrt(rightNumber);
	}
	
    // Menelusuri sub-tree kiri secara rekursif hingga ditemui operand
    leftNumber = calculateTreeExpression(left(root));
	
    // Ditemui operator biner (+ atau / atau * atau ^)
    return calculateWithBinaryOperator((int)(opVal(root)), leftNumber, rightNumber);
}


double calculateWithBinaryOperator(int root_operator, double leftNum, double rightNum) {
    switch ((root_operator)) {
		case '+':
	        return leftNum + rightNum;
		case '*':
	        return leftNum * rightNum;
		case '/':
	        return leftNum / rightNum;
		case '^':
	        return pow(leftNum, rightNum);
	}
}
