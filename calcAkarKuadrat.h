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

/**
 * Jenis : Procedure
 * Tujuan : Melakukan proses pada fitur kalkulator akar kuadrat.
 * Initial State : Fitur kalkulator akar kuadrat belum dimuat.
 * Final State : Fitur kalkulator akar kuadrat sudah dimuat.
 */
void initializeCalcAkarKuadrat();

/**
 * Jenis : Procedure
 * Tujuan : Melakukan proses pencarian nilai akar-akar riil dari persamaan kuadrat
 *          lalu menampilkan hasilnya ke layar.
 * Initial State : Perhitungan akar kuadrat belum dilakukan.
 * Final State : Perhitungan akar kuadrat dilakukan dan hasilnya ditampilkan ke layar.
 */
void calculateTwoRealRoots(int a, int b, int c);

/**
 * Jenis : Function
 * Tujuan : Melakukan pengecekan apakah suatu variabel itu sama (1 huruf) atau tidak dalam satu ekspresi akar kuadrat.
 */
bool isVariableUniform (char* quadraticEq);

/**
 * Jenis : Function
 * Tujuan : Melakukan pengecekan apakah suatu variabel itu karakter alphabet (A-Z, a-z) atau tidak dalam satu ekspresi akar kuadrat.
 */
bool isVariableAlphabet (char ch);

/**
 * Jenis : Function
 * Tujuan : Melakukan pengecekan apakah suatu ekspresi akar kuadrat berakhiran '=0' atau tidak.
 */
bool isEndedByEqualsZero (char* quadraticEq);


#endif