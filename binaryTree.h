/**
 *  Program file name   : binaryTree.h
 *  Description         : deklarasi header file untuk struktur data binary tree pada program kalkulator
 *  Author              : Rachmat Purwa Saputra, 211524054
 *  Compiler            : GCC
 *
 */

#ifndef binaryTree_H
#define binaryTree_H

#define nil NULL
#define opVal(P) P->opValue
#define isOperand(P) P->isOperand
#define left(P) P->left
#define right(P) P->right

#include <stdio.h>                  // scanf, printf
#include <stdlib.h>                 // malloc, getche
#include <string.h>                 // strtod, strrev, strlen, isdigit
#include <math.h>                   // fmod, pow, sqrt
#include <windows.h>
#include <stdbool.h>                // bool : true, false

typedef struct tNodeBinTree* addr;
typedef struct tNodeBinTree {
    double opValue;                 // to preserve both operand and operator
    bool isOperand;                 // value checking whether the node is number or not
    addr left, right;
} NodeBinTree;


/**
 * Type : function
 * Tujuan : membuat sebuah node baru yang dialokasikan di dalam memori
 *          dengan beberapa field node yang berhasil dialokasikan diisi
 *          oleh nilai dari parameter. Pointer left dan right diinisialisasi
 *          oleh nilai NULL.
 */
addr createNode (double opValue, bool isOperand);

/**
 * Type : procedure
 * Tujuan : mengalokasikan sekian byte memori untuk menyimpan 1 elemen node
 *          pada binary tree kalkulator ini.
 * Initial state : nilai address pada parameter masih bernilai nil
 * Final state : nilai address pada parameter sudah diperbaharui
 */
void AlokasiMemoriNode (addr* _newNode);

/**
 * Type : function
 * Tujuan : memasukkan node baru ke dalam struktur binary tree dengan melihat
 *          keadaan node son di kiri ataupun di kanannya. Proses bisa dilakukan
 *          secara rekursif hingga ditemui daerah yang dapat dimasuki node baru
 *          ke dalam struktur binary tree.
 */
addr insertNodeToTree (double opValue, bool isOperand, addr root);

/**
 * Type : procedure
 * Tujuan : Menampilkan seluruh element di dalam tree secara pre-order traversal.
 *          Dimulai dari root node hingga leaf node paling akhir.
 * Initial State : elemen-elemen di dalam tree belum ditampilkan.
 * Final State : elemen-elemen di dalam tree sudah ditampilkan ke layar
 */
void printTree (addr root);

/**
 * Type : function
 * Tujuan : membuat/membangun binary tree dari notasi postfix pada parameter input.
 *          Pembacaan notasi postfix dilakukan dari belakang agar selalu dipastikan
 *          bahwa root node dari tree yang dibangun merupakan operator. Kecuali
 *          pada kasus dimana hanya angka yang diinput sebagai ekspresi matematika.
 * 
 */
addr createTreeFromPostfix (char* expression);

/**
 * Type : function
 * Tujuan : menghitung seluruh operand di dalam binary tree dengan operatornya, lalu
 *          mengembalikan hasil perhitungannya. Dilakukan secara rekursif.
 */
double calculateTreeExpression(addr root);

/**
 * Type : function
 * Tujuan : melakukan perhitungan antara dua bilangan yang operatornya
 *          adalah operator '+', '*', '/', atau '^'. Kembalikan nilai perhitungannya
 *          dalam bentuk bilangan desimal (double).
 */
double calculateWithBinaryOperator(int root_operator, double leftNum, double rightNum);


#endif