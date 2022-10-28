/*
    NIM         : 13517014
    Nama        : Yoel Susanto
    Deskripsi   : ADT List dengan implementasi array statis
*/
#include "list.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
void MakeEmpty(List *L)
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
{
    L->Neff = 0;
}

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int Length(List L)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
{
    return L.Neff;
}

/* *** Daya tampung container *** */
int MaxLength(List L)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
    return IdxMax - IdxMin + 1;
}

/* *** Selektor INDEKS *** */
IdxType FirstIdx(List L)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen pertama */
{
    return 0;
}

IdxType LastIdx(List L)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen terakhir */
{
    return L.Neff - 1;
}

/* *** Menghasilkan sebuah elemen *** */
ElType Get(List L, IdxType i)
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(L)..LastIdx(L) */
/* Mengirimkan elemen tabel yang ke-i */
{
    return L.A[i];
}

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
void Set(List *L, IdxType i, ElType v)
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
/* Operasi hanya dilakukan apabila i berada dalam index efektif*/
{
    if (!IsIdxEff(*L, i))
    {
        return;
    }
    (*L).A[i] = v;
}

void SetNeff(List *L, IdxType N)
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */
{
    L->Neff = N;
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid(List L, IdxType i)
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
    if ((i >= IdxMin) && (i <= IdxMax))
    {
        return true;
    }

    return false;
}

boolean IsIdxEff(List L, IdxType i)
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(L)..LastIdx(L) */
{
    if ((i >= IdxMin) && (i < L.Neff))
    {
        return true;
    }

    return false;
}

/* ********** Operasi-operasi ********** */
IdxType Search(List L, ElType v)
/* I.S. L, i, v terdefinisi.
/* F.S. Mengembalikan indeks lojik elemen pertama L yang bernilai v (jika ada), */
/* atau mengembalikan IdxUndef jika tidak ada. */
{
    IdxType iterationIdx = FirstIdx(L);
    IdxType targetIdx = IdxUndef;

    // while element not exhausted and still not found
    while (iterationIdx <= LastIdx(L) && targetIdx == IdxUndef)
    {
        if (L.A[iterationIdx] == v)
        {
            targetIdx = iterationIdx;
        }
        iterationIdx++;
    }
    return targetIdx;
}

void InsertFirst(List *L, ElType v)
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen pertama L. */
{
    InsertAt(L, 0, v);
}

void InsertAt(List *L, IdxType i, ElType v)
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. v disisipkan dalam L pada indeks ke-i (bukan menimpa elemen di i). */
{
    IdxType iterationIdx;
    for (iterationIdx = L->Neff; iterationIdx > i; iterationIdx--)
    {
        L->A[iterationIdx] = L->A[iterationIdx - 1];
    }
    L->A[iterationIdx] = v;
    L->Neff++;
}

void InsertLast(List *L, ElType v)
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen terakhir L. */
{
    InsertAt(L, L->Neff, v);
}

void DeleteFirst(List *L, ElType *F)
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen pertama L, elemen pertama L dihapus dari L. */
{
    (*F) = Get(*L, FirstIdx(*L)); // atau (*F) = L->A[0];
    DeleteAt(L, 0);
}

void DeleteAt(List *L, IdxType i)
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. Elemen L pada indeks ke-i dihapus dari L. */
{
    IdxType iterationIdx;
    for (iterationIdx = i; iterationIdx < L->Neff - 1; iterationIdx++)
    {
        L->A[iterationIdx] = L->A[iterationIdx + 1];
    }
    L->Neff--;
}

void DeleteLast(List *L, ElType *F)
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen terakhir L, elemen terakhir L dihapus dari L. */
{
    (*F) = Get(*L, LastIdx(*L)); // atau (*F) = L->A[L->Neff-1];
    DeleteAt(L, L->Neff);
}

void Concat(List L1, List L2, List *L3)
/* I.S. L1 ≠ L2, L1 ≠ L3, dan L3 ≠ L2; L1, L2 mungkin kosong */
/* F.S. L3 adalah hasil Konkatenasi ("Menyambung") dua buah list, L2 */
/* ditaruh di belakang L1 */
{
    IdxType iterationIdx;
    for (iterationIdx = 0; iterationIdx < L1.Neff; iterationIdx++)
    {
        InsertLast(L3, L1.A[iterationIdx]);
    }
    for (iterationIdx = 0; iterationIdx < L2.Neff; iterationIdx++)
    {
        InsertLast(L3, L2.A[iterationIdx]);
    }
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty(List L)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
    if (L.Neff > 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}