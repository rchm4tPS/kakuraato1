/**
 * @file list.c
 * @author Husna Maulana
 * @brief implementasi header file list.h dengan alokasi dinamis untuk program kalkulator
 * 
 * Date     : 26 Mei 2022
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

address Alokasi(char* expression)
{
    address newItem = (address)malloc(sizeof(NodeList));
    if (newItem != Nil)
    {
      	strcpy(newItem->expression, expression);
        Next(newItem) = Nil;
    }
    return newItem;
}

void InsLast (List *L, char* expression) {
    address NodeLast = Alokasi(expression);      
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

    printf("\n");
}
