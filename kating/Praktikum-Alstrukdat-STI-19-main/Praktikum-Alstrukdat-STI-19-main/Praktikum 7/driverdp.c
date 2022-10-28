#include<stdio.h>
#include<stdlib.h>
#include"listdp.c"
#include"listdp.h"
int main(){
    List L;
    address p,q;
    infotype a,b;
    CreateEmpty(&L);
    if(IsEmpty(L)){
        printf("Hello\n");
    }
    InsVLast(&L,5);
    InsVFirst(&L,10);
    p=Search(L,10);
    q=Search(L,5);
    printf("TEST SEARCH\n");
    printf("%d\n",First(L));
    printf("%d\n",p);
    printf("TEST DELETE\n");
    DelVLast(&L,&b);
    DelVFirst(&L,&a);
    printf("%d\n",a);
    printf("%d\n",b);
    if(IsEmpty(L)){
        printf("Kosong kak\n");
    }
    printf("TEST INSERT\n");
    InsVFirst(&L,5);
    InsVFirst(&L,100);
    InsVFirst(&L,99);
    InsVFirst(&L,6);
    InsVFirst(&L,7);
    address r=Alokasi(999),s=Search(L,7);
    InsertBefore(&L,r,s);
    PrintForward(L);
    PrintBackward(L);
    printf("\n");
    printf("TEST DELETE#2\n");
    DelP(&L,6);
    PrintForward(L);
    PrintBackward(L);
    return 0;
}