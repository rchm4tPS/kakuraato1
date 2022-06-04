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

void beginApplication();
void initiateStandardCalc();
void writeHistory(List _history);
void userTimeHistory(char* arrayOfTime);

int main() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 229); // asalnya 125, lalu 229 - alternatifnya 245. Ada lagi 252 (merah) atau 249 (biru cerah).
	// Inisialisasi jendela cmd agar bersih
    system("cls");
    // Make the console windows become full-size
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	
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
			tampilHelp();
		}
		else if (inputUser == 52) {
			tampilHistory();	
		}else if (inputUser == 53) {
			tampilCredit();	
	    }
		else {
			gotoxy(_X + 25, _Y + 20);
			printf("Harap masukkan angka 0, 1, 2, 3, 4, atau 5 saja!");
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

	int _X = getScreenWidth() / 2 - 31;
	int _Y = getScreenHeight() / 2 - 9;

	List exprHistory;
	CreateList(&exprHistory);

	do{	
		tampilKalkStandar();

		gotoxy(_X + 22, _Y + 7);
		
		scanf(" %[^\n]%*c", infix);
		
		checkPostfix = infix_to_postfix(infix, postfix);

		if (checkPostfix == -1) {
			printf("Ekspresi tidak valid");
		}

		addr treeRoot = createTreeFromPostfix(postfix);
		double result = calculateTreeExpression(treeRoot);
		gotoxy(_X + 21, _Y + 11);
		printf(" %.2f", result);

		userTimeHistory(timeCalculation);
		InsLast(&exprHistory, infix, result, timeCalculation);

		gotoxy(_X + 53, _Y + 15);
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
