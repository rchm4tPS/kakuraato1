/**
 *  Program file name   : List.h
 *  Description         : deklarasi header file untuk struktur data linked list dinamis pada program Kakuraato.
 *  Author              : Husna Maulana, 211524045
 *  Compiler            : GCC
 *
 */

#ifndef LIST_H
#define LIST_H


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define Nil NULL

typedef struct tNodeList* address;
typedef struct tNodeList {
	char expression[40];
	double result;
	char timeEnteringExpression[64];
	address next;
}NodeList;
typedef struct{
	address root;
} List;
	  
/* 	I.S : L terdefinisi, tidak diketahui nilainya
	F.S : L diinisialisasi L.root = nil
*/
void CreateList(List *L);

/*	Mengirimkan address hasil alokasi sebuah elemen
	Jika alokasi berhasil, maka address !=Nil,
	Jika alokasi gagal, mengirimkan Nil
*/
address Alokasi(char* expression, double result, char* timeOfCalculation);

/*	I.S : P terdefinisi
	F.S : P dikembalikan ke sistem
			Melakukan dealokasi/ pengembalian address P ke system.
*/
void DeAlokasi (address P);

/*I.S : L terdefinisi, mungkin kosong
  F.S : melakukan alokasi sebuah elemen dan
		menambahkan elemen terakhir pada List dengan array expression jika alokasi
		berhasil. Jika alokasi gagal IS = FS
*/
void InsLast (List *L, char* expression, double result, char* timeOfCalculation);

/* I.S : L terdefinisi, mungkin kosong
   F.S : Jika List tidak kosong, menampilkan semua info yang disimpan pada
		 elemen list ke layar.
*/  
void PrintInfo(List L);


#endif

	  
