#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "binaryTree.c"
#include "stack.c"
#include "tampilan.c"

int main() {
    char infix[21];
    char postfix[21];
    char treeHistory[41] = "";

    scanf(" %[^\n]%*c", infix);
    infix_to_postfix(infix, postfix);
    printf(" \n%s\n", postfix);
    
    addr treeRoot = BuildTreeFromPostfix(postfix);

    double result = TreeCalculate(treeRoot);
    printf(" \n The result is : %.2f", TreeCalculate(treeRoot));

    // printBanner();

    return 0;
}