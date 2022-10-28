#include<stdio.h>
#include"mesinkar.h"
#include"mesinkar.c"
int main(){
    int count=0;
    char rn;
    START();
    while (CC!=MARK){
        rn=CC;
        ADV();
        if(rn=='l'&&CC=='e'){
            count=count+1;
        }
        }
    printf("%d\n",count);
    return 0;
}