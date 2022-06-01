/**
 *  Program file name   : stack.h
 *  Description         : deklarasi header file untuk struktur data stack pada program Kakuraato.
 *  Author              : Danu Mahesa, 211524037
 *  Compiler            : GCC
 *
 */

#ifndef stack_H
#define stack_H

#include<stdio.h>
#include<conio.h>
#include <stdbool.h>
 
#define MAX_ELMT 40

typedef struct tNodeStack{
    int* oper;
    int top;
}tNodeStack;

/**
 * Mengalokasikan memori untuk sebuah stack dan menginisialisasi stack->top = -1
 */
tNodeStack* createStack(int length);

/**
 * Mengecek apakah sebuah stack kosong atau tidak 
 */
int isEmpty(tNodeStack *stack);

/**
 * Menghapus elemen puncak dari Stack dan mengembalikan nilai info ke bagian pemanggil.
 */
char Pop(tNodeStack *stack);

/**
 * Menambahkan ch sebagai elemen stack di bagian puncak.
 */
void Push(tNodeStack *stack, char ch);

/**
 * Mengembalikan nilai p->data[p->top] sebagai nilai bertipe integer (nomor ASCII).
 */
int Top(tNodeStack *p); 

/**
 * Mendapatkan nilai prioritas suatu operator
 * berdasarkan apa yang disebutkan dalam hukum matematika (precedence)
 */
int getPriority(char opr);

/**
 * Mengubah notasi infix menjadi notasi postfix.
 * Kembalikan nilai -1 jika ada operator ataupun operand yang tidak valid untuk dikonversi.
 */
int infix_to_postfix(char infix[],char postfix[]);

#endif
