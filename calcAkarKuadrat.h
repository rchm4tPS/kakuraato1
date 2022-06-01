/**
 *  Program file name   : calcAkarKuadrat.h
 *  Description         : deklarasi prototipe / header file untuk program kalkulator akar kuadrat
 *  Author              : Rachmat Purwa Saputra, 211524054
 *  Compiler            : GCC
 *
 */

#ifndef calcAkarKuadrat_H
#define calcAkarKuadrat_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void initializeCalcAkarKuadrat();

void calculateTwoRealRoots(int a, int b, int c);

bool isVariableUniform (char* quadraticEq);

bool isVariableAlphabet (char ch);

bool isEndedByEqualsZero (char* quadraticEq);


#endif