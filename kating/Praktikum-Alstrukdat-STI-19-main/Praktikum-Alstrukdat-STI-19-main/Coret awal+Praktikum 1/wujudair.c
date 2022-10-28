/*
NIM:18219006
Nama: Marcelino Feihan
Tanggal: 17/09/2020
Topik Praktikum: Praktikum 1
Deskripsi:Wujud air
*/
#include<stdio.h>
int main(){
    int suhu;
    scanf("%d",&suhu);
    if (suhu<0){
        printf("PADAT\n");
    }
    else if (suhu==0){
        printf("PADAT-CAIR\n");
    }
    else if((suhu>0)&&(suhu<100)){
        printf("CAIR\n");
    }
    else if(suhu==100){
        printf("CAIR-GAS\n");
    }
    else{
        printf("GAS\n");
    }
    return 0;
}