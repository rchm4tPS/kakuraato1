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
