// NAMA      : Saul Sayers
// NIM       : 13520094
// Tanggal   : 11 November
// Topik     : Mqueue
// Deskripsi : Implementasi ADT Queue dengan representasi linked list dalam bahasa C

#include <stdio.h>
#include <stdlib.h>
#include "queue_linked.c"

int main() {
    int n, T_i ,i,buangan;
    scanf("%d",&n);
    Queue urutan;
    CreateQueue(&urutan);
    for (i=0; i < n; i++) {
        scanf("%d",&T_i);
        enqueue(&urutan, T_i);
        while (HEAD(urutan) + 300 < T_i) 
        {
            dequeue(&urutan,&buangan);
        }
        printf("%d\n", length(urutan));
    }
    return 0;
}