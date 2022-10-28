//Nama : Saul Sayers
//NIM  : 13520094 / 16520075
//Kelas: K02
//PRAKTIKUM 2 SOAL 1

#include <stdio.h>
#include "time.h"

int main(){
    int record,i;
    TIME time1,time2;
    TIME akhir = MakeTIME(0,0,0);
    TIME awal = MakeTIME(23,59,59);
    scanf("%d",&record);
    for (i=1;i<=record;i++){
        printf("[%d]\n", i);
        BacaTIME(&time1);
        BacaTIME(&time2);
        if (TLT(time1,time2)){
            if (TLT(time1,awal)){
                awal = time1;
            }
            if (TGT(time2,akhir)){
                akhir = time2;
            }
            printf("%d\n", Durasi(time1,time2));
        }
        else {
            if (TLT(time2,awal)){
                awal = time2;
            }
            if (TGT(time1,akhir)){
                akhir = time1;
            }
            printf("%d\n", Durasi(time2,time1));
        }
    }
    TulisTIME(awal);
    printf("\n");
    TulisTIME(akhir);
    printf("\n");
    return 0;
}