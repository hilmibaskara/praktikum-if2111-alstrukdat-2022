// NAMA      : Saul Sayers
// NIM       : 13520094
// Tanggal   : 11 November
// Topik     : Backspace
// Deskripsi : Implementasi ADT Stack dengan representasi linked list dalam bahasa C

#include <stdio.h>
#include <stdlib.h>
#include "stack_linked.c"

int main() 
{
    int N, M, i, angka, sama = 1;
    scanf("%d %d", &N, &M);
    Stack sA, sB;
    CreateStack(&sA);
    CreateStack(&sB);
    for (i=0; i < N ; i++) 
    {
        scanf("%d", &angka);
        if (angka != 0) 
        {
            push(&sA, angka);
        }
        if (angka == 0 && !isEmpty(sA))
        {
            pop(&sA, &angka);
        }
    }
    for (i=0; i < M ; i++) 
    {
        scanf("%d", &angka);
        if (angka != 0) 
        {
            push(&sB, angka);
        }
        if (angka == 0 && !isEmpty(sB))
        {
            pop(&sB, &angka);
        }
    }
    while (!isEmpty(sA)) {
        printf("%d", TOP(sA));
        pop(&sA, &angka);
    }
    /*while (!isEmpty(sA) && !isEmpty(sB) && sama)
    {
        if (TOP(sA) == TOP(sB))
        {
            pop(&sA, &angka);
            pop(&sB, &angka);
        }
        else 
        {
            sama = 0;
        }
    }
    if (!isEmpty(sA) || !isEmpty(sB)) 
    {
        sama = 0;
    }
    if (sama) 
    {
        printf("Sama\n");
    }
    else 
    {
        printf("Tidak sama\n");
    }*/
    return 0;
}