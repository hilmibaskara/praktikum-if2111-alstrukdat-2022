// NAMA      : Saul Sayers
// NIM       : 13520094
// Tanggal   : 4 November 2021
// Topik     : ADT Linked List Circular
// Deskripsi : Round Robin program

#include <stdio.h>
#include <stdlib.h>
#include "list_circular.c"


float average(List l)
{
    float total=0,banyak = 0, ratarata;
    Address sekarang;
    if (!isEmpty(l)) 
    {
        sekarang = FIRST(l);
        while (NEXT(sekarang) != FIRST(l)) 
        {
            banyak += 1;
            total += INFO(sekarang);
            sekarang = NEXT(sekarang);
        } 
        banyak += 1;
        total += INFO(sekarang);
    }
    if (banyak==0)
    {
        ratarata = 0;
    }
    else 
    {
        ratarata = total/banyak;
    }
    return ratarata;
}

void deleteRR (List *l, ElType tQ)
{
    Address sekarang = FIRST(*l);
    ElType buangan;
    if (isEmpty(*l)) 
    {
        printf("List kosong\n") ;
    }
    else 
    {
        while (NEXT(sekarang) != FIRST(*l)) 
        {
            sekarang = NEXT(sekarang);
        } //disini udah sampe ke yang terakhir
        if (INFO(sekarang) <= tQ )
        {
            printf("%d\n",INFO(sekarang));
            deleteLast(l,&buangan);
        }
        else
        {
            INFO(sekarang) = INFO(sekarang) - tQ;
            printf("%d\n",tQ);
            deleteLast(l,&buangan);
            insertFirst(l,buangan);
        }
    }
}

int main() 
{
    List l;
    CreateList(&l);
    int selesai = 0;
    ElType tQ, baru ;
    char huruf ;
    scanf("%d", &tQ);
    do 
    {
        scanf("%d", &tQ);
    } while (tQ<=0);

    while (!selesai) 
    {
        scanf(" %c", &huruf);
        if (huruf =='F') 
        {
            if (!isEmpty(l)) 
            {
                printf("%0.2f\n", average(l));
            }
            else 
            {
                printf("Proses selesai\n");
            }
            selesai = 1;
        }
        else if (huruf =='D')
        {
            deleteRR(&l,tQ) ;
        }
        else if (huruf =='A')
        {
            scanf("%d", &baru);
            if(baru > 0) {
                insertFirst(&l,baru);
            }
        }
        else
        {
            printf("Kode salah\n");
        }
    }
    return 0;
}