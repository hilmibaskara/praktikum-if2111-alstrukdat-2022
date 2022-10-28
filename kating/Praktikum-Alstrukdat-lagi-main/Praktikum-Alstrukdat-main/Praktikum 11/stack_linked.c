// NAMA      : Saul Sayers
// NIM       : 13520094
// Tanggal   : 4 November 2021
// Topik     : ADT Stack dengan representasi linked list
// Deskripsi : Implementasi ADT Stack dengan representasi linked list dalam bahasa C

#include <stdio.h>
#include <stdlib.h>
#include "stack_linked.h"

Address newNode(ElType x) 
{
    Address p = (Address) malloc(sizeof(Node));
    if (p!=NULL) {
        INFO(p) = x;
        NEXT(p) = NULL;
    }
    return p;
}

boolean isEmpty(Stack s)
{
    return ADDR_TOP(s) == NULL;
}

void CreateStack(Stack *s)
{
    ADDR_TOP(*s) = NULL;
}

void push(Stack *s, ElType x)
{
    Address baru = newNode(x);
    if (baru != NULL) 
    {
        NEXT(baru) = ADDR_TOP(*s);
        ADDR_TOP(*s) = baru;
    }
}

void pop(Stack *s, ElType *x)
{
    Address buangan = ADDR_TOP(*s);
    *x = TOP(*s);
    ADDR_TOP(*s) = NEXT(ADDR_TOP(*s));
    NEXT(buangan) = NULL;
    free(buangan);
}