/**
 *  Program file name   : calcStandar.h
 *  Description         : Definisi body dari header file untuk proses yang berkaitan dengan fitur kalkulator standar
 *  Author              : Rachmat Purwa Saputra, 211524054
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
#include "calcStandar.h"

void initiateStandardCalc() {
	char infix[40];
    char postfix[40];
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