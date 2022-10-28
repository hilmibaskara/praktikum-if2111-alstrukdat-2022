// NAMA      : Saul Sayers
// NIM       : 13520094
// Tanggal   : 24 Oktober 2021
// Topik     : ADT Linked List
// Deskripsi : cache.c

#include <stdio.h>
#include "list_linked.h"
//#include "node.c"

int main() {
    List L ;
    ElType val;
    Address sekarang;
    CreateList(&L);
    boolean ketemu;
    int N, Q,x, i,j,indeks;
    scanf("%d", &N);
    scanf("%d", &Q);
    for (i=1 ; i <= N ; i++) {
        insertLast(&L, i) ;
    }
    for (j=0;j<Q;j++) {
        scanf("%d", &x);
        ketemu = false ; //proses pencarian x dalam list
        sekarang = L;
        indeks = 0;
        while (sekarang != NULL && !ketemu) {
            if(INFO(sekarang) == x) {
                ketemu = true;
            }
            else{
                sekarang = NEXT(sekarang);
                indeks++ ;
            }
        }
        if (ketemu == true) {
            deleteAt(&L, indeks, &val);
            insertFirst(&L, x) ;
            printf("hit ");
            displayList(L);
            printf("\n");
        }
        else {
            deleteLast(&L, &val) ;
            insertFirst(&L, x);
            printf("miss ");
            displayList(L);
            printf("\n");
        }
    }
    return 0;
}