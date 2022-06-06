/**
 *  Program file name   : history.h
 *  Description         : Definisi header file untuk proses yang berkaitan dengan fitur history
 *  Author              : Rachmat Purwa Saputra, 211524054
 *  Compiler            : GCC
 *
 */

#ifndef history_H
#define history_H

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

void showHistory();

void createHistoryTable();

void writeHistory(List _history);

void userTimeHistory(char* arrayOfTime);

#endif