/**
 *  Program file name   : binaryTree.h
 *  Description         : deklarasi header file untuk struktur data binary tree pada program kalkulator
 *  Author              : Rachmat Purwa Saputra, 211524054
 *  Date                : 26 Mei 2022
 *  Compiler            : GCC
 *
 */

#ifndef binaryTree_H
#define binaryTree_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#include <stdbool.h>

typedef struct tNodeBinTree* addr;
typedef struct tNodeBinTree {
    double opValue;                 // to preserve both operand and operator
    bool isOperand;                 // value checking whether the node is number or not
    addr left, right;
} NodeBinTree;


addr createNode (double opValue, bool isOperand);

addr insertNodeToTree (double opValue, bool isOperand, addr root);

void printTree (addr root, char* expression);

addr BuildTreeFromPostfix (char* expression);

double TreeCalculate(addr root);


#endif