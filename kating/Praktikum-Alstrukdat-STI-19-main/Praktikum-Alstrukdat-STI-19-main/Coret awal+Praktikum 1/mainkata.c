#include<stdio.h>
#include"mesinkata1.h"
boolean IsKataSama(Kata KataWHILE, Kata CKata){
    return ((KataWHILE.length==CKata.length)&&(KataWHILE.TabKata[0]==CKata.TabKata[0])&&(KataWHILE.TabKata[1]==CKata.TabKata[1])&&(KataWHILE.TabKata[2]==CKata.TabKata[2])&&(KataWHILE.TabKata[3]==CKata.TabKata[3])&&(KataWHILE.TabKata[4]==CKata.TabKata[4]));

int main(){
    int hitung=0;
    Kata KataWHILE;
    KataWHILE.TabKata[0]='W';
    KataWHILE.TabKata[1]='H';
    KataWHILE.TabKata[2]='I';
    KataWHILE.TabKata[3]='L';
    KataWHILE.TabKata[4]='E';
    KataWHILE.length=5;
    STARTKATA();
    while(!EndKata){
        if (IsKataSama(KataWHILE, CKata)){
            hitung+=1;
        }
        ADVKATA();
    }
    printf("%d\n",hitung);
    /*int panjang=0;
    int counter=0;
    STARTKATA();
    while(!EndKata){
        panjang=panjang+CKata.length;
        counter+=1;
        ADVKATA();
    }
    if (counter!=0){
        printf("%d\n",panjang/counter);
    }
    else{
        printf("Tidak ada kata yang dihitung\n");
    }*/
    return 0;
}