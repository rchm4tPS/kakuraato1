/**
 *  Program file name   : list.c
 *  Description         : definisi dari header file list untuk struktur data linked list pada program Kakuraato.
 *  Author              : Husna Maulana, 211524045
 *  Compiler            : GCC
 *
 */

#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>


void CreateList(List *L)
{
    L->root = Nil;
}

address Alokasi(char* expression, double result, char* timeOfCalculation)
{
    address newItem = (address)malloc(sizeof(NodeList));
    if (newItem != Nil)
    {
      	strcpy(newItem->expression, expression);
        newItem->result = result;
        strcpy(newItem->timeEnteringExpression, timeOfCalculation);
        newItem->next = Nil;
    }
    return newItem;
}

void InsLast (List *L, char* expression, double result, char* timeOfCalculation) {
    address NodeLast = Alokasi(expression, result, timeOfCalculation);
    address tmp =L->root;        

    if (NodeLast != Nil)
    {
    	if(tmp != Nil){
		
	        while (tmp->next != Nil)
	        {
	            tmp = tmp->next;
	        }
	        tmp->next = NodeLast;
    	} else {
    		L->root = NodeLast;
		}
    }

}

void PrintInfo (List L) {
   address tmp = L.root;  

    if (L.root != Nil) {
        while (tmp != Nil)
        {
            printf("%s\n", tmp->expression);
            tmp = tmp->next;
        }
	}
}
