/*
    NIM         : 18221072
    Nama        : Hilmi Baskara Radanto
    Tanggal     : 02 Oktober 2022
    Topik       : Praktikum 4
    Deskripsi   : Menghapus nilai minimal dan maksimal dari sebuah list,
                  lalu menambahkan kedua nilai tersebut pada urutan terakhir list
*/
#include <stdio.h>
#include "list.h"

ElType ValMax (List T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai maksimum tabel */
{
    ElType max = Get(T, FirstIdx(T));
    for (int i = FirstIdx(T); i <= LastIdx(T); i++)
    {
        if (Get(T, i) > max)
        {
            max = Get(T, i);
        }
    }
    return max;
}

ElType ValMin (List T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai minimum tabel */
{
    ElType min = Get(T, FirstIdx(T));
    for (int i = FirstIdx(T); i <= LastIdx(T); i++)
    {
        if (Get(T, i) < min)
        {
            min = Get(T, i);
        }
    }
    return min;
}

/* *** Mengirimkan indeks elemen bernilai ekstrem *** */
IdxType IdxMaxTab (List T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i dengan elemen ke-i adalah nilai maksimum pada tabel */
{
    IdxType i = FirstIdx(T);
    for (i; i<=LastIdx(T); i++){
        if (Get(T, i) == ValMax(T)){
            return i;
        }
    }
}


IdxType IdxMinTab (List T)
/* Prekondisi : Tabel tidak kosong */
/* Mengirimkan indeks i */
/* dengan elemen ke-i nilai minimum pada tabel */
{
    IdxType i = FirstIdx(T);
    for (i; i<=LastIdx(T); i++){
        if (Get(T, i) == ValMin(T)){
            return i;
        }
    }
}

List MinMax(List L){
    ElType min = ValMin(L);
    DeleteAt(&L, IdxMinTab(L));
    InsertLast(&L, min);
    ElType max = ValMax(L);
    DeleteAt(&L, IdxMaxTab(L));
    InsertLast(&L, max);
    return L;
}