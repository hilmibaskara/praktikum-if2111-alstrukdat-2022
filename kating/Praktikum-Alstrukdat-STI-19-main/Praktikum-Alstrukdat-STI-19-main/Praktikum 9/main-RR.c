#include"RR.h"
#include"RR.c"
#include<stdlib.h>
#include<stdio.h>
int main(){
    Queue Q;
    infotype a,b,c;
    CreateEmpty(&Q);
    Add(&Q,5,4);
    Add(&Q,10,2);
    Add(&Q,15,3);
    PrintInfo(Q);
    int urut=Urutan(Q,0);
    printf("%d\n",urut);
    CheckPrio(Q);
    Del(&Q,&a);
    Del(&Q,&b);
    Del(&Q,&c);
    PrintInfo(Q);
    printf("%d\n",a);
    printf("%d\n",b);
    printf("%d\n",c);
    if (IsEmpty(Q)){
        printf("Kosong kak\n");
    }
    return 0;
}