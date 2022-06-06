/**
 *  Program file name   : history.c
 *  Description         : Definisi file body dari header history.h
 *  Author              : Extended by : Rachmat Purwa Saputra, 211524054
 *  Compiler            : GCC
 *
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<sys/time.h>

#include "binaryTree.h"
#include "stack.h"
#include "tampilan.h"
#include "list.h"
#include "history.h"

void showHistory() {

	system("cls");

	createHistoryTable();

	int numOfRecords = 0, records = 0;
	int iter = 0;
	int addLines = 1;
	double resultFieldValue = 0;

	char str[128];
    int resultOfReadingFile;
    FILE* fh = fopen("calc_history.csv", "r");

	do {
		resultOfReadingFile = fscanf(fh, "%127[^,\n]", str);
		if(resultOfReadingFile != 0) {
			numOfRecords++;
			if (numOfRecords % 5 == 0) {
				records++;
			}
		} else {
			resultOfReadingFile = fscanf(fh, "%*c");
		}
	} while (resultOfReadingFile != EOF);

	memset(str, '\0', sizeof(char));

	rewind(fh);
	numOfRecords = 0;

	int rowOfRecordToShow = 0;

	do {
        resultOfReadingFile = fscanf(fh, "%127[^,\n]", str);

        if(resultOfReadingFile == 0)
        {
            resultOfReadingFile = fscanf(fh, "%*c");
        }
        else
        {
			if ((rowOfRecordToShow >= records - 20 && rowOfRecordToShow < records) || rowOfRecordToShow == 0) {
				iter++;
				if (iter == 1) {
					gotoxy(8, 3+addLines);
					printf("%s", str);
				} else if (iter == 2) {
					gotoxy(21, 3+addLines);
					printf("%s", str);
				} else if (iter == 3) {
					gotoxy(36, 3+addLines);
					printf("%s", str);
				} else if (iter == 4) {
					gotoxy(51, 3+addLines);
					printf("%s", str);
				} else if (iter == 5) {
					if (addLines > 1) {
						resultFieldValue = strtod(str, NULL);
						gotoxy(100, 3+addLines);
						printf("%.2f", resultFieldValue);
					} else {
						gotoxy(100, 3+addLines);
						printf("%s", str);
						addLines++;
					}
					addLines++;
					iter = 0;
				}
			}

			numOfRecords++;
			if(numOfRecords % 5 == 0) {
				rowOfRecordToShow++;
			}
        }

    } while(resultOfReadingFile != EOF);

	fclose(fh);
	getche();
}

void createHistoryTable() {
	char historyTable[24][122] = {"[=============T==============T=============T================================================T================7",
								  "|             |              |             |                                                |                |",
								  "}=============X==============X=============X================================================X================{",
								  "|             |              |             |                                                |                |",
								  "|             |              |             |                                                |                |",
								  "|             |              |             |                                                |                |",
								  "|             |              |             |                                                |                |",
								  "|             |              |             |                                                |                |",
								  "|             |              |             |                                                |                |",
								  "|             |              |             |                                                |                |",
								  "|             |              |             |                                                |                |",
								  "|             |              |             |                                                |                |",
								  "|             |              |             |                                                |                |",
								  "|             |              |             |                                                |                |",
								  "|             |              |             |                                                |                |",
								  "|             |              |             |                                                |                |",
								  "|             |              |             |                                                |                |",
								  "|             |              |             |                                                |                |",
								  "|             |              |             |                                                |                |",
								  "|             |              |             |                                                |                |",
								  "|             |              |             |                                                |                |",
								  "|             |              |             |                                                |                |",
								  "|             |              |             |                                                |                |",
								  "L=============^==============^=============^================================================^================/"
								 };
	
	int i = 0, j = 0;
	for (i = 0; i < 24; i++) {
		for (j = 0; j < 122; j++) {
			gotoxy(6 + j, 3 + i);
			printASCIIforHistTable(historyTable[i][j]);
		}
		printf("\n");
	}

	gotoxy(18, 29);
	printf("Menampilkan 20 entri histori teratas penggunaan kalkulator standar . . .");
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

    gotoxy(30, 5);
	printf("Successfully record previous data to the file!\n");  //pesan jika proses penulisan ke file berhasil
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