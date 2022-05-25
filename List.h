#ifndef LIST_H
#define LIST_H

#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define Nil NULL
#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) (L).First

typedef struct tNodeList* address;
	  typedef struct tNodeList {
		char expression[40];
		address next;
	  }
	  typedef struct 
	  {
		address root/head;
	  }
	  
void CreateList (List *L);
/* 	I.S : L terdefinisi, tidak diketahui nilainya
	F.S : L diinisialisasi first(L) = nil
*/

address Alokasi (infotype X);
/*	Mengirimkan address hasil alokasi sebuah elemen
	Jika alokasi berhasil, maka address !=Nil,
	dan misalnya menghasilkan P, maka Info(P)= x, Next(P)=Nil
	Jika alokasi gagal, mengirimkan Nil
*/

void DeAlokasi (address P);
/*	I.S : P terdefinisi
	F.S : P dikembalikan ke sistem
	Melakukan dealokasi/ pengembalian address P ke system.
*/

void InsFirst (List *L, infotype X);
/*	I.S : L terdefinisi, mungkin kosong
	F.S : melakukan alokasi sebuah elemen dan
		  menambahkan elemen pertama pada List dengan nilai X jika alokasi
	      berhasil. Jika alokasi gagal IS = FS
*/

void InsLast(List *L, infotype X);
/*I.S : L terdefinisi, mungkin kosong
F.S : melakukan alokasi sebuah elemen dan
menambahkan elemen terakhir pada List dengan nilai X jika alokasi
berhasil. Jika alokasi gagal IS = FS
*/

void PrintInfo(List L);
/* I.S : L terdefinisi, mungkin kosong
F.S : Jika List tidak kosong, menampilkan semua info yang disimpan pada
elemen list ke layar. jika List kosong, hanya menampilkan pesan “list
kosong”
*/


	  
