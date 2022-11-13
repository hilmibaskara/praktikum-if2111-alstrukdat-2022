/*
	NIM			: 18221072
	Nama		: Hilmi Baskara Radanto
	TAnggal		: 07 NOvember 2022
	Topik		: Praktikum 9 - List Linear
	Deskripsi	: SOAL 3 - IMplementasi removeDuplicate.h
*/

#include "removeDuplicate.h"

List removeDuplicate(List l){

	address P = First(l);
	List temp; CreateEmpty(&temp);

	InsVFirst(&temp, Info(P));
	P = Next(P);
	address Q = temp.First;
	while (P != NULL){
		if ((Info(P)) != Info(Q)) {
			InsVLast(&temp, Info(P));
			Q = Next(Q);
		} else { // info p = info temp
			P = Next(P);
		}
	}

	l.First  = temp.First;
	return l;
}
