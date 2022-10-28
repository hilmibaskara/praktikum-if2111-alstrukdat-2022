// NAMA      : Saul Sayers
// NIM       : 13520094
// Tanggal   : 25 November 2021
// Topik     : merkle
// Deskripsi : Implementasi Binary Tree dalam bahasa C

#include <stdio.h>
#include "bintree.c"
#include <stdlib.h>

void makeMerkel(BinTree* p, int level) 
{
    int elemen ;
    BinTree sementara = newTreeNode(0);
    BinTree sementara2 = newTreeNode(0);
    if (level != 0)
    {
        LEFT(*p) = sementara;
        RIGHT(*p) = sementara2;
        makeMerkel(&LEFT(*p), level -1);
        makeMerkel(&RIGHT(*p), level -1);
        ROOT(*p) = ROOT(LEFT(*p)) + ROOT(RIGHT(*p));
    }
    else
    {
        scanf("%d", &elemen);
        ROOT(*p) = elemen;
    }
}

int main()
{
    BinTree merkel = NewTree(0,NULL,NULL); 
	int N,pangkat = 0;
    long long hasilpangkat=1;
	scanf("%d", &N);
	while (hasilpangkat < N)
	{
		pangkat = pangkat + 1;
        hasilpangkat = 2*hasilpangkat;
	}
	if (hasilpangkat == N)
    {
        makeMerkel(&merkel, pangkat);
		printTree(merkel, 2);
    }
	else
	{
        printf("Jumlah masukan tidak sesuai\n");
	}
	return 0;
}