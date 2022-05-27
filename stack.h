/**
 * @file stack.h
 * @author Danu Mahesa
 * @brief header file untuk stack alokasi statis dengan array
 * Date : 26 Mei 2022
 * 
 */

#ifndef stack_H
#define stack_H

#include<stdio.h>
#include<conio.h>
#include <stdbool.h>
 
#define MAX 20

typedef struct tNodeStack{
    int* oper;
    int top;
}tNodeStack;

tNodeStack* createStack(int length);

int isEmpty(tNodeStack *stack);

char Pop(tNodeStack *stack);

void Push(tNodeStack *stack, char x);

int Top(tNodeStack *p); 

int getPriority(char opr);

int infix_to_postfix(char infix[],char postfix[]);

#endif
