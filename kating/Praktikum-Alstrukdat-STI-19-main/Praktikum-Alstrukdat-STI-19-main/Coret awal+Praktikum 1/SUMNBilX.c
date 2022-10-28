/*
NIM:18219006
Nama: Marcelino Feihan
Tanggal: 17/09/2020
Topik Praktikum: Praktikum 1
Deskripsi: SUMNBilX
*/
#include<stdio.h>
int main(){
    int i,X,N,Sum;
    i=1;
    Sum=0;
    scanf("%d",&X);
    while (X!=9999){
        printf("%d\n",X);
        Sum+=X;
        i+=1;
        scanf("%d",&X);
    }
    printf("Jumlah : %d\n",Sum);
    printf("Banyaknya bilangan : %d\n",i-1);
    return 0;
}