/*
	NIM			: 18221072
	Nama		: Hilmi Baskara Radanto
	Tanggal		: 04 November 2022
	Topik		: Pra - Praktikum 9
	Deskripsi	: SOAL 2 - Program menghitung nilai mata kuliah
*/

#include "listlinier.h"
#include <stdio.h>

int main()
{
    List L; CreateEmpty(&L);
    int nilai;

    scanf("%d", &nilai);
    while (nilai >= 0 && nilai <= 100)
    {
        InsVFirst(&L, nilai);
        scanf("%d", &nilai);   
    }

    if (IsEmpty(L)) printf("Daftar nilai kosong\n");
    else {
        printf("%d\n", NbElmt(L));
        printf("%d\n", Max(L));
        printf("%d\n", Min(L));
        printf("%.2f\n", Average(L));
        InversList(&L);
        PrintInfo(L); printf("\n");
        InversList(&L);
        PrintInfo(L); printf("\n");
    }
    return 0;
}
