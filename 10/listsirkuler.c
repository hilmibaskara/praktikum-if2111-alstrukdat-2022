/*
    NIM         : 18221072
    Nama        : Hilmi Baskara Radanto
    Tanggal     : 13 November 2022
    Topik       : Praktikum 10
    Deskripsi   : Implementasi List Double Pointer dengan header listsirkuler.h
*/

#include "listsirkuler.h"
#include <stdio.h>
#include <stdlib.h>

/* Definisi list : */
/* List kosong : First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list: jika addressnya Last, maka Next(Last)=First(L) */

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
/* Mengirim true jika list kosong. Lihat definisi di atas. */
{
    return (First(L) == Nil);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. L sembarang             */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
{
    First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    address P;
    P = (address) malloc(sizeof(infotype));
    if (P == Nil){
        return Nil;
    }
    else{
        Info(P) = X;
        Next(P) = Nil;
        return P;
    }    
}

void Dealokasi (address P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    Next(P) = Nil;
    free(P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
    if (IsEmpty(L)) return Nil;
    else
    {
        address p = First(L);
        while (Next(p) != First(L) && Info(p) != X) p = Next(p);
        if (Info(p) == X) return p;
        else return Nil;
    }
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
    address p = Alokasi(X);
    if (p != Nil) InsertFirst(L, p);
}
void InsVLast (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    address p = Alokasi(X);
    if (p != Nil) InsertLast(L, p);
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype * X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
    address p; DelFirst(L, &p);
    *X = Info(p); Dealokasi(p);
}

void DelVLast (List *L, infotype * X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
    address p; DelLast(L, &p);
    *X = Info(p); Dealokasi(p);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
    if (IsEmpty(*L))
    {
        L->First = P;
        Next(P) = P;
    } 
    else 
    {
        address last = L->First;
        while (Next(last) != L->First) last = Next(last);
        Next(P) = L->First;
        L->First = P;
        Next(last) = P;
    }
}

void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    if (IsEmpty(*L)) InsertFirst(L, P);
    else
    {
        address P1 = First(*L);
        while (Next(P1) != First(*L)){
            P1 = Next(P1);
        }
        Next(P1) = P;
        Next(P) = First(*L);
    }
}
void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    Next(P) = Next(Prec);
    Next(Prec) = P;    
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    if (Next(First(*L)) == First(*L)){
        *P = First(*L);
        Next(*P) = Nil;
        First(*L) = Nil;
    }
    else{
        *P = First(*L);
        address last = First(*L);
        while (Next(last) != First(*L)){
            last = Next(last);
        }
        First(*L) = Next(*P);
        Next(*P) = Nil;
        Next(last) = First(*L);
    }
}

void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
{
    if (Next(First(*L)) == First(*L)){
        *P = First(*L);
        First(*L) = Nil;
        //Next(*P) = Nil;
    }
    else{
        address P1 = First(*L);
        while (Next(Next(P1)) != First(*L)){
            P1 = Next(P1);
        }
        *P = Next(P1);
        Next(P1) = First(*L);
        //Next(*P) = Nil;
    }    
}
void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    if (Next(Prec) == First(*L)){
        DelFirst(L, Pdel);
    }
    else if (Next(Next(Prec)) == First(*L)){
        DelLast(L, Pdel);
    }
    else{
        *Pdel = Next(Prec);
        Next(Prec) = Next(*Pdel);
        Next(*Pdel) = Nil;
    }
}
void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
    address P = Search(*L, X);
    if (P != Nil){
        if (P == First(*L)){
            DelFirst(L, &P);
        }
        else{
            address Prec = First(*L);
            while(Next(Prec) != P){
                Prec = Next(Prec);
            }
            DelAfter(L, &P, Prec);
        }
    }    
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    address P;
    if (IsEmpty(L)) printf("[]");
    else 
    {
        P = First(L);
        do {
            printf("%d, ", Info(P));
            P = Next(P);
        } while (P != First(L));
    }
}