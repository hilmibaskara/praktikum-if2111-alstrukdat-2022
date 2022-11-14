/*
    NIM         : 18221072
    Nama        : Hilmi Baskara Radanto
    Tanggal     : 13 November 2022
    Topik       : Praktikum 10
    Deskripsi   : Implementasi List Double Pointer dengan header listdp.h
*/

#include "listdp.h"
#include <stdio.h>
#include <stdlib.h>

/* Definisi list : */
/* List kosong : First(L) = Nil dan Last(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P), Prev(P) */
/* Elemen terakhir list: Last(L) */

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
/* Mengirim true jika list kosong. Lihat definisi di atas. */
{
    return (First(L) == Nil && Last(L) == Nil);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
{
    First(*L) = Nil;
    Last(*L) = Nil;
}
/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
{
    address P;
    P = (address) malloc(sizeof(ElmtList));
    if (P != Nil)
    {
        Info(P) = X;
        Next(P) = Nil;
        Prev(P) = Nil;
        return P;
    }
}

void Dealokasi (address P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    free(P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
    address P = First(L);
    boolean found = false;
     while(P != Nil && !found){
        if(Info(P) == X) found = true;
        else P = Next(P);
    }
    if (found) return P;
    else return Nil;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
    address p = Alokasi(X);
    InsertFirst(L, p);
}
void InsVLast (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    address P;
    P = Alokasi(X);
    if (P != Nil) InsertLast(L, P);
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
    address P = L->First;
    *X = Info(P);
    DelFirst(L, &P);
    free(P);

}
void DelVLast (List *L, infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
    address P = Last(*L);
    *X = Info(P);
    DelLast(L, &P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
    if (IsEmpty(*L))
    {
        First(*L) = P;
        Last(*L) = P;
    }
    else
    {
        InsertBefore(L, P, First(*L));
    }
}
void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    Prev(P) = Last(*L);
    if (!(IsEmpty(*L))) { 
        Next(Last(*L)) = P;
    } else {
        First(*L) = P;
    }
    Last(*L) = P;
}

void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    Next(P) = Next(Prec);
    Prev(P) = Prec;
    Next(Prec) = P;
    if (Next(P) == Nil)
    {
        L->Last = P;
    }
    else
    {
        Prev(Next(P)) = P;
    }
}

void InsertBefore (List *L, address P, address Succ)
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */
{
    Prev(P) = Prev(Succ);
    Next(P) = Succ;
    Prev(Succ) = P;
    if (Prev(P) == Nil) First(*L) = P;
    else Next(Prev(P)) = P;
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    if (L->First == L->Last)
    {
        Next(*P) = Nil;
        Prev(*P) = Nil;
    } 
    else 
    {
        L->First = Next(*P);
        Prev(*P) = Nil;
        Next(*P) = Nil;
    }
    
}

void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
{
    if (L->First = L->Last)
    {
        L->First = Nil;
        L->Last = Nil;
    }
    else
    {
        L->Last = Prev(*P);
        Next(L->Last) = Nil;
    }
}

void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{  
    address p = Search(*L, X);
    if (p != Nil)
    {
        if(First(*L) == Last(*L))
        {
            Next(p) = Nil;
            Prev(p) = Nil;
        }
        else
        {
            address prec = Prev(p);
            DelAfter(L, &p, prec);
            // Next(Prev(p)) = Next(p);
            // Prev(Next(p)) = Prev(p);
        }
    }
}

void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    (*Pdel) = Next(Prec);
    Next(Prec) = Next(*Pdel);
    if (Next(Prec) != Nil)
    {
        Prev(Next(Prec)) = Prec;
        Next(*Pdel) = Nil;
    }
    else
    {
        Last(*L) = Prec;
    }
    Prev(*Pdel) = Nil;
}
void DelBefore (List *L, address *Pdel, address Succ)
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    *Pdel = Prev(Succ);
    Prev(Succ) = Prev(*Pdel);
    if (Prev(Succ) != Nil)
    {
        Next(Prev(Succ)) = Succ;
        Prev(*Pdel) = Nil;
    }
    else
    {
        First(*L) = Succ;
    }
    Next(*Pdel) = Nil;
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintForward (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    if (IsEmpty(L)) printf("[]");
    else
    {
        address P = L.First;
        printf("[");
        while (P != Nil)
        {
            printf("%d", Info(P));
            if (Next(P) != Nil)
            {
                printf(",");
            }
            P = Next(P);
        }
        printf("]");
    }
}

void PrintBackward (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    if (IsEmpty(L)) printf("[]");
    else
    {
        address P = Last(L);
        printf("[");
        while (P != Nil)
        {
            printf("%d", Info(P));
            if (Prev(P) != Nil)
            {
                printf(",");
            }
            P = Prev(P);
        }
        printf("]");
    }
}
