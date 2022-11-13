/*
	NIM			: 18221072
	Nama		: Hilmi Baskara Radanto
	TAnggal		: 07 NOvember 2022
	Topik		: Praktikum 9 - List Linear
	Deskripsi	: SOAL 1 - 
*/


#include "listlinier.h"
#include <stdio.h>

int main(){
	List l; CreateEmpty(&l);
	infotype N, Q;
	address P;

	scanf("%d", &N);
	scanf("%d", &Q);

	int num[Q];
	for (int i = 1; i <= N; i++){
		InsVLast(&l, i);
	}

	for (int i = 0; i < Q; i++){
		scanf("%d", &num[i]);
	}

	for (int i = 0; i < Q; i++){
		// kalo gaada di list
		if (Search(l, num[i]) == Nil){
			printf("miss ");

			InsVFirst(&l, num[i]);
			DelLast(&l, &P);

			PrintInfo(l);
			printf("\n");
		} else { // kalo ada di list
			printf("hit ");

			DelP(&l, num[i]);
			InsVFirst(&l, num[i]);
			PrintInfo(l);
			printf("\n");
		}
	}

	return 0;
}