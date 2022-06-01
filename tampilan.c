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

void tampilMainMenu(){
	printf("\n\n\t\t\t\t===========================================================================\n");
	printBanner();
	printf("\n\n");
	printf("\t\t\t\t\tPilihan Menu:\n");
	printf("\t\t\t\t\t1. Kalkulator Standar\n");
	printf("\t\t\t\t\t2. Kalkulator Akar Kuadrat\n");
	printf("\t\t\t\t\t3. Help\n");
	printf("\t\t\t\t\t4. History Penggunaan Kakuraato\n");
	printf("\n");
	printf("\t\t\t\t\t0. Exit\n");
	printf("\n\n");
	printf("\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205, 205, 205,187);
	printf("\t\t\t\t\t%c  Menu Yang Dipilih : [ ]  %c\n",186,186);
	printf("\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205, 205, 205,188);
	printf("\n\n");
	printf("\t\t\t\t===========================================================================\n");
}

void tampilKalkStandar(){
	system("cls");
	printf("\t\t\t\t========================================================================\n");
	printf("\t\t\t\t\tKalkulator Standar\n");
	printf("\n\n");
	printf("\t\t\t\t\tEkspresi\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
	printf("\t\t\t\t\tMatematika\t%c\t\t\t\t       %c\n",186,186);
	printf("\t\t\t\t\tYang Dihitung\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
	printf("\n");
	printf("\t\t\t\t\tHasil\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
	printf("\t\t\t\t\tPerhitungan\t%c\t\t\t\t       %c\n",186,186);
	printf("\t\t\t\t\tEkspresi\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
	printf("\n\n");
	printf("\t\t\t\t\tSilakan tekan angka Q untuk kembali ke home menu : \n");
	printf("\t\t\t\t========================================================================\n");
}

void tampilKalkAkur(){
	system("cls");
	printf("\t\t\t\t========================================================================\n");
	printf("\t\t\t\t\tKalkulator Akar Kuadrat\n");
	printf("t\t\t\t\t\t(bentuk umum x^2 + x + 1 = 0)");
	printf("\n\n");
	printf("\t\t\t\t\tEkspresi\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
	printf("\t\t\t\t\tMatematika\t%c\t\t\t\t       %c\n",186,186);
	printf("\t\t\t\t\tYang Dihitung\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
	printf("\n");
	printf("\t\t\t\t\tNilai\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
	printf("\t\t\t\t\tAkar\t\t%c\t\t\t\t       %c\n",186,186);
	printf("\t\t\t\t\tKe-1\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
	printf("\n");
	printf("\t\t\t\t\tNilai\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
	printf("\t\t\t\t\tAkar\t\t%c\t\t\t\t       %c\n",186,186);
	printf("\t\t\t\t\tke-2\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
	printf("\n\n");
	printf("\t\t\t\t\tSilakan tekan huruf Q untuk kembali ke home menu : ");
	printf("\n\n");
	printf("\t\t\t\t========================================================================\n");
}

void gotoxy(int x, int y) {
    COORD coord;
     
    coord.X = x;
    coord.Y = y;
     
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void tampilCredit(){
	printf("\t\t\t\t========================================================================\n");
 	printf("\t\t\t\t\t\t\t\tCREDIT\n");
 	printf("\t\t\t\t========================================================================\n");
 	printf("\n");
 	printf("\t\t\t\t\t\t\t\tAUTHOR   \n\n");
 	printf("\t\t\t\t\t\t       Danu Mahesa (211524037)\n");
 	printf("\t\t\t\t\t\t      Husna Maulana (211524045)\n");
 	printf("\t\t\t\t\t\t    Rachmat Purwa Saputra (211524054)\n\n");
 	printf("\t\t\t\t\t\t 			 Kelas : 1B \n");
 	printf("\t\t\t\t\t\t    D4 Teknik Informatika\n");
 	printf("\t\t\t\t\t\t    \n");
 	printf("\t\t\t\t\t\t    \n");
 	printf("\n");
	printf("\t\t\t\t\t     Silakan tekan angka 0 untuk kembali ke home menu : ");
 	printf("\n\n");
 	printf("\t\t\t\t========================================================================\n");
}

void tampilHelp(){
	FILE *help = NULL; 
	system("cls");
	printf("\t\t\t\t -------------\n");
	printf("\t\t\t\t    | HELP |\n");
	printf("\t\t\t\t -------------\n");
	char isiHelp[300];
	
	help = fopen("Help.txt", "r");
	if(help == NULL){
		printf("File Doesn't Exist");
		getche();
	}else {
		while(fscanf(help,"%[^\n]%*c", isiHelp) == 1){
			printf("%s\n",isiHelp);
		}
		getche();
	}
	fclose(help);
	printf("\n");
	printf("\n\nInput Number 0 For Back to Main Menu : ");
}

void tampilHistory(){
	system("cls");
	char historyTabel[6][42]= { "[===============T===============]",
								"|               |               |",
								"{===============X===============}",
								"|               |               |",
								"L===============W===============/" 
							  };
	int i, j;
	char ch;
	i = j = 0;
	
	for (i = 0; i < 6; i++) {
		for (j = 0; j < 42; j++) {
			ch = historyTabel[i][j];
			if (ch == '[') {
				printf("%c", 218);
			} else if (ch == '=') {
				printf("%c", 196);
			} else if (ch == 'T') {
				printf("%c", 194);
			} else if (ch == ']') {
				printf("%c", 191);
			} else if (ch == '|') {
				printf("%c", 179);
			} else if (ch == '{') {
				printf("%c", 195);
			} else if (ch == '}') {
				printf("%c", 180);
			} else if (ch == 'X') {
				printf("%c", 197);
			} else if (ch == 'L') {
				printf("%c", 192);
			} else if (ch == 'W') {
				printf("%c", 193);
			} else if (ch == '/') {
				printf("%c", 217);
			} else if (ch == ' ') {
				printf("%c", 32);
			}
		}
		printf("\n");
	}
	getche();
}

void printBanner() {
	int i,j;
	char banner_active[6][68] = {"==]  ==] =====] ==]  ==]==]   ==]======]  =====] ========] ======] ",
								 "==| ==[/==[__==]==| ==[/==|   ==|==[__==]==[__==]L__==[__/==[___==]",
								 "=====[/ =======|=====[/ ==|   ==|======[/=======|   ==|   ==|   ==|",
								 "==| ==] ==[__==|==[_==] ==|   ==|==[__==]==[__==|   ==|   ==|   ==|",
								 "==|  ==]==|  ==|==|  ==]L======[/==|  ==|==|  ==|   ==|   L======[/",
								 "L_/  L_/L_/  L_/L_/  L_/ L_____/ L_/  L_/L_/  L_/   L_/    L_____/ "
								};
	
	for (i = 0; i < 6; i++) {
		gotoxy(36, 5+i);
		for (j = 0; j < 68; j++) {
			printASCII(banner_active[i][j]);
		}
		printf("\n");
	}
}

void printASCII(char ch) {
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

