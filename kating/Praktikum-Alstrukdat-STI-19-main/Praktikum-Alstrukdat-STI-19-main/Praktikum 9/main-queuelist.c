#include<stdio.h>
#include<stdlib.h>
#include"queuelist.h"
#include"queuelist.c"
int main(){
    Queue Q;
    int hasil,delete;
    CreateEmpty(&Q);
    Add(&Q,5);
    Add(&Q,10);
    Add(&Q,15);
    Del(&Q,&delete);
    if (IsEmpty(Q)){
        printf("Kosong mas\n");
    }
    PrintInfo(Q);
    hasil=NbElmt(Q);
    printf("%d\n",hasil);
    printf("%d\n",delete);
    return 0;
}