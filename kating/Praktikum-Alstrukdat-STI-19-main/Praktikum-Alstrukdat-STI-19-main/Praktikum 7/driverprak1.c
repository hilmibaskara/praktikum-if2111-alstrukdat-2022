#include<stdio.h>
#include<stdlib.h>
#include"diantarakita.h"
#include"diantarakita.c"
int main(){
    List L;
    address q=Alokasi(123);
    Dealokasi(&q);
    CreateEmpty(&L);
    if (IsEmpty(L)){
        printf("Halo\n");
    }
    InsertLast(&L,99);
    InsertFirst(&L,5);
    InsertFirst(&L,10);
    InsertAfter(&L,99,0);
    InsertBefore(&L,10,100);
    PrintInfo(L);
    
    
    /*InsVFirst(&L,5);
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
    Nprintf("\n");
    printf("TEST DELP\n");
    DelP(&L,999);
    PrintInfo(L);*/
    return 0;
}