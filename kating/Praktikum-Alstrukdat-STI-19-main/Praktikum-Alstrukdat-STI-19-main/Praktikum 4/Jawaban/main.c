/* NIM: 18219006
NAMA: Marcelino Feihan
TANGGAL: 8 Oktober 2020
TOPIK: Praktikum 4
DESKRIPSI: Main.c
*/
#include<stdio.h>
#include<stdlib.h>
int main(){
    int jumlahAntrean,i;
    scanf("%d",&jumlahAntrean);
    int nomorAntrean[jumlahAntrean];
    for (i=0;i<jumlahAntrean;i++){
        scanf("%d",&nomorAntrean[i]);
    }
    printf("%d\n",nomorAntrean[0]);
    return 0;
}