#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#include <stdbool.h>
#include "binaryTree.h"


addr createNode (double opValue, bool isOperand) {
    addr _newNode = (addr)malloc(sizeof(NodeBinTree));

    if (_newNode != NULL) {
        _newNode->opValue = opValue;
        _newNode->isOperand = isOperand;
        _newNode->left = _newNode->right = NULL;
    }

    return _newNode;
}

/*
    Ide besarnya adalah :
        - kunjungi root node
        - jika root tsb. NULL, buat sebuah node
        - jika root sebelah kanan bukan NULL ataupun digit atau operand, kunjungi daerah sub-tree kanan
        - jika root sebelah kiri yang bukan NULL ataupun bukan digit angka/operand, DAN nilai node root bukan karakter '-' ataupun '#', kunjungi daerah sub-tree kanan

        - jika tidak memenuhi semua kriteria di atas, kembalikan nilai address NULL
*/
addr insertNodeToTree (double opValue, bool isOperand, addr root) {
    addr newNode;

    if (root == NULL) {
        return createNode(opValue, isOperand);
    }

    if (root->right == NULL || !root->right->isOperand) {
        newNode = insertNodeToTree(opValue, isOperand, root->right);
        if (newNode != NULL) {
            root->right = newNode;
            return root;
        }
    }

    // berupa operator unary (negatif atau akar kuadrat)
    if (root->opValue != '-' && root->opValue != '#' && 
        (root->left == NULL || !root->left->isOperand)) {
        newNode = insertNodeToTree(opValue, isOperand, root->left);
        if (newNode != NULL) {
            root->left = newNode;
            return root;
        }
    }

    return NULL;
}

/*
    Menampilkan susunan element di dalam tree secara pre-order traversal.
*/
void printTree (addr root, char* expression) {
    double number = 0;
    int leftNum = 0, rightNum = 0;
    int i = 0;
    int t = 0;
    char num[40];

    memset(num, 0, 40);

    if (root != NULL) {
        if (root->isOperand) {
            // use fmod to count the remainders of floating number (instead of using % operator)
            if (fmod(root->opValue, 2.00) != 0.00) printf("%.2f", root->opValue);
            else printf("%d", (int)root->opValue); // print only number without leading zero if it's a whole number

            number = root->opValue;
            leftNum = (int)number;
            number -= leftNum;
            number *= 100;
            rightNum = (int)number;
            itoa(leftNum, num, 10); // convert int dengan base 10 (bilangan desimal) to string

            for (i = 0; i < strlen(num); i++) {
                expression[t++] = num[i];
            }

            expression[t++] = '.';
            itoa(rightNum, num, 10);
            if (rightNum == 0) {
                // tambahkan dua char '0' setelah tanda titik pada array expression
                // for (i = 0; i < 2; i++) {
                //     expression[t++] = '0';
                // }
            } else {
                // tambahkan dua char digit sebelah kanan koma setelah tanda titik pada array expression
                for (i = 0; i < 2; i++) {
                    expression[t++] = num[i];
                }
            }
        } else {
            // tampilkan langsung karakter operator
            printf("%c", (int)root->opValue);

            // tuliskan setiap karakter operator pada parameter input/output array of char expression
            expression[t++] = (char)root->opValue;
        }

        printf(" ");
        expression[t++] = '(';
        printTree(root->left, expression);
        printTree(root->right, expression);
        // printf(" ");
        expression[t++] = ')';
    }
}

addr BuildTreeFromPostfix (char* expression) {
    addr tree = NULL;
    int i, index;
    char number[40];
    double temp;

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

double TreeCalculate(addr root) 
{	
	double rightNumber, leftNumber;
	
    // Ditemui element node merupakan digit operand
	if (root->isOperand) {
    	return root->opValue;
	}
	
	// Menelusuri sub-tree kanan secara rekursif hingga ditemui operand
    rightNumber = TreeCalculate(root->right);
    
    // Ditemui operator negatif atau akar kuadrat di awal digit
    if (root->opValue == '-') {
		return rightNumber * -1;
	}
	if (root->opValue == '#') {
		return sqrt(rightNumber);
	}
	
    // Menelusuri sub-tree kiri secara rekursif hingga ditemui operand
    leftNumber = TreeCalculate(root->left);
	
    // Menghitung dua bilangan kiri dan kanan dengan operator yang sesuai pada parent keduanya
    switch ((int)(root->opValue)) {
		case '+':
	        return leftNumber + rightNumber;
		case '*':
	        return leftNumber * rightNumber;
		case '/':
	        return leftNumber / rightNumber;
		case '^':
	        return pow(leftNumber, rightNumber);
	}
}