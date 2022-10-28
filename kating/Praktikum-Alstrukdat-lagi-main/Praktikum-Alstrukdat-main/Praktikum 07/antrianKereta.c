//NAMA  : Saul Sayers
//NIM   : 13520094 / 16520075
//KELAS : K02 Alstrukdat
//PRAPRAKTIKUM 7

#include <stdio.h>
#include "queue.h"

int main() {
    Queue antrian;
    CreateQueue(&antrian);
    int op,i;
    int val_enq, val_deq,total=0;
    boolean sudah = false ;
    while (!sudah) {
        scanf("%d", &op);
        if (op == 1) {
            scanf(" %d", &val_enq);
            if (isFull(antrian)){
                printf("Queue penuh\n");
            }
            else{
                enqueue(&antrian,val_enq);
            }
        }
        else if (op==2){
            if (isEmpty(antrian)){
                printf("Queue kosong\n");
            }
            else {
                dequeue(&antrian,&val_deq);
            }
        }
        else if (op==0) {
            sudah = true;
            printf("%d\n", length(antrian));
        }
    }
    if (isEmpty(antrian)) {
        printf("Tidak bisa dihitung\n");
    }
    else {
        for (i=IDX_HEAD(antrian);i<length(antrian)+IDX_HEAD(antrian);i++) {
            total += antrian.buffer[i];
        }
        printf("%.2f\n", (float) total/length(antrian));
    }
    return 0;
}