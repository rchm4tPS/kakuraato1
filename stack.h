#ifndef stack_h
#define stack_h

#include<stdio.h>
#include<conio.h>
#include<ctype.h>
 
#define MAX 20

typedef struct tNodeStack{
    char oper[MAX];
    int top;
}tNodeStack;

void createStack(tNodeStack *stack);

int isEmpty(tNodeStack *stack);

int isFull(tNodeStack *stack);

int Pop(tNodeStack *stack);

void Push(tNodeStack *stack, int x);

int Top(tNodeStack *p); 

int getPriority(char opr);

void infix_to_postfix(char infix[],char postfix[]);

#endif
