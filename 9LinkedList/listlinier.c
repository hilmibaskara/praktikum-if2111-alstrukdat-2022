/*
	NIM			: 18221072
	Nama		: Hilmi Baskara Radanto
	Tanggal		: 04 November 2022
	Topik		: Pra - Praktikum 9
	Deskripsi	: SOAL 1 - Implementasi listlinier.h
*/

#include "listlinier.h"
#include <stdlib.h>
#include <stdio.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L){
    return (First(L) == Nil);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L){
	First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X){
	address P;
	P = (ElmtList *)malloc(sizeof(ElmtList));
	if (P == NULL) return Nil;
	else {
		Info(P) = X;
		Next(P) = Nil;
		return P;
	}
}

/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void Dealokasi (address *P){
	free(*P);
}

/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X){
	address P = L.First;
	boolean found = false;
		
	while (P != Nil && found == false){
		if (Info(P) != X) P = Next(P);
		else found = true;
	}
	if (found) return P;
	else return Nil;
}

/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X){
	address P = Alokasi(X);
	if (P != Nil){
		Next(P) = First(*L);
		First(*L) = P;
	}
}

/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (List *L, infotype X){
	address P = Alokasi(X);
	if (P != Nil) InsertLast(L, P);
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X){
	address P ;
	DelFirst(L, &P);
	*X = Info(P);
	Dealokasi(&P);
}
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (List *L, infotype *X){
	address P;
	DelLast(L, &P);
	*X = Info(P);
	Dealokasi(&P);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P){
	Next(P) = First(*L);
	First(*L) = P;
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertAfter (List *L, address P, address Prec){
	Next(P) = Next(Prec);
	Next(Prec) = P;
}
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLast (List *L, address P){
	if (IsEmpty(*L)) InsertFirst(L, P);
	else {
		address temp = L->First;
		while (Next(temp) != Nil) {
			temp = Next(temp);
		}
		InsertAfter(L, P, temp);
	}
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P){
	*P = First(*L);
	First(*L) = Next(*P);
}

/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelP (List *L, infotype X){
	address P = Search(*L, X);

	if (P != Nil){
		if (P == First(*L)){
			DelFirst(L, &P);
		}
		else {
			address prev = First(*L);
			while (Next(prev) != P){
				prev = Next(prev);
			}
			DelAfter(L, &P, prev);
		}
	}
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelLast (List *L, address *P){
	address last = First(*L);
	address prev = Nil;

	while (Next(last) != Nil){
		prev = last;
		last = Next(last);
	}

	*P = last;
	if (prev == Nil) First(*L) = Nil; 
	else Next(prev) = Nil;
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
void DelAfter (List *L, address *Pdel, address Prec){
	*Pdel = Next(Prec);
	if (Next(Prec) != Nil){
		Next(Prec) = Next(Next(Prec));
		Next(*Pdel) = Nil;
	}
}
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L){
	if (IsEmpty(L)) printf("[]");
	else
	{
		address P = L.First;

		printf("[");
		while (P != Nil){
			printf("%d", Info(P));
			if (Next(P) != Nil) printf(",");
			P = Next(P);
		}
		printf("]");

	}
}

/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
int NbElmt (List L){
	if (IsEmpty(L)) return 0;
	else
	{
		int ctr = 0;
		address P = First(L);

		while (P != Nil){
			ctr++;
			P = Next(P);
		}

		return ctr;
	}
}

/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype Max (List L){
	if (IsEmpty(L)) return 0;
	else
	{
		address P = First(L);
		infotype max = Info(P);

		while (P != Nil){
			if (Info(P) > max) max = Info(P);
			P = Next(P);
		}

		return max;
	}
}

/* Mengirimkan nilai info(P) yang maksimum */
address AdrMax (List L){
	if (IsEmpty(L)) return 0;
	else
	{
		int maxVal = Max (L);
		return Search(L, maxVal);
	}
}

/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
infotype Min (List L){
	if (IsEmpty(L)) return 0;
	else
	{
		address P = First(L);
		infotype min = Info(P);

		while (P != Nil){
			if (Info(P) < min) min = Info(P);
			P = Next(P);
		}
		
		return min;
	}
}

/* Mengirimkan nilai info(P) yang minimum */
address AdrMin (List L){
	if (IsEmpty(L)) return 0;
	else
	{
		int minVal = Min (L);
		return Search(L, minVal);
	}
}

/* Mengirimkan address P, dengan info(P) yang bernilai minimum */
float Average (List L){
	if (IsEmpty(L)) return 0;
	else
	{
		address P = First(L);
		float sum = 0, ctr = 0;

		while (P != Nil){
			ctr++;
			sum = sum + Info(P);
			P = Next(P);
		}
		
		float avg = sum/ctr;
		return avg;
	}
}

/* Mengirimkan nilai rata-rata info(P) */

/****************** PROSES TERHADAP LIST ******************/

void InversList (List *L){
	address P = First(*L);
	address temp1 = P;
	address temp2 = Next(P);
	
	while (temp2 != Nil) {
		temp1 = temp2;
		temp2 = Next(temp2);
		InsertFirst(L, temp1);
		Next(P) = temp2;
	}
}
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */

void Konkat1 (List *L1, List *L2, List *L3){
	CreateEmpty(L3);
	address lastL1 = First(*L1);

	if (IsEmpty(*L1)){
		First(*L3) = First(*L2);
	} else {
		First(*L3) = First(*L1);
		while (Next(lastL1) != Nil){
			lastL1 = Next(lastL1);
		}
		Next(lastL1) = First(*L2);
	}
	CreateEmpty(L1);
	CreateEmpty(L2);
}
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */