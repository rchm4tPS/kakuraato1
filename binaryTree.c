#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#include <stdbool.h>
#include "binaryTree.h"

int t = 0;

addr createNode (double opValue, bool isOperand) {
    addr _newNode = (addr)malloc(sizeof(NodeBinTree));

    if (_newNode != NULL) {
        _newNode->opValue = opValue;
        _newNode->isOperand = isOperand;
        _newNode->left = _newNode->right = NULL;
    }

    return _newNode;
}

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

void printTree (addr root, char* expression) {
    double number = 0;
    int leftNum = 0, rightNum = 0;
    int i = 0;
    char num[40];

    memset(num, 0, 40);

    if (root != NULL) {
        if (root->isOperand) {
            printf("%.2f", root->opValue);

            number = root->opValue;
            leftNum = (int)number;
            number -= leftNum;
            number *= 100;
            rightNum = (int)number;
            itoa(leftNum, num, 10);
            for (i = 0; i < strlen(num); i++) {
                expression[t++] = num[i];
            }
            expression[t++] = '.';
            itoa(rightNum, num, 10);
            if (rightNum == 0) {
                for (i = 0; i < 2; i++) {
                    expression[t++] = '0';
                }
            } else {
                for (i = 0; i < 2; i++) {
                    expression[t++] = num[i];
                }
            }
        } else {
            printf("%c", (int)root->opValue);
            expression[t++] = (char)root->opValue;
        }

        printf("(");
        expression[t++] = '(';
        printTree(root->left, expression);
        printTree(root->right, expression);
        printf(")");
        expression[t++] = ')';
    }
}

addr BuildTreeFromPostfix (char* expression) {
    addr tree = NULL;
    int i, len, index;
    char number[40];
    double temp;

    len = strlen(expression);

    for (i = len - 1; i >= 0; i--) {
        if (expression[i] == ' ') {
      		continue;
   		}

        if (isdigit(expression[i]) || expression[i] == '.') {
            index = 0;
            do {
                number[index++] = expression[i--];
            } while ((i >= 0 && isdigit(expression[i])) || expression[i] == '.');
            number [index] = '\0';

            
            temp = strtod(strrev(number), NULL); 
            tree = insertNodeToTree(temp, true, tree);
        }

        else {
            tree = insertNodeToTree(expression[i], false, tree);
        }
        
    }
    return tree;
}

double TreeCalculate(addr root) 
{
	/* Mengkalkulasikan expression tree */
	/* IS : - */
	/* FS : Mengembalikan nilai kalkulasi berupa double */
	
	/* Kamus Data */
	double rightOp, leftOp;
	
	/* Algoritma */
    // Hanya angka saja
	if (root->isOperand) {
    	return root->opValue;
	}
	
	// Rekursif kanan
    rightOp = TreeCalculate(root->right);
    
    // Memproses UNARY OPERATOR
    if (root->opValue == '-') {
		return rightOp * -1;
	}
	if (root->opValue == '#') {
		return sqrt(rightOp);
	}
	
    // Rekursif kiri
    leftOp = TreeCalculate(root->left);
	
    // Memroses BINARY OPERATOR
    switch ((int)(root->opValue)) {
		case '+':
	        return leftOp + rightOp;
		case '*':
	        return leftOp * rightOp;
		case '/':
	        return leftOp / rightOp;
		case '^':
	        return pow(leftOp, rightOp);
	}
}