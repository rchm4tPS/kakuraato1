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

#include "binaryTree.c"
#include "stack.c"
#include "tampilan.c"

int main() {
	// Inisialisasi jendela cmd agar bersih dan berukuran 145 x 40
    system("cls");
    // Make the console windows become full-size
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	
    char infix[21];
    char postfix[21];

	char inputUser;
	char inputUserStd = 48;

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
			do{	
				tampilKalkStandar();

				gotoxy(57,5);
				scanf(" %[^\n]%*c", infix);

				infix_to_postfix(infix, postfix);

				addr treeRoot = createTreeFromPostfix(postfix);

				// gotoxy(57, 15);
				// printTree(treeRoot);

				gotoxy(57,9);
				printf(" %.2f", calculateTreeExpression(treeRoot));
				getche();

				gotoxy(91,13);
				scanf(" %c", &inputUserStd);
			} while (inputUserStd != 81);  // selama user tidak menekan karakter 'Q' dari keyboard
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

    return 0;
}

  
