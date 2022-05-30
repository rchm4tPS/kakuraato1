#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>

#include "binaryTree.c"
#include "stack.c"
#include "tampilan.c"

int main() {
    system("cls");
    system("mode 145, 40");
	
    char infix[21];
    char postfix[21];
    char treeHistory[41] = "";
	char inputUser;
	char inputUserStd = 48;
	do{	
		system("cls");
		tampilMainMenu();
	    printf("\n");
		gotoxy(64,23);
	
		scanf(" %c",&inputUser);	
		if(inputUser == 49){
			do{	
				tampilKalkStandar();
				gotoxy(57,5);
				scanf(" %[^\n]%*c2", infix);
				infix_to_postfix(infix, postfix);
				addr treeRoot = BuildTreeFromPostfix(postfix);
				gotoxy(57,9);
				printf(" %.2f", TreeCalculate(treeRoot));
				getche();
				gotoxy(88,13);
				scanf(" %c", &inputUserStd);
			} while(inputUserStd != 81);
		}else if(inputUser == 50){
			tampilKalkAkur();
		}else if(inputUser == 51){
			tampilHelp();
		}else if(inputUser == 52){
			tampilHistory();	
		}else{
			exit(0);
		}
	}while(inputUser != 48);
    return 0;
}

  
