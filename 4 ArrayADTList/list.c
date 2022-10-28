/*
NIM         : 18221072
Nama        : Hilmi Baskara Radanto
Tanggal     : 26 September 2022
Topik       : Pra-praktikum 4
Deskripsi   : Implementasi list.h
*/

/* Indeks yang digunakan seberapa banyak memori itu terisi */
/* Jika L adalah List, cara deklarasi dan akses: */
/* Deklarasi: L : List */
/* Maka cara akses:
 * L.A untuk mengakses seluruh nilai elemen list
 * L.A[i] untuk mengakses elemen ke-i */

#include "list.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor: create list kosong */
List MakeList(){
/* I.S. sembarang */
/* F.S. Terbentuk list L kosong dengan kapasitas MaxEl */
    List L;
    IdxType i;
    for (i = 0; i < MaxEl; i++){
        L.A[i] = Mark;
    }
    return L;
}
/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean IsEmpty(List L){
/* Mengirimkan true jika list L kosong, mengirimkan false jika tidak */
    return (L.A[0] == Mark);
}
/* *** Menghasilkan sebuah elemen *** */
ElType Get(List L, IdxType i){
/* Prekondisi : list tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen list yang ke-i */
    return L.A[i];
}
/* *** Selektor SET : Mengubah nilai list dan elemen list *** */
void Set(List *L, IdxType i, ElType v){
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
    (*L).A[i] = v;
}
/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int Length(List L){
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list kosong */
    int i = 0;
    while (L.A[i] != Mark){
        i++;
    }
    return i;
}
/* *** Selektor INDEKS *** */
IdxType FirstIdx(List L){
/* Prekondisi : list L tidak kosong */
/* Mengirimkan indeks elemen pertama */
    IdxType i = 0;
    return i;
}

IdxType LastIdx(List L){
/* Prekondisi : list L tidak kosong */
/* Mengirimkan indeks elemen terakhir */
    return Length(L) - 1;
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (List L, IdxType i){
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran list */
/* yaitu antara indeks yang terdefinisi untuk container*/
    return (i >= 0 && i <= MaxEl);
}
boolean IsIdxEff (List L, IdxType i){
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara FirstIdx(L)..LastIdx(L) */
    return (i >= FirstIdx(L) && i <= LastIdx(L));
}
/* ********** Operasi-operasi ********** */
boolean Search(List L, ElType X){
/* Prekondisi : X sembarang */
/* Mengirimkan true jika terdapat elemen X di dalam list */
/* yaitu antara FirstIdx(L)..LastIdx(L) */
    boolean kondisi = false;
    IdxType i = FirstIdx(L);
    while (i <= LastIdx(L) && kondisi == false) {
        if (L.A[i] == X){
            kondisi = true;
        }
        i++;
    }
    return kondisi;
}
void InsertFirst(List *L, ElType X){
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen pertama L. */
    InsertAt(L, X, FirstIdx(*L));
}
void InsertAt(List *L, ElType X, IdxType i){
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. v disisipkan dalam L pada indeks ke-i (bukan menimpa elemen di i). */
    IdxType j = LastIdx(*L);
    while (j >= i){
        Set(L, j + 1, Get(*L, j));
        j--;
    }
    Set(L, i, X);
}

void InsertLast(List *L, ElType X){
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen terakhir L. */
    InsertAt(L, X, LastIdx(*L) + 1);
}    

void DeleteFirst(List *L){
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen pertama L, elemen pertama L dihapus dari L. */
    DeleteAt(L, FirstIdx(*L));
}
void DeleteAt(List *L, IdxType i){
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. Elemen L pada indeks ke-i dihapus dari L. */
    IdxType j = LastIdx(*L);
    while (i <= j){
        Set(L, i, Get(*L, i + 1));
        i++;
    }
}

void DeleteLast(List *L){
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen terakhir L, elemen terakhir L dihapus dari L. */
    Set(L, LastIdx(*L), Mark);
}

List Concat(List L1, List L2)
/* Prekondisi : L1 dan L2 tidak kosong */
/* Mengirimkan sebuah List yang merupakan gabungan dari L1 dan L2 */
/* Urutan elemen terisi dari L1, lalu L2 */
/* Contoh : L1 : [1, 2]{} L2 : [3, 4]{} Mengembalikan [1, 2, 3, 4] */
{
    List L = MakeList(L);
    int i;
    for (i = 0; i < Length(L1); i++)
    {
        InsertLast(&L, Get(L1, i));
    }
    for (i = 0; i < Length(L2); i++)
    {
        InsertLast(&L, Get(L2, i));
    }
    return L;
}