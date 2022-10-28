// NIM             : 18221072
// Nama            : Hilmi Baskara Radanto
// Tanggal         : 15 Oktober 2022
// Topik praktikum : Praktikum 5
// Deskripsi       : Program Caesar Cipher

#include <stdio.h>
#include "boolean.h"
#include "mesinkarakterv2.h"
#include "mesinkata.h"

int main()
{
	STARTWORD();
	int Nb_first_kata = currentWord.Length, i;
	while (!isEndWord())
	{
		for (i = 0; i < currentWord.Length; i++)
		{
			currentWord.TabWord[i] += Nb_first_kata;
			while (currentWord.TabWord[i] > 'Z')
			{
				currentWord.TabWord[i] -= 26;
			}
			printf("%c", currentWord.TabWord[i]);
		}
		ADVWORD();
		if (!isEndWord() || currentWord.Length == 0)
			printf(" ");
		else
			printf(".");
	}
	printf("\n");
}