/**
 *  Program file name   : test_Calc.c
 *  Description         : Main driver untuk program Kakuraato
 *  Author              : Danu Mahesa, 211524037 || Extended by : Rachmat Purwa Saputra, 211524054
 *  Compiler            : GCC
 *
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<sys/time.h>

#include "binaryTree.c"
#include "stack.c"
#include "tampilan.c"
#include "list.c"
#include "calcAkarKuadrat.c"
#include "calcStandar.c"
#include "history.c"

void beginApplication();

int main() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 229); // asalnya 125, lalu 229 - alternatifnya 245. Ada lagi 252 (merah) atau 249 (biru cerah).
	
	// Inisialisasi jendela cmd agar bersih
    system("cls");

    // Make the console windows become full-size
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	
	// Aplikasi dimulai
	beginApplication();

    return 0;
}

void beginApplication() {
	char inputUser;
	int _X = getScreenWidth() / 2 - 31;
	int _Y = getScreenHeight() / 2 - 9;
	
	// Lakukan selama user belum memilih untuk keluar dari aplikasi
	do{	
		system("cls");
		tampilMainMenu();
	    printf("\n");

		gotoxy(_X + 17, _Y + 20);
		scanf(" %c",&inputUser);	

		if (inputUser == 48) {
			break;
		}
		else if (inputUser == 49){
			// proses kalkulator standar dimulai
			initiateStandardCalc();
		}
		else if (inputUser == 50) {
			// proses kalkulator akar kuadrat dimulai
			initializeCalcAkarKuadrat();
		}
		else if (inputUser == 51) {
			// menampilkan fitur help
			tampilHelp();
		}
		else if (inputUser == 52) {
			// menampilkan history penggunaan kalkulator standar.
			showHistory();
		}
		else if (inputUser == 53) {
			// menampilkan fitur credit
			tampilCredit();	
	    }
		else {
			// inputan angka tidak valid, beritakan kesalahan input
			gotoxy(_X + 25, _Y + 20);
			printf("Harap masukkan angka 0, 1, 2, 3, 4, atau 5 saja!");
			getche();
		}
	} while (inputUser != 48);  // selama bukan digit 0 yang dipilih user
}
