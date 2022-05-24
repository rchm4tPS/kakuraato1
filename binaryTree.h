/**
 *
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
typedef struct {
    addr root;                      // address of root node
} BinTree;

addr createNode (double opValue, bool isOperand);

addr insertNodeToTree (double opValue, bool isOperand, addr root);

void printTree (addr root, char* expression);

addr BuildTreeFromPostfix (char* expression);

double TreeCalculate(addr root);

#endif