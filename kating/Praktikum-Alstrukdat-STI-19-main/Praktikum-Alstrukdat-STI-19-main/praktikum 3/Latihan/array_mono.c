//NIM           :13519106
//Nama          :Shifa Salsabiila
//Tanggal       :10 September 2020
//Topik         :ADT
//Deskripsi     :Menerima sebuah array T, kemudian menuliskan keterangan mengenai kemonotonan
//               array tersebut. Ketentuan output:
//               1. Array A adalah Array Monotonik Tidak Mengecil jika untuk semua i <= j, A[i] <= A[j]
//               2. Array A adalah Array Monotonik Tidak Membesar jika untuk semua i <= j, A[i] >= A[j]
//               3. Array A adalah Array Monotonik Statik jika untuk semua i <= j, A[i] = A[j]
//               4. Array A adalah Array Tidak Monotonik jika tidak mengikuti salah satu ketentuan di atas

/*File: array_mono.c*/
/*Program ArrayMonotonik*/
/*Driver ADT Arraypos*/

#include <stdio.h>
#include <math.h>
#include "arraypos.h"
#include "boolean.h"

int main()
{   /*KAMUS*/
    TabInt T;
    TabInt sortMengecil;
    TabInt sortMembesar;
    
    /*ALGORITMA*/
    MakeEmpty(&T);
    BacaIsi(&T);
    
    sortMengecil = T;
    sortMembesar = T;
    
    Sort(&sortMengecil, false);
    Sort(&sortMembesar, true);
    
    if (IsEQ(T, sortMengecil) && IsEQ(T, sortMembesar)){
        printf("Array monotonik statik\n");
    } else if (IsEQ(T, sortMengecil) && !IsEQ(T, sortMembesar)){
        printf("Array monotonik tidak membesar\n");
    } else if (!IsEQ(T, sortMengecil) && IsEQ(T, sortMembesar)){
        printf("Array monotonik tidak mengecil\n");
    } else{
        printf("Array tidak monotonik\n");
    }
    
    
    return 0;
}
