/*NAMA: MARCELINO FEIHAN
NIM: 18219006
TANGGAL: 01/10/2020
JUDUL: PRAKTIKUM 3
DESKRIPSI: list.c
*/
#include "list.h"
#include<stdio.h>
#include<stdlib.h>
List MakeList(){
/**
 * Destruktor
 * I.S. List terdefinisi
 * F.S. list->A terdealokasi
 */
    List L;
    L.A=(ElType*)malloc(L.Capacity*sizeof(ElType));
    L.Capacity=InitialSize;
    L.Neff=0;
    return L;
}
void DeallocateList(List *list){

/**
 * Fungsi untuk mengetahui apakah suatu list kosong.
 * Prekondisi: list terdefinisi
 */
    free(list->A);
}
boolean IsEmpty(List list){
/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif list, 0 jika tabel kosong.
 * Prekondisi: list terdefinisi
 */
    return (list.Neff==0);
}
int Length(List list){

/**
 * Mengembalikan elemen list L yang ke-I (indeks lojik).
 * Prekondisi: list tidak kosong, i di antara 0..Length(list).
 */
    return (list.Neff);
}
ElType Get(List list, IdxType i){

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: list terdefinisi
 */
    return (list.A[i]);
}
int GetCapacity(List list){

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: list terdefinisi, i di antara 0..Length(list).
 */
    return list.Capacity;

}
void InsertAt(List *list, ElType el, IdxType i){

/**
 * Fungsi untuk menambahkan elemen baru di akhir list.
 * Prekondisi: list terdefinisi
 */
    IdxType j;
    (*list).Neff+=1;
    if ((*list).Neff>(*list).Capacity){
        int temp[(*list).Neff],max,eff;
        max=(*list).Capacity;
        eff=(*list).Neff;
        IdxType k;
        for (k=0;k<eff;k++){
            temp[k]=(*list).A[k];
        }
        DeallocateList(list);
        (*list).A=(ElType*)malloc((L.Capacity*2)*sizeof(ElType));
        for (k=0;k<eff;k++){
            (*list).A[k]=temp[k];
        }
        (*list).Neff=eff;
    }
    for (j=((*list).Neff-1);j>=i;j--){
        (*list).A[j+1]=(*list).A[j];
    }
    (*list).A[i]=el;
}
void InsertLast(List *list, ElType el){

/**
 * Fungsi untuk menambahkan elemen baru di awal list.
 * Prekondisi: list terdefinisi
 */
    IdxType a;
    (*list).Neff+=1;
    if ((*list).Neff>(*list).Capacity){
        int temp[(*list).Neff],max,eff;
        max=(*list).Capacity;
        eff=(*list).Neff;
        IdxType k;
        for (k=0;k<eff;k++){
            temp[k]=(*list).A[k];
        }
        DeallocateList(list);
        *list=MakeList();
        (*list).Capacity=max*2;
        for (k=0;k<eff;k++){
            (*list).A[k]=temp[k];
        }
        (*list).Neff=eff;
    }
    a=(*list).Neff;
    (*list).A[a-1]=el;
}
void InsertFirst(List *list, ElType el){
    IdxType j;
    (*list).Neff+=1;
    if ((*list).Neff>(*list).Capacity){
        int temp[(*list).Neff],max,eff;
        max=(*list).Capacity;
        eff=(*list).Neff;
        IdxType k;
        for (k=0;k<eff;k++){
            temp[k]=(*list).A[k];
        }
        DeallocateList(list);
        *list=MakeList();
        (*list).Capacity=max*2;
        for (k=0;k<eff;k++){
            (*list).A[k]=temp[k];
        }
        (*list).Neff=eff;
    }
    for (j=((*list).Neff-1);j>=0;j--){
        (*list).A[j+1]=(*list).A[j];
    }
    (*list).A[0]=el;
}