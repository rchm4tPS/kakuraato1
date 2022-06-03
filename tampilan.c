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
	gotoxy(65,9);
	printf("=====================================================================================\n");
	printBanner();
	printf("\n\n");
	gotoxy(65,23);
	printf("Pilihan Menu:\n");
	gotoxy(65,25);
	printf("1. Kalkulator Standar\n");
	gotoxy(65,26);
	printf("2. Kalkulator Akar Kuadrat\n");
	gotoxy(65,27);
	printf("3. Help\n");
	gotoxy(65,28);
	printf("4. History Penggunaan Kakuraato\n");
	gotoxy(65,29);
	printf("5. Credit\n");
	gotoxy(65,30);
	printf("\n");
	gotoxy(65,31);
	printf(" 0. Exit\n");
	gotoxy(65,32);
	printf("\n\n");
	gotoxy(65,33);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205, 205, 205 ,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205, 205, 205,187);
	gotoxy(65,34);
	printf("%c  Menu Yang Dipilih : [   ]  %c\n",186,186);
	gotoxy(65,35);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200, 205, 205, 205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205, 205, 205,188);
	gotoxy(65,36);
	printf("\n\n");
	gotoxy(65,37);
	printf("=====================================================================================\n");
}

void tampilKalkStandar(){
	system("cls");
	gotoxy(43,14);
	printf("\t\t\t\t========================================================================\n");
	gotoxy(43,18);
	printf("\t\t\t\t\t\t\tKALKULATOR STANDAR\n");
	gotoxy(43,19);
	printf("\n\n");
	gotoxy(43,20);
	printf("\t\t\t\t\tEkspresi\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
	gotoxy(43,21);
	printf("\t\t\t\t\tMatematika\t%c\t\t\t\t       %c\n",186,186);
	gotoxy(43,22);
	printf("\t\t\t\t\tYang Dihitung\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
	gotoxy(43,23);
	printf("\n");
	gotoxy(43,24);
	printf("\t\t\t\t\tHasil\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
	gotoxy(43,25);
	printf("\t\t\t\t\tPerhitungan\t%c\t\t\t\t       %c\n",186,186);
	gotoxy(43,26);
	printf("\t\t\t\t\tEkspresi\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
	gotoxy(43,27);
	printf("\n\n");
	gotoxy(43,28);
	printf("\t\t\t\t\tSilakan tekan huruf Q untuk kembali ke home menu : \n");
	gotoxy(43,32);
	printf("\t\t\t\t========================================================================\n");
}

void tampilKalkAkur(){
	system("cls");
	gotoxy(43,14);
	printf("\t\t\t\t========================================================================\n\n");
	gotoxy(43,15);
	printf("\t\t\t\t\tKALKULATOR AKAR KUADRAT\n");
	gotoxy(43,16);
	printf("t\t\t\t\t\t(bentuk umum x^2 + x + 1 = 0)");
	gotoxy(43,17);
	printf("\n\n");
	gotoxy(43,18);
	printf("\t\t\t\t\tEkspresi\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
	gotoxy(43,19);
	printf("\t\t\t\t\tMatematika\t%c\t\t\t\t       %c\n",186,186);
	gotoxy(43,20);
	printf("\t\t\t\t\tYang Dihitung\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
	gotoxy(43,21);
	printf("\n");
	gotoxy(43,22);
	printf("\t\t\t\t\tNilai\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
	gotoxy(43,23);
	printf("\t\t\t\t\tAkar\t\t%c\t\t\t\t       %c\n",186,186);
	gotoxy(43,24);
	printf("\t\t\t\t\tKe-1\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
	gotoxy(43,25);
	printf("\n");
	gotoxy(43,26);
	printf("\t\t\t\t\tNilai\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
	gotoxy(43,27);
	printf("\t\t\t\t\tAkar\t\t%c\t\t\t\t       %c\n",186,186);
	gotoxy(43,28);
	printf("\t\t\t\t\tke-2\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
	gotoxy(43,29);
	printf("\n\n");
	gotoxy(43,30);
	printf("\t\t\t\t\tSilakan tekan huruf Q untuk kembali ke home menu : ");
	gotoxy(43,31);
	printf("\n\n");
	gotoxy(43,32);
	printf("\t\t\t\t========================================================================\n");
}

void gotoxy(int x, int y) {
    COORD coord;
     
    coord.X = x;
    coord.Y = y;
     
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void tampilCredit(){
	system("cls");
	gotoxy(43,12);
	printf("\t\t\t\t========================================================================\n");
	gotoxy(43,13);
 	printf("\t\t\t\t\t\t\t\tCREDIT\n");
 	gotoxy(43,14);
 	printf("\t\t\t\t========================================================================\n");
 	gotoxy(43,15);
 	printf("\n");
 	gotoxy(43,16);
 	printf("\t\t\t\t\t\t\t\tAUTHOR   \n\n");
 	gotoxy(43,17);
 	printf("\t\t\t\t\t\t       Danu Mahesa (211524037)\n");
 	gotoxy(43,18);
 	printf("\t\t\t\t\t\t      Husna Maulana (211524045)\n");
 	gotoxy(43,19);
 	printf("\t\t\t\t\t\t    Rachmat Purwa Saputra (211524054)\n\n");
 	gotoxy(43,20);
 	printf("\t\t\t\t\t        	      Kelas : 1B \n");
 	gotoxy(43,21);
 	printf("\t\t\t\t\t\t         D4 Teknik Informatika\n");
 	gotoxy(43,22);
 	printf("\t\t\t\t\t\t    \n");
 	gotoxy(43,23);
 	printf("\t\t\t\t\t\t    \n");
 	gotoxy(43,24);
 	printf("\n");
 	gotoxy(43,25);
 	printf("\n\n");
 	gotoxy(43,26);
 	printf("\t\t\t\t========================================================================\n");
 	getche();
}

void tampilHelp(){
	FILE *help = NULL; 
	system("cls");
	gotoxy(50,4);
	printf("\t\t\t\t ======================\n");
	gotoxy(50,5);
	printf("\t\t\t\t          HELP \n");
	gotoxy(50,6);
	printf("\t\t\t\t ======================\n");
	char isiHelp[300];
	
	help = fopen("Help.txt", "r");
	if(help == NULL){
		printf("File Doesn't Exist");
		getche();
	}else {
		int i = 1;
		while(fscanf(help,"%[^\n]%*c", isiHelp) == 1){
			gotoxy(50,8+i);
			printf("%s\n",isiHelp);
			i++;
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
		gotoxy(74, 15+i);
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

