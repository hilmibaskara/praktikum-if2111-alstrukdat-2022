/*
Nama : Carissa Tabina Rianda
NIM : 18221120
Tanggal : 18 September 2022
Topik Praktikum : Pra-praktikum 3
Deskripsi : Submit kembali file arraydin.c yang merupakan implementasi dari arraydin.h
*/

#include <stdio.h>
#include <stdlib.h>
#include "arraydin.h"

// Boolean
#define boolean unsigned char
#define true 1
#define false 0


ArrayDin MakeArrayDin(ArrayDin *array){
    /**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ArrayDin kosong dengan ukuran InitialSize
 */
     ArrayDin make;
    make.A = (ElType*) malloc (InitialSize * sizeof(ElType));
    make.Capacity = InitialSize;
    make.Neff = 0;
    return make;
}


void DeallocateArrayDin(ArrayDin *array){
    /**
     * Destruktor
     * I.S. ArrayDin terdefinisi
     * F.S. array->A terdealokasi
     */
     free((*array).A);
}



int Length(ArrayDin array) {
    /**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */

    return array.Neff;
}

boolean IsEmpty(ArrayDin array){
    /**
    * Fungsi untuk mengetahui apakah suatu array kosong. */
    return (Length(array) == 0);
}

ElType Get(ArrayDin array, IdxType i){
    /**
     * Mengembalikan elemen array L yang ke-I (indeks lojik).
     * Prekondisi: array tidak kosong, i di antara 0..Length(array).
     */
    return array.A[i];
}
int GetCapacity(ArrayDin array){
    /**
     * Fungsi untuk mendapatkan kapasitas yang tersedia.
     * Prekondisi: array terdefinisi
     */
    return array.Capacity;
}

void InsertAt(ArrayDin *array, ElType el, IdxType i){
    /**
     * Fungsi untuk menambahkan elemen baru di index ke-i
     * Prekondisi: array terdefinisi, i di antara 0..Length(array).
     */
    int Idx;
    Idx = Length(*array); 

    /* Menggeser elemen hingga index i */
    while (Idx > i){     
        (*array).A[Idx] = (*array).A[Idx-1];  
        Idx -= 1;}                

    /* insert elemen baru */
    (*array).A[i] = el;

    /* update Neff*/
    (*array).Neff += 1;
}

void DeleteAt(ArrayDin *array, IdxType i){
    /**
     * Fungsi untuk menghapus elemen di index ke-i ArrayDin
     * Prekondisi: array terdefinisi, i di antara 0..Length(array).
     */
    int Idx = i;

    while (Idx < (Length(*array))){            
        (*array).A[Idx] = (*array).A[Idx+1];
        Idx += 1;}

    /* update Neff */
    (*array).Neff -= 1;

}
