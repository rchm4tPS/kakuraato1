#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

#include "binaryTree.c"
#include "stack.c"
#include "tampilan.c"

int main() {
    system("cls");
    system("mode 145, 40");

    tampilMainMenu();
    printf("\n");

    char infix[21];
    char postfix[21];
    char treeHistory[41] = "";

    printf("\t Masukkan ekspresi matematika : ");
    scanf(" %[^\n]%*c", infix);
    infix_to_postfix(infix, postfix);
    printf("\n\t Dalam notasi post-fix : %s\n", postfix);
    
    addr treeRoot = BuildTreeFromPostfix(postfix);
    printf("\n\t Traversal node pre-order di dalam binary tree-nya : \n\t");
    printTree(treeRoot, treeHistory);

    double result = TreeCalculate(treeRoot);
    printf(" \n\n\tThe result is : %.2f \n", TreeCalculate(treeRoot));

    return 0;
}