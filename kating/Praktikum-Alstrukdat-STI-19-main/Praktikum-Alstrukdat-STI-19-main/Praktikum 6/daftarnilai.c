/*
NAMA:MARCELINO FEIHAN
NIM:18219006
TANGGAL:26/10/2020
TOPIK:Praktikum 6
DESKRIPSI:daftarnilai.c
*/
#include<stdio.h>
#include<stdlib.h>
#include"listlinier.h"
#include"listlinier.c"
int main(){
    List L,temp;
    CreateEmpty(&L);
    infotype input;
    scanf("%d",&input);
    if (input>100||input<0){
        printf("Daftar nilai kosong");
    }    
    else{
        while(input<=100&&input>=0){
            InsVFirst(&L,input);
            scanf("%d",&input);
        }
        temp=L;
        printf("%d\n",NbElmt(L));
        printf("%d\n",Max(L));
        printf("%d\n",Min(L));
        printf("%.2f\n",Average(L));
        PrintInfo(L);
        InversList(&L);
        PrintInfo(L);
    }
    return 0;
}