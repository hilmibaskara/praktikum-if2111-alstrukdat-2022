#include<stdio.h>
#include<stdlib.h>
#include"listsirkuler.h"
#include"listsirkuler.c"
int main(){
    List L;
    address q=Alokasi(123);
    CreateEmpty(&L);
    if (IsEmpty(L)){
        printf("Halo\n");
    }
    InsVFirst(&L,5);
    InsVLast(&L,10);
    InsVFirst(&L,0);
    InsVLast(&L,999);
    address p=Search(L,999),z=Search(L,5);
    InsertAfter(&L,q,z);
    PrintInfo(L);
    printf("\n");
    printf("TEST DELETE\n");
    infotype a,b;
    DelAfter(&L,&q,p);
    PrintInfo(L);
    printf("\n");
    printf("TEST DELP\n");
    DelP(&L,999);
    PrintInfo(L);
    return 0;
}