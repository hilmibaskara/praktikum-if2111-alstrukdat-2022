/*
	NIM			: 18221072
	Nama		: Hilmi Baskara Radanto
	Tanggal		: 04 November 2022
	Topik		: Pra - Praktikum 9
	Deskripsi	: SOAL 3 - Implementasi OddEvenList.h
*/

#include "OddEvenList.h"

void sortToBig(List *L){
    address P = First(*L);
    while (P != Nil)
    {
        address Q = Next(P);
        while (Q != Nil)
        {
            if (Info(P)>Info(Q)){
                int temp;
                temp = Info(P);
                Info(P) = Info(Q);
                Info(Q) = temp;
            }
            Q = Next(Q);
        }
        P = Next(P);
    }
}

void sortToSmall(List *L){
    address P = First(*L);
    while (P != Nil)
    {
        address Q = Next(P);
        while (Q != Nil)
        {
            if (Info(P)>Info(Q)){
                int temp;
                temp = Info(P);
                Info(P) = Info(Q);
                Info(Q) = temp;
            }
            Q = Next(Q);
        }
        P = Next(P);
    }  
} 


void OddEvenList(List L, List *Odd, List *Even){
    CreateEmpty(Odd);
    CreateEmpty(Even);
    address P;
    P = First(L);
    while (P != Nil){
        if (Info(P)%2 == 0) InsVFirst(Even, Info(P));
        else InsVFirst(Odd, Info(P));
        P = Next(P);
    }

    sortToBig(Even);
    sortToSmall(Odd);
}


    /* Memisahkan elemen ganjil dan genap dari list L kedalam dua list baru secara mengurut membesar*/
    /* I.S: List L TIDAK mungkin kosong dan memiliki nilai lebih dari sama dengan 0(value>=0), List Odd dan Even kosong*/
    /* F.S: List Odd memiliki elemen bernilai ganjil mengurut membesar, List Even memiliki elemen bernilai genap mengurut membesar
            List L TIDAK PERLU DIDEALOKASI*/
    /*Contoh:
        Input:
            L: [0,3,1,4,5]
            Odd: []
            Even: []
        Output:
            L: [0,3,1,4,5]
            Odd: [1,3,5]
            Even: [0,4] */
    /*Note: 
        1. Bilangan 0 merupakan bilangan genap
        2. Buatlah List Odd dan Even terlebih dahulu*/