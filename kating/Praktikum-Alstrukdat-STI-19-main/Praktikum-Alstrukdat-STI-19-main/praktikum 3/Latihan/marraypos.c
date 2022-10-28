//NIM           :13519106
//Nama          :Shifa Salsabiila
//Tanggal       :10 September 2020
//Topik         :ADT
//Deskripsi     :Menerima masukan sebuah array T dan sebuah integer X. Jika X merupakan bagian dari T, maka
//               akan dituliskan pada baris ke berapa pada T X pertama ditemukan dan mengembalikan apakah
//               X merupakan maksimum, minimum, atau median pada T. Jika X tidak ditemukan pada T, akan dituliskan
//               "X tidak ada".

/*File: marraypos.c*/
/*Program Marraypos*/
/*Driver ADT Arraypos*/

#include <stdio.h>
#include <math.h>
#include "arraypos.h"
#include "boolean.h"

int main()
{   /*KAMUS*/
    TabInt T;
    int X;
    ElType max, min, median;
    
    /*ALGORITMA*/
    MakeEmpty(&T);
    BacaIsi(&T);
    TulisIsiTab(T);
    printf("\n");
    
    scanf("%d", &X);
    
    if (SearchB(T,X)){
        printf("%d\n", Search1(T,X));
        
        /*MaxMin*/
        MaxMin(T, &max, &min);
        
        /*Median*/
        Sort(&T, true);
        if (NbElmt(T)%2==1){
            median = Elmt(T,(NbElmt(T)/2));
        } else{
            median = Elmt(T,(NbElmt(T)/2)-1);
        }
        
        if (X==max){
            printf("maksimum\n");
        }
        if (X==min){
            printf("minimum\n");
        }
        if (X==median){
            printf("median\n");
        }
        
    } else{
        printf("%d tidak ada\n", X);
    }
    
    return 0;
}
