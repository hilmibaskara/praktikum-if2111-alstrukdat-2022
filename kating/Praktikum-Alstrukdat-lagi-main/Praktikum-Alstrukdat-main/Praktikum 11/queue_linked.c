// NAMA      : Saul Sayers
// NIM       : 13520094
// Tanggal   : 24 Oktober 2021
// Topik     : ADT Queue dengan representasi linked list
// Deskripsi : Implementasi ADT Queue dengan representasi linked list dalam bahasa C

#include <stdio.h>
#include <stdlib.h>
#include "queue_linked.h"

Address newNode(ElType x) 
{
    Address p = (Address) malloc(sizeof(Node));
    if (p!=NULL) {
        INFO(p) = x;
        NEXT(p) = NULL;
    }
    return p;
}

boolean isEmpty(Queue q)
{
    return (ADDR_HEAD(q) == NULL && ADDR_TAIL(q) == NULL);
}

int length(Queue q)
{
    int banyak = 0;
    Address sekarang = ADDR_HEAD(q);
    while (sekarang != NULL) 
    {
        banyak += 1;
        sekarang = NEXT(sekarang);
    }
    return banyak;
}

void CreateQueue(Queue *q)
{
    ADDR_HEAD(*q) = NULL;
    ADDR_TAIL(*q) = NULL;
}

void enqueue(Queue *q, ElType x)
{
    Address baru;
    baru = newNode(x);
    if (baru != NULL)
    {
        if (!isEmpty(*q)) 
        {
            NEXT(ADDR_TAIL(*q)) = baru;
        }
        else
        {
            ADDR_HEAD(*q) = baru;
        }
        ADDR_TAIL(*q) = baru;
    }
}

void dequeue(Queue *q, ElType *x)
{
    Address buangan = ADDR_HEAD(*q);
    *x = HEAD(*q);
    ADDR_HEAD(*q) = NEXT(ADDR_HEAD(*q)) ;
    if (ADDR_HEAD(*q) == NULL) 
    {
        ADDR_TAIL(*q) = NULL;
    }
    NEXT(buangan) = NULL;
    free(buangan);
}