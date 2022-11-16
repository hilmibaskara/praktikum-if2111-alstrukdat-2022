/*
	NIM			: 18221072
	Nama		: Hilmi Baskara Radanto
	TAnggal		: 14 NOvember 2022
	TOpik		: Praktikum terakhir (10)
	Deskripsi	: Soal 2 - Implementasi linkdummy.h
*/

#include "linkdummy.h"
#include <stdio.h>
#include <stdlib.h>

/* Definisi list: */
/* List kosong: First(L) = Last(L) = dummy@ */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
/* Elemen dummy terletak pada last */

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty(List L){
	return (First(L) == Last(L));
}
/* Mengirim true jika list kosong: First(L) = dummy@
dan Last(L) = dummy@ */

/****************** PEMBUATAN LIST KOSONG ******************/
void MakeEmpty(List *L){
	address p;
	p = Alokasi(0);
	if (p != Nil)
	{
		L->First = p;
		L->Last = p;
	}
	else
	{
		L->First = Nil;
		L->Last = Nil;
	}
}
/* I.S. sembarang */
/* F.S. Terbentuk list L kosong, dengan satu elemen dummy */
/* Jika gagal maka First = Last = Nil dan list gagal terbentuk */

/****************** MANAJEMEN MEMORI ******************/
address Alokasi (ElType X){
    address P;
    P = (address) malloc(sizeof(Node));
    if (P != Nil) {
        Info(P) = X;
        Next(P) = Nil;
    }
    return P;
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */

void Dealokasi (address P){
	free(P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** SEARCHING ******************/
address Search(List L, ElType X){
    // address P = First(L);
    // boolean found = false;
    //  while(P != Nil && !found){
    //     if(Info(P) == X) found = true;
    //     else P = Next(P);
    // }
    // if (found) return P;
    // else return Nil;
	// address p = First(L);
	// address p_found;
	// boolean found = false;
	// while (p != Last(L) && !found)
	// {
	// 	if (Info(p) == X){
	// 		found = true;
	// 		p_found = p;
	// 	}
	// 	p = Next(p);
	// }
	// return p_found;
	address p = First(L);
	Info(Last(L)) = X;
	while (Info(p) != X)
	{
		p = Next(p);
	}
	if (p == Last(L)) return Nil;
	else return p;
}
/* Mencari apakah ada node list dengan info(P) = X */
/* Jika ada, mengirimkan address node tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsertFirst(List *L, ElType X){
	address p = Alokasi(X);
	if (p != Nil){
		Next(p) = First(*L);
		First(*L) = p;
	}
}
/* I.S. List L terdefinisi */
/* F.S. Menambahkan elemen X sebagai elemen pertama List L */
void InsertLast(List *L, ElType X){
	address p, last;

	if (IsEmpty(*L)) InsertFirst(L, X);
	else
	{
		p = Alokasi(X);
		if (p != Nil){
			last = First(*L);
			while (Next(last) != Last(*L)) last = Next(last);
			Next(last) = p;
			Next(p) = Last(*L);
		}
	}
}
/* I.S. List L terdefinisi */
/* F.S. X ditambahkan sebagai elemen terakhir yang baru, */
/* yaitu menjadi elemen sebelum elemen dummy */
/* Alamat elemen dummy tidak berubah */

/*** PENGHAPUSAN ELEMEN ***/
void DeleteFirst(List *L, ElType *X){
	address p = L->First;
	*X = Info(p);
	L->First = Next(L->First);
	free(p);
}
/* I.S. List tidak kosong */
/* F.S. X adalah elemen pertama list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DeleteLast(List *L, ElType *X){
	address last;
	address preclast;
	last = L->First; preclast = Nil;
	while (Next(last) != Last(*L)){
		preclast = last; last = Next(last);
	}
	*X = Info(last);
	if (preclast == Nil) L->First = L->Last;
	else Next(preclast) = L->Last;
	free(last);
}
/* I.S. List tidak kosong */
/* F.S. X adalah terakhir sebelum dummy pada list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */