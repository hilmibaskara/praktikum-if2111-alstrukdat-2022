//NAMA  : Saul Sayers
//NIM   : 13520094 / 16520075
//KELAS : K02 Alstrukdat
//PRAKTIKUM 7

#include <stdio.h>
#include "prioqueue.c"

void sortnilai(PrioQueue *q) {
    int i, j;
    ElType temp;
    for (i = IDX_HEAD(*q); i < IDX_TAIL(*q); i++){
        for (j = IDX_HEAD(*q); j < IDX_TAIL(*q) - i; j++){
            if ((*q).buffer[j].score > (*q).buffer[j+1].score){
                temp = (*q).buffer[j];
                (*q).buffer[j] = (*q).buffer[j+1];
                (*q).buffer[j+1] = temp;
            }
        }
    }
}

void sortdatang(PrioQueue *q) {
    int i, j;
    ElType temp;
    for (i = IDX_HEAD(*q); i < IDX_TAIL(*q); i++){
        for (j = IDX_HEAD(*q); j < IDX_TAIL(*q) - i; j++){
            if ((*q).buffer[j].tArrival > (*q).buffer[j+1].tArrival){
                temp = (*q).buffer[j];
                (*q).buffer[j] = (*q).buffer[j+1];
                (*q).buffer[j+1] = temp;
            }
        }
    }
}



int main() {
    int t = 1,wait = 0;
    PrioQueue awal, now, tunggu;
    CreatePrioQueue(&awal);
    CreatePrioQueue(&now);
    CreatePrioQueue(&tunggu);
    ElType elemen ;
    int N,i,id,tarrival,score,dservice;
    scanf("%d", &N);
    for (i=0;i<N;i++) {
        scanf("%d", &id);
        elemen.id = id;
        scanf("%d", &tarrival);
        elemen.tArrival = tarrival;
        scanf("%d", &score);
        elemen.score = score;
        scanf("%d", &dservice);
        elemen.dService = dservice;
        enqueue(&awal, elemen);
    }
    sortdatang(&awal);
    while (!isEmpty(awal) || !isEmpty(now) || !isEmpty(tunggu)) {
        if (isEmpty(now) && HEAD(awal).tArrival == t && isEmpty(tunggu)) {
            enqueue(&now,HEAD(awal));
            dequeue(&awal,&elemen);
            printf("%d",t);
            printf(" %d", HEAD(now).id);
        }
        else if (isEmpty(now) && HEAD(tunggu).tArrival == t && !isEmpty(tunggu)) {
            enqueue(&now,HEAD(tunggu));
            dequeue(&tunggu,&elemen);
        }
        if (!isEmpty(now) && HEAD(awal).tArrival == t){
            enqueue(&tunggu, awal.buffer[i]);
            sortnilai(&tunggu);
        }
        else if ((!isEmpty(now) && HEAD(awal).tArrival != t)){
            HEAD(now).dService -= 1;
        }
        if (!isEmpty(tunggu)) {
            wait ++ ;
        }
        if (HEAD(now).dService == 0) {
            dequeue(&now,&elemen);
            printf(" %d\n", wait);
            wait = 0;
        }
        t++ ;
    }
    return 0;
}