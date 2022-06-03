/**
 *  Program file name   : calcAkarKuadrat.c
 *  Description         : definisi dari header file untuk struktur data binary tree pada program kalkulator
 *  Author              : Rachmat Purwa Saputra, 211524054
 *  Compiler            : GCC
 *
 */

#include "calcAkarKuadrat.h"
#include "tampilan.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


void initializeCalcAkarKuadrat() {
    int i;
    char quadraticEquation[24];
    char* end;
    char delimiterEquals = '.', userInputAkur = '.';
    char numTemp[4] = {'\0', '\0', '\0', '\0'};
    double a, b, c;
    int t, j, cvrt;

    do {
        fflush(stdin);
        a = b = c = 0;
        t = 0; j = -1;
        cvrt = 0;
        system("cls");
        end = NULL; delimiterEquals = '.';
        memset(quadraticEquation, '\0', 24*sizeof(char));

        tampilKalkAkur();

        gotoxy(98,19);
        scanf(" %[^\n]%*c", quadraticEquation);
        // printf(" \n %s\n", quadraticEquation);

        
        if (isEndedByEqualsZero(quadraticEquation) && isVariableUniform (quadraticEquation)) {
            for (i = 0; i < strlen(quadraticEquation) && delimiterEquals != '='; i++) {
                if (quadraticEquation[i] == ' ') continue;

                if (!isdigit(quadraticEquation[i]) && isVariableAlphabet(quadraticEquation[i])) {
                    if (i >= 1) {
                        if (!isdigit(quadraticEquation[i - 1])) {
                            t++;
                            if (t == 2) b = 1;
                        }
                    } else if (i == 0) {
                        t++;
                        if (t == 1) a = 1;
                    }
                }

                // melihat tanda sebelumnya, apakah negatif atau bukan
                if (quadraticEquation[i] == '-') {
                    t++; i++;
                    j = 0;

                    do {
                        numTemp[j++] = quadraticEquation[i++];
                    } while (isdigit(quadraticEquation[i]));

                    cvrt = strtod(&numTemp[0], &end) * -1;

                    if (t == 1) {
                        if (cvrt == 0) a = -1;
                        else a = cvrt;
                    } else if (t == 2) {
                        b = cvrt;
                    } else if (t == 3) {
                        c = cvrt;
                    }

                    memset(numTemp, '\0', 4*sizeof(char));
                } else {
                    if (i == 0 && isdigit(quadraticEquation[0])) {
                        j = 0;

                        do {
                            numTemp[j++] = quadraticEquation[i++];
                        } while (isdigit(quadraticEquation[i]));

                        a = strtod(&numTemp[0], &end);
                        
                        t++;
                        
                        memset(numTemp, '\0', 4*sizeof(char));
                    }
                }

                if (isdigit(quadraticEquation[i]) && (i >= 1 && i <= strlen(quadraticEquation) - 1) && 
                    (quadraticEquation[i - 1] != '^' && (quadraticEquation[i - 1] == ' ' ))
                )
                {
                    j = 0;
                    t++;
                    
                    do {
                        numTemp[j++] = quadraticEquation[i++];
                    } while (isdigit(quadraticEquation[i]));

                    i--;
                    numTemp[j] = '\0';

                    cvrt = strtod(&numTemp[0], &end);

                    if (t == 2) b = cvrt;
                    else if (t == 3) c = cvrt;

                    memset(numTemp, '\0', 4*sizeof(char));
                }

                delimiterEquals = quadraticEquation[i+1];

            }

            calculateTwoRealRoots(a, b, c);
        } else {
            gotoxy(98,21);
            printf("Persamaan Kuadrat tidak valid! Harus sama variabelnya dan berakhiran '= 0'\n");
        }
        
        // a, b, dan c yang didapat merupakan koefisien (dan c sbg konstanta) utk persamaan kuadrat
        // printf(" \n%.2f %.2f %.2f\n", a, b, c);

        gotoxy(131,30);
		scanf(" %c", &userInputAkur);
    } while (userInputAkur != 81);
}

void calculateTwoRealRoots(int a, int b, int c) {
    double Discriminant = pow(b, 2) - (4*a*c);
    double akar1, akar2;

    if (Discriminant < 0) {
        gotoxy(98,21);
        printf("PERHATIAN! Akar-akar tidak real / imajiner\n");
    } else {
        akar1 = ((b * -1) + sqrt(Discriminant))/(2*a);
        akar2 = ((b * -1) - sqrt(Discriminant))/(2*a);

        gotoxy(98,23);
        printf("%.2f", akar1);
        gotoxy(98,27);
        printf("%.2f", akar2);
    }
}

bool isVariableUniform (char* quadraticEq) {
    int idx = 0;
    char quadVar[3] = {'.', '.', '.'};
	int i;
    for (i = 0; i < strlen(quadraticEq) - 1; i++) {
        if (quadraticEq[i] >= 97 && quadraticEq[i] <= 122) {
            quadVar[idx] = quadraticEq[i];
            if (idx >= 1) {
                if (quadVar[idx - 1] == quadVar[idx]) {
                    continue;
                } else {
                    return false;
                }
            }
            idx++;
        }
    }

    return true;
}

bool isVariableAlphabet (char ch) {
    return (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122);
}

bool isEndedByEqualsZero (char* quadraticEq) {
    return (quadraticEq[strlen(quadraticEq) - 1] == '0');
}
