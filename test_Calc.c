/**
 *  Program file name   : testCalc.c
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

void beginApplication();
void initiateStandardCalc();
void writeHistory(List _history);
void userTimeHistory(char* arrayOfTime);

int main() {
	// Inisialisasi jendela cmd agar bersih dan berukuran 145 x 40
    system("cls");
    // Make the console windows become full-size
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	
	beginApplication();

    return 0;
}

void beginApplication() {
	char inputUser;

	// Lakukan selama user belum memilih untuk keluar dari aplikasi
	do{	
		system("cls");
		tampilMainMenu();
	    printf("\n");

		gotoxy(64,23);
		scanf(" %c",&inputUser);	

		if (inputUser == 48) {
			break;
		}
		else if (inputUser == 49){
			// proses kalkulator standar dimulai
			initiateStandardCalc();
		}
		else if (inputUser == 50) {
			tampilKalkAkur();
		}
		else if (inputUser == 51) {
			tampilHelp();
		}
		else if (inputUser == 52) {
			tampilHistory();	
		}
		else {
			printf("\nHarap masukkan angka 0, 1, 2, 3, atau 4 saja!\n");
			getche();
		}
	} while (inputUser != 48);  // selama bukan digit 0 yang dipilih user
}

void initiateStandardCalc() {
	char infix[21];
    char postfix[21];
	char timeCalculation[64];
	int checkPostfix = 0;
	char inputUserStd = 48;

	List exprHistory;
	CreateList(&exprHistory);

	do{	
		tampilKalkStandar();

		gotoxy(57,5);
		scanf(" %[^\n]%*c", infix);

		checkPostfix = infix_to_postfix(infix, postfix);

		if (checkPostfix == -1) {
			printf("Ekspresi tidak valid");
		}

		addr treeRoot = createTreeFromPostfix(postfix);

		gotoxy(57,9);
		double result = calculateTreeExpression(treeRoot);
		printf(" %.2f", result);
		getche();

		userTimeHistory(timeCalculation);
		InsLast(&exprHistory, infix, result, timeCalculation);

		gotoxy(91,13);
		scanf(" %c", &inputUserStd);
	} while (inputUserStd != 81);  // selama user tidak menekan karakter 'Q' dari keyboard

	system("cls");
	writeHistory(exprHistory);
	
}

void writeHistory(List _history) {
	FILE *fhist = fopen("calc_history.csv", "a");  // mode append kepada file csv

	if (fhist != NULL) {
		address nodeList = _history.root;

		while (nodeList != NULL) {
			// delimiter file csv adalah koma (',').
			fprintf(fhist, "%s,%s,%.2f\n", nodeList->timeEnteringExpression, nodeList->expression, nodeList->result);
			nodeList = nodeList->next;
		}
	} else {
		exit(EXIT_FAILURE);
	}

	fclose(fhist);
	printf("\nSuccessfully recorded data to the file!\n");  //pesan jika proses penulisan ke file berhasil
	getche();
}

void userTimeHistory(char* arrayOfTime) {
	// Disadur dari : https://linuxhint.com/gettimeofday_c_language/
	// pada tanggal 1 Juni 2022

	struct timeval tv;
	time_t t;
	struct tm *info;
	char buffer[64];

	gettimeofday(&tv, NULL);
    t = tv.tv_sec;

    info = localtime(&t);
    strftime(buffer, sizeof buffer, "%A, %d %b %Y, %H:%M:%S", info); //format : Hari, tanggal bulan tahun, Jam, menit, detik

	strcpy(arrayOfTime, buffer);
}