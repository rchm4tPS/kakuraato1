/**
 *  Program file name   : tampilan.c
 *  Description         : definisi prototipe modul-modul behavior untuk tampilan pada Kakuraato.
 *  Author              : Danu Mahesa, 211524037
 *  Compiler            : GCC
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include "tampilan.h"

int getScreenWidth() {
    CONSOLE_SCREEN_BUFFER_INFOEX _infoex = {0};
    HANDLE handleOfConsoleOutput = NULL;

    handleOfConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    _infoex.cbSize = sizeof(_infoex);
    GetConsoleScreenBufferInfoEx(handleOfConsoleOutput, &_infoex);

    return _infoex.srWindow.Right;
}

int getScreenHeight() {
    CONSOLE_SCREEN_BUFFER_INFOEX _infoex = {0};
    HANDLE handleOfConsoleOutput = NULL;

    handleOfConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    _infoex.cbSize = sizeof(_infoex);
    GetConsoleScreenBufferInfoEx(handleOfConsoleOutput, &_infoex);

    return _infoex.srWindow.Bottom;
}

void tampilMainMenu(){
	int widthOfScreen = getScreenWidth();
	int heightOfScreen = getScreenHeight();

	int _X = widthOfScreen / 2 - 31;
	int _Y = heightOfScreen / 2 - 9;

	gotoxy(_X - 8, _Y - 3);
	printf("=====================================================================================\n");
	printBanner();
	printf("\n\n");
	gotoxy(_X - 8, _Y + 10);
	printf("Pilihan Menu:\n");
	gotoxy(_X - 6, _Y + 11);
	printf("1. Kalkulator Standar\n");
	gotoxy(_X - 6, _Y + 12);
	printf("2. Kalkulator Akar Kuadrat\n");
	gotoxy(_X - 6, _Y + 13);
	printf("3. Help\n");
	gotoxy(_X - 6, _Y + 14);
	printf("4. History Penggunaan Kakuraato\n");
	gotoxy(_X - 6, _Y + 15);
	printf("5. Credit\n");
	gotoxy(_X - 6, _Y + 16);
	printf("\n");
	gotoxy(_X - 6, _Y + 17);
	printf(" 0. Exit\n");
	gotoxy(_X - 8, _Y + 18);
	printf("\n\n");
	gotoxy(_X - 8, _Y + 19);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205, 205, 205 ,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205, 205, 205,187);
	gotoxy(_X - 8, _Y + 20);
	printf("%c  Menu Yang Dipilih : [   ]  %c\n",186,186);
	gotoxy(_X - 8, _Y + 21);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200, 205, 205, 205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205, 205, 205,188);
	gotoxy(_X - 8, _Y + 22);
	printf("\n\n");
	gotoxy(_X - 8, _Y + 23);
	printf("=====================================================================================\n");
}

void tampilKalkStandar(){
	int _X = getScreenWidth() / 2 - 31;
	int _Y = getScreenHeight() / 2 - 9;

	system("cls");
	gotoxy(_X - 2, _Y);
	printf("========================================================================\n");
	gotoxy(_X + 25, _Y + 2);
	printf("KALKULATOR STANDAR\n");
	gotoxy(_X + 2, _Y+5);
	printf("\n\n");
	gotoxy(_X +2, _Y + 6);
	printf("Ekspresi");
	gotoxy(_X +20, _Y + 6);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
	gotoxy(_X +2, _Y + 7);
	printf("Matematika");
	gotoxy(_X +20, _Y + 7);
	printf("%c                                      %c\n",186,186);
	gotoxy(_X +2, _Y + 8);
	printf("Yang Dihitung");
	gotoxy(_X +20, _Y + 8);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
	gotoxy(_X +2, _Y + 9);
	printf("\n");
	gotoxy(_X +2, _Y + 10);
	printf("Hasil");
	gotoxy(_X +20, _Y + 10);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
	gotoxy(_X +2, _Y + 11);
	printf("Perhitungan");
	gotoxy(_X +20, _Y + 11);
	printf("%c                                      %c\n",186,186);
	gotoxy(_X +2, _Y + 12);
	printf("Ekspresi");
	gotoxy(_X +20, _Y + 12);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
	gotoxy(_X +2, _Y + 13);
	printf("\n\n");
	gotoxy(_X +2, _Y + 15);
	printf("Silakan tekan huruf Q untuk kembali ke home menu : \n");
	gotoxy(_X +2, _Y + 16);
	printf("Atau tekan huruf apapun selain Q untuk kembali menggunakan kalkualtor standar");
	gotoxy(_X - 2, _Y + 18);
	printf("========================================================================\n");
}

void tampilKalkAkur(){
	int _X = getScreenWidth() / 2 - 31;
	int _Y = getScreenHeight() / 2 - 9;

	system("cls");
	gotoxy(_X - 2, _Y - 4);
	printf("========================================================================\n\n");
	gotoxy(_X + 23, _Y - 2);
	printf("KALKULATOR AKAR KUADRAT\n");
	gotoxy(_X + 20, _Y - 1);
	printf("(bentuk umum x^2 + x + 1 = 0)");
	gotoxy(_X + 2, _Y+1);
	printf("\n\n");
	gotoxy(_X +2, _Y + 2);
	printf("Ekspresi");
	gotoxy(_X +20, _Y + 2);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
	gotoxy(_X +2, _Y + 3);
	printf("Matematika");
	gotoxy(_X +20, _Y + 3);
	printf("%c                                         %c\n",186,186);
	gotoxy(_X +2, _Y + 4);
	printf("Yang Dihitung");
	gotoxy(_X +20, _Y + 4);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
	gotoxy(_X +2, _Y + 5);
	printf("\n");
	gotoxy(_X +2, _Y + 6);
	printf("Nilai");
	gotoxy(_X +20, _Y + 6);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
	gotoxy(_X +2, _Y + 7);
	printf("Akar");
	gotoxy(_X +20, _Y + 7);
	printf("%c                                         %c\n",186,186);
	gotoxy(_X +2, _Y + 8);
	printf("Ke-1");
	gotoxy(_X +20, _Y + 8);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
	gotoxy(_X +2, _Y + 9);
	printf("\n");
	gotoxy(_X +2, _Y + 10);
	printf("Nilai");
	gotoxy(_X +20, _Y + 10);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205, 205, 205, 205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
	gotoxy(_X +2, _Y + 11);
	printf("Akar");
	gotoxy(_X +20, _Y + 11);
	printf("%c                                         %c\n",186,186);
	gotoxy(_X +2, _Y + 12);
	printf("ke-2");
	gotoxy(_X +20, _Y + 12);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
	
	gotoxy(_X +2, _Y + 15);
	printf("Silakan tekan huruf Q untuk kembali ke home menu : ");
	gotoxy(_X +2, _Y + 16);
	printf("Atau tekan huruf apapun selain Q untuk kembali menggunakan kalkualtor akar kuadrat");
	gotoxy(_X - 2, _Y + 19);
	printf("========================================================================\n");
}

void gotoxy(int x, int y) {
    COORD coord;
     
    coord.X = x;
    coord.Y = y;
     
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void tampilCredit(){
	int _X = getScreenWidth() / 2 - 31;
	int _Y = getScreenHeight() / 2 - 9;

	system("cls");
	gotoxy(_X - 2, _Y);
	printf("========================================================================\n");
	gotoxy(_X + 30, _Y + 1);
 	printf("CREDIT\n");
 	gotoxy(_X - 2, _Y + 2);
 	printf("========================================================================\n");

 	gotoxy(_X + 30, _Y + 4);
 	printf("AUTHOR   \n\n");
 	gotoxy(_X + 22, _Y + 5);
 	printf("Danu Mahesa (211524037)\n");
 	gotoxy(_X + 21, _Y + 6);
 	printf("Husna Maulana (211524045)\n");
 	gotoxy(_X + 17, _Y + 7);
 	printf("Rachmat Purwa Saputra (211524054)\n\n");
 	gotoxy(_X + 28, _Y + 9);
 	printf("Kelas : 1B \n");
 	gotoxy(_X + 23, _Y + 11);
 	printf("D4 Teknik Informatika\n");
	gotoxy(_X + 31, _Y + 12);
	printf("2022");
 	gotoxy(_X - 2, _Y + 14);
 	printf("========================================================================\n");
 	getche();
}

void tampilHelp(){
	int _X = getScreenWidth() / 2 - 31;
	int _Y = getScreenHeight() / 2 - 9;

	FILE *help = NULL; 
	system("cls");
	gotoxy(_X + 19, _Y - 7);
	printf("======================\n");
	gotoxy(_X + 28, _Y - 6);
	printf("HELP \n");
	gotoxy(_X + 19, _Y - 5);
	printf("======================\n");
	char isiHelp[300];
	
	help = fopen("Help.txt", "r");
	if(help == NULL){
		printf("File Doesn't Exist");
		getche();
	}else {
		int i = 1;
		while(fscanf(help,"%[^\n]%*c", isiHelp) == 1){
			gotoxy(_X - 15, _Y - 2 + i);
			printf("%s\n",isiHelp);
			i++;
		}
		getche();
	}
	fclose(help);
	printf("\n");
	printf("\n\nInput Number 0 For Back to Main Menu : ");
}

void printBanner() {
	int i,j;
	int widthOfScreen = getScreenWidth();
	int heightOfScreen = getScreenHeight();

	int _X = widthOfScreen / 2 - 31;
	int _Y = heightOfScreen / 2 - 9;

	char banner_active[6][68] = {"==]  ==] =====] ==]  ==]==]   ==]======]  =====] ========] ======] ",
								 "==| ==[/==[__==]==| ==[/==|   ==|==[__==]==[__==]L__==[__/==[___==]",
								 "=====[/ =======|=====[/ ==|   ==|======[/=======|   ==|   ==|   ==|",
								 "==| ==] ==[__==|==[_==] ==|   ==|==[__==]==[__==|   ==|   ==|   ==|",
								 "==|  ==]==|  ==|==|  ==]L======[/==|  ==|==|  ==|   ==|   L======[/",
								 "L_/  L_/L_/  L_/L_/  L_/ L_____/ L_/  L_/L_/  L_/   L_/    L_____/ "
								};
	
	
	for (i = 0; i < 6; i++) {
		gotoxy(_X, _Y + 1 + i);
		for (j = 0; j < 68; j++) {
			printASCIIforBanner(banner_active[i][j]);
		}
		printf("\n");
	}
}

void printASCIIforBanner(char ch) {
	if (ch == '=') {
		printf("%c", 219);
	} else if (ch == '|') {
		printf("%c", 186);
	} else if (ch == ']') {
		printf("%c", 187);
	} else if (ch == '/') {
		printf("%c", 188);
	} else if (ch == '[') {
		printf("%c", 201);
	} else if (ch == 'L') {
		printf("%c", 200);
	} else if (ch == ' ') {
		printf("%c", 32);
	} else if (ch == '_') {
		printf("%c", 205);
	}
}

void printASCIIforHistTable(char ch) {
	if (ch == '=') {
		printf("%c", 196);
	} else if (ch == '[') {
		printf("%c", 218);
	} else if (ch == 'L') {
		printf("%c", 192);
	} else if (ch == 'T') {
		printf("%c", 194);
	} else if (ch == 'X') {
		printf("%c", 197);
	} else if (ch == '7') {
		printf("%c", 191);
	} else if (ch == '/') {
		printf("%c", 217);
	} else if (ch == '^') {
		printf("%c", 193);
	} else if (ch == '}') {
		printf("%c", 195);
	} else if (ch == '{') {
		printf("%c", 180);
	} else if (ch == '|') {
		printf("%c", 179);
	} else if (ch == ' ') {
		printf("%c", 32);
	}
}

