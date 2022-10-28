/*
NIM: 18219006
NAMA: Marcelino Feihan
TANGGAL: 24 September 2020
TOPIK: List.c
DESKRIPSI: Realisasi list.h
*/


/* MODUL LIST INTEGER */
/* Berisi definisi dan semua primitif pemrosesan list integer */
/* Penempatan elemen selalu rapat kiri */
#include<stdio.h>
#include "boolean.h"
#include"list.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong */
void MakeEmpty (List *T){
    (*T).Neff=0; 
}
/* I.S. sembarang */
/* F.S. Terbentuk list L kosong dengan kapasitas IdxMax-IdxMin+1 */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int Length (List L){
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list kosong */
/* *** Daya tampung container *** */
    return L.Neff;
}
int MaxLength (List L){
/* Mengirimkan maksimum elemen yang dapat ditampung oleh list */
/* *** Selektor INDEKS *** */
    return IdxMax+1;
}
IdxType FirstIdx (List L){
/* Prekondisi : list L tidak kosong */
/* Mengirimkan indeks elemen pertama */
    return IdxMin;
}
IdxType LastIdx (List L){
/* Prekondisi : list L tidak kosong */
/* Mengirimkan indeks elemen terakhir */
/* *** Menghasilkan sebuah elemen *** */
    return L.Neff-1;
}
ElType Get (List L, IdxType i){
/* Prekondisi : list tidak kosong, i antara FirsLIdx(T)..LasLIdx(T) */
/* Mengirimkan elemen list yang ke-i */
    return L.A[i];
}
/* *** Selektor SET : Mengubah nilai list dan elemen list *** */
void Set (List *T, IdxType i, ElType v){
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
    (*T).A[i]=v;
}
void SetNeff (List *L, IdxType N){
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */
    (*L).Neff=N;
}
/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (List L, IdxType i){
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran list */
/* yaitu antara indeks yang terdefinisi untuk container*/
    return ((i>=IdxMin)&&(i<=IdxMax));
}
boolean IsIdxEff (List L, IdxType i){
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara FirstIdx(L)..LastIdx(L) */
    return ((i>=FirstIdx(L))&&(i<=LastIdx(L)));
}
/* ********** Operasi-operasi ********** */
IdxType Search (List L, ElType v){
/* I.S. L, i, v terdefinisi.
/* F.S. Mengembalikan indeks lojik elemen pertama L yang bernilai v (jika ada), */
/* atau mengembalikan IdxUndef jika tidak ada. */
    IdxType j;
    j=FirstIdx(L);
    if(!IsEmpty(L)){
        while ((j<LastIdx(L))&&(L.A[j]!=v)){
        j+=1;
        }
    return L.A[j]==v;
    }
    else{
        return IdxUndef;
    }
   
}
void InsertFirst (List *L, ElType v){
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen pertama L. */
    IdxType j;
    for (j=((*L).Neff-1);j>=0;j--){
        (*L).A[j+1]=(*L).A[j];
    }
    (*L).A[IdxMin]=v;
}
void InsertAt (List *L, IdxType i, ElType v){
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. v disisipkan dalam L pada indeks ke-i (bukan menimpa elemen di i). */
    IdxType j;
    for (j=((*L).Neff-1);j>=i;j--){
        (*L).A[j+1]=(*L).A[j];
    }
    (*L).A[i]=v;
}
void InsertLast (List *L, ElType v){
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen terakhir L. */
    IdxType a;
    a=(*L).Neff;
    (*L).A[a-1]=v;
}
void DeleteFirst (List *L, ElType *F){
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen pertama L, elemen pertama L dihapus dari L. */

}
void DeleteAt (List *L, IdxType i){
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. Elemen L pada indeks ke-i dihapus dari L. */

}
void DeleteLast (List *L, ElType *F){
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen terakhir L, elemen terakhir L dihapus dari L. */
}
void Concat (List L1, List L2, List *L3){
/* I.S. L1 ≠ L2, L1 ≠ L3, dan L3 ≠ L2; L1, L2 mungkin kosong */
/* F.S. L3 adalah hasil Konkatenasi ("Menyambung") dua buah list, L2 */
/* ditaruh di belakang L1 */
    if (IsEmpty(L2)){
        (*L3)=L1;
    }
    else if (IsEmpty(L1)){
        (*L3)=L2;
    }
    else{
        IdxType j;
        int n;
        n=(L1.Neff)+(L2.Neff);
        SetNeff(L3,n);
        for (j=FirstIdx(L1);j<=LastIdx(L1);j++){
            (*L3).A[j]=L1.A[j];
        }
        for (j=FirstIdx(L2);j<=LastIdx(L2);j++){
            (*L3).A[LastIdx(L1)+j]=L2.A[j];
        }
    }
}
/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean IsEmpty (List L){
/* Mengirimkan true jika list L kosong, mengirimkan false jika tidak */
    return L.Neff==0;
}
