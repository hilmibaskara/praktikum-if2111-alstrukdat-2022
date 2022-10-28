/*
NAMA: MARCELINO FEIHAN
NIM:18219006
TANGGAL: 04/10/2020
JUDUL: PERBAIKAN PRAKTIKUM 3*/

#include<stdio.h>
#include"list.h"
#include<stdlib.h>
/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk List kosong dengan ukuran InitialSize
 */
List MakeList(){

/**
 * Destruktor
 * I.S. List terdefinisi
 * F.S. list->A terdealokasi
 */
    List L;
    L.A=(ElType*)malloc(InitialSize*sizeof(ElType));
    L.Capacity=InitialSize;
    L.Neff=0;
    return L;
}
void DeallocateList(List *list){
    free((*list).A);
    (*list).Capacity=0;
    (*list).Neff=0;
/**
 * Fungsi untuk mengetahui apakah suatu list kosong.
 * Prekondisi: list terdefinisi
 */
}
boolean IsEmpty(List list){

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif list, 0 jika tabel kosong.
 * Prekondisi: list terdefinisi
 */
    return list.Neff==0;
}
int Length(List list){

/**
 * Mengembalikan elemen list L yang ke-I (indeks lojik).
 * Prekondisi: list tidak kosong, i di antara 0..Length(list).
 */
    return list.Neff;
}
ElType Get(List list, IdxType i){

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: list terdefinisi
 */
    return list.A[i];
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
    if(((*list).Neff)==(*list).Capacity){
        IdxType k;
        ElType *arr=(ElType*)malloc((InitialSize*2)*sizeof(ElType));
        for (k=0;k<(*list).Neff;k++){
            arr[k]=Get(*list,k);
        }
        free((*list).A);
        (*list).A=arr;
        (*list).Capacity=InitialSize*2;
     }
    IdxType j;
    for (j=(*list).Neff-1;j>=i;j--){
        (*list).A[j+1]=(*list).A[j];
    }
    (*list).A[i]=el;
    (*list).Neff+=1;
}
void InsertLast(List *list, ElType el){
/**
 * Fungsi untuk menambahkan elemen baru di awal list.
 * Prekondisi: list terdefinisi
 */
     /*f (IsEmpty(*list)){
        (*list).A[0]=el;
        (*list).Neff+=1;
    }
    else{
         if(((*list).Neff+1)>(*list).Capacity){
            IdxType k;
            int temp[((*list).Capacity)];
            for (k=0;k<(*list).Neff;k++){
                temp[k]=(*list).A[k];
            }
            DeallocateList(list);
            MakeList();
            (*list).Capacity*=2;
        }
        (*list).A[(*list).Neff]=el;
        (*list).Neff+=1;
    }
    (*list).A[(*list).Neff]=el;
    (*list).Neff+=1;*/
    InsertAt(list,el,list->Neff);
}
void InsertFirst(List *list, ElType el){
    /*if (IsEmpty(*list)){
        (*list).A[0]=el;
        (*list).Neff+=1;
    }
    else{
        if(((*list).Neff+1)>(*list).Capacity){
            IdxType k;
            int temp[((*list).Capacity)];
            for (k=0;k<(*list).Neff;k++){
                temp[k]=(*list).A[k];
            }
            DeallocateList(list);
            MakeList();
            (*list).Capacity*=2;
        }
        IdxType j;
        for (j=(*list).Neff-1;j==0;j--){
        (*list).A[j+1]=(*list).A[j];
        }
        (*list).A[0]=el;
        (*list).Neff+=1;
    }*/
    InsertAt(list,el,0);
}