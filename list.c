#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


void CreateList(List *L)
{
    First(*L) = Nil;
}

address Alokasi(infotype X)
{
    address newItem = (address)malloc(sizeof(NodeList));
    if (newItem != Nil)
    {
        Info(newItem) = X;
        Next(newItem) = Nil;
    }
    return P;
}

void DeAlokasi (address P) 
{
    free(P);
}

void InsFirst (List *L, infotype X) {
    address Node1 = Alokasi(X); 

    if (Node1 != Nil)
    {
        if (First(*L) != Nil)
        {
            Node1->next = First(*L);
            First(*L) = Node1;
        } else {
            First(*L) = Node1;
        }
    }
}

void InsLast (List *L, infotype X) {
    address NodeLast = Alokasi(X);      
    address tmp = First(*L);        

    if (NodeLast != Nil)
    {
        while (tmp->next != Nil)
        {
            tmp = tmp->next;
        }
        tmp->next = NodeLast;
    }
}

void PrintInfo (List L) {
    address tmp = First(L);

    if (ListEmpty(L) == false || NbElmt(L) != 0) {
        while (tmp != Nil)
        {
            printf("%d ", tmp->info);
            tmp = tmp->next;
        }
    } else {
        printf("list kosong");
    }

    printf("\n");
}
