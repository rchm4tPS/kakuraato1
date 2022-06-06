/**
 *  Program file name   : stack.c
 *  Description         : definisi dari header file untuk struktur data stack pada program Kakuraato.
 *  Author              : Danu Mahesa, 211524037
 *  Compiler            : GCC
 *
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "stack.h"

tNodeStack* createStack(int length){
    tNodeStack* stack = (tNodeStack*)malloc(sizeof(tNodeStack));
    
    stack->oper = (int*)malloc(sizeof(int) * length);
    stack->top=-1;

    return stack;
}

int isEmpty(tNodeStack *stack)
{
    if(stack->top == -1)
    	return (1);
 	else
   		return (0);
}

void Push(tNodeStack *stack, char ch)
{
    stack->top = stack->top+1;
    stack->oper[stack->top] = ch;
}

char Pop(tNodeStack *stack)
{    
    if (!isEmpty(stack)) {
        return stack->oper[stack->top--];
    } else {
        return '\0';
    }
}

int Top(tNodeStack *p){
    return (p->oper[p->top]);
}

int getPriority(char opr){
    if(opr=='+'||opr=='-')
        return (1);
    if(opr=='*'||opr=='/')
        return (2);
    if(opr=='^')
        return (3);
    if(opr=='#')
        return (4);
 	else
    	return (-1);
}

int infix_to_postfix(char infix[], char postfix[])
{
    tNodeStack* s = createStack(strlen(infix));
    char ch, token;
    int i,j;    //i-index of infix,j-index of postfix
    
    j=0;
 
    // selama masih ada karakter untuk diiterasi dalam array infix, lakukan :
    for(i=0; infix[i]!='\0'; i++)
    {
        token = infix[i];

        if (token == ' ') continue;

        // bila merupakan digit angka atau titik (desimal)
        else if (isdigit(infix[i]) || infix[i] == '.') {
            do {
                // isi array postfix selama masih ditemui digit angka pada array infix selanjutnya
                postfix[j++] = infix[i++];
            } while (isdigit(infix[i]) || infix[i] == '.');

            // pisahkan antara angka dengan operator oleh tanda spasi
            postfix[j++] = ' ';
            i--;
        }
        
        // langsung push ke dalam stack jika karakter merupakan kurung buka
        else if (token == '(')
            Push(s, token);
        
        // jika kurung tutup ditemui, keluarkan isi stack
        else if (token == ')') {
            // selama belum menemui tanda kurung buka di dalam stack dan belum kosong stacknya
            while((ch = Top(s)) != '(' && !isEmpty(s)) {
                postfix[j++] = Pop(s);  // elemen yang di pop dimasukkan ke dalam array postfix
                postfix[j++] = ' ';  // beri spasi antar elemen yang dipop dari stack pada array postfix
            }
                    
            if (!isEmpty(s) && Top(s) != '(') {
                return -1; // jumlah pasangan kurung tidak sesuai
            } else {
                Pop(s);
            }
        }

        // jika merupakan operator ( +, -, *, /, #, atau ^ )
        else {
            while(getPriority(token) <= getPriority(Top(s)) && !isEmpty(s))
            {
                // keluarkan dari stack jika precedence infix lebih kecil atau sama dengan precedence pada puncak stack
                ch = Pop(s);
                postfix[j++] = ch;
                postfix[j++] = ' ';
            }

            if (infix[i] == '-' && isdigit(infix[i-1])) {
                Push(s, '+');
            }

            Push(s,token);
        }
    }
 
    // jika masih ada elemen di dalam stack, keluarkan semuanya.
    while(!isEmpty(s))
    {
        ch = Pop(s);
        postfix[j++] = ch;
        postfix[j++] =' ';
    }
    
    // akhiri array postfix dengan '\0' sebagai penanda akhir array
    postfix[j--] = '\0';

    return 0;
}
