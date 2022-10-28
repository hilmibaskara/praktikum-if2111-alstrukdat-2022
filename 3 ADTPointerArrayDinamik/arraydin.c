/*
NIM         : 18221072
Nama        : Hilmi Baskara Radanto
Tanggal     : 19 September 2022
Topik       : Praktikum 3
Deskripsi   : Implementasi arraydin.h
*/

#include <stdio.h>
#include "arraydin.h"
#include <stdlib.h>

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ArrayDin kosong dengan ukuran InitialSize
 */
ArrayDin MakeArrayDin()
{
	ArrayDin A;
	A.A = (ElType *)malloc(sizeof(ElType) * InitialSize);
	A.Capacity = InitialSize;
	A.Neff = 0;
	return A;
}

void DeallocateArrayDin(ArrayDin *array)
{
	free((*array).A);
}

boolean IsEmpty(ArrayDin array)
{
	return array.Neff == 0;
}

int Length(ArrayDin array)
{
	return array.Neff;
}

ElType Get(ArrayDin array, IdxType i)
{
	return array.A[i];
}

int GetCapacity(ArrayDin array)
{
	return array.Capacity;
}

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void InsertAt(ArrayDin *array, ElType el, IdxType i){
	int j;
	if (Length(*array) == GetCapacity(*array))
	{
		ElType *temp = (ElType *)malloc(sizeof(ElType) * GetCapacity(*array));
		for (j = 0; j < Length(*array); j++)
		{
			temp[j] = (*array).A[j];
		}
		DeallocateArrayDin(array);
		(*array).Capacity *= 2;
		(*array).A = (ElType *)malloc(sizeof(ElType) * GetCapacity(*array));
		for (j = 0; j < Length(*array); j++)
		{
			(*array).A[j] = temp[j];
		}
		free(temp);
	}
	for (j = Length(*array); j > i; j--)
	{
		(*array).A[j] = (*array).A[j - 1];
	}
	(*array).A[i] = el;
	(*array).Neff++;
}

/**
 * Fungsi untuk menambahkan elemen baru di akhir array.
 * Prekondisi: array terdefinisi
 */
void InsertLast(ArrayDin *array, ElType el){
	int i;
	if (Length(*array) == GetCapacity(*array))
	{
		ElType *temp = (ElType *)malloc(sizeof(ElType) * GetCapacity(*array));
		for (i = 0; i < Length(*array); i++)
		{
			temp[i] = (*array).A[i];
		}
		DeallocateArrayDin(array);
		(*array).Capacity *= 2;
		(*array).A = (ElType *)malloc(sizeof(ElType) * GetCapacity(*array));
		for (i = 0; i < Length(*array); i++)
		{
			(*array).A[i] = temp[i];
		}
		free(temp);
	}
	(*array).A[Length(*array)] = el;
	(*array).Neff++;
}

/**
 * Fungsi untuk menambahkan elemen baru di awal array.
 * Prekondisi: array terdefinisi
 */
void InsertFirst(ArrayDin *array, ElType el){
	int i;
	if (Length(*array) == GetCapacity(*array))
	{
		ElType *temp = (ElType *)malloc(sizeof(ElType) * GetCapacity(*array));
		for (i = 0; i < Length(*array); i++)
		{
			temp[i] = (*array).A[i];
		}
		DeallocateArrayDin(array);
		(*array).Capacity *= 2;
		(*array).A = (ElType *)malloc(sizeof(ElType) * GetCapacity(*array));
		for (i = 0; i < Length(*array); i++)
		{
			(*array).A[i] = temp[i];
		}
		free(temp);
	}
	for (i = Length(*array); i > 0; i--)
	{
		(*array).A[i] = (*array).A[i - 1];
	}
	(*array).A[0] = el;
	(*array).Neff++;
}

/**
 * Fungsi untuk menghapus elemen di index ke-i ArrayDin
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteAt(ArrayDin *array, IdxType i){
    int length = Length(*array);
    for (int a = i; a < length - 1;a++){
        array -> A[a] = array->A[a + 1];
    }
    array -> Neff--;
}

/**
 * Fungsi untuk menghapus elemen terakhir ArrayDin
 * Prekondisi: array tidak kosong
 */
void DeleteLast(ArrayDin *array){
    int deleteAt = Length(*array) -1;
    DeleteAt(array,deleteAt);
}

/**
 * Fungsi untuk menghapus elemen pertama ArrayDin
 * Prekondisi: array tidak kosong
 */
void DeleteFirst(ArrayDin *array){
    DeleteAt(array,0);
}

/**
 * Fungsi untuk melakukan print suatu ArrayDin.
 * Print dilakukan dengan format: [elemen-1, elemen-2, ..., elemen-n]
 * dan diakhiri newline.
 * Prekondisi: array terdefinisi
 */
void PrintArrayDin(ArrayDin array){
	int i;
	printf("[");
	if (Length(array) > 0)
	{
		for (i = 0; i < Length(array); i++)
		{
			printf("%d", array.A[i]);
			if (i < Length(array) - 1) printf(", ");
		}
	}
	printf("]\n");
}

/**
 * Fungsi untuk melakukan reverse suatu ArrayDin.
 * Prekondisi: array terdefinisi
 */
void ReverseArrayDin(ArrayDin *array){
	int i;
	ElType *temp = (ElType *)malloc(sizeof(ElType) * Length(*array));
	for (i = 0; i < Length(*array); i++)
	{
		temp[i] = (*array).A[i];
	}
	for (i = Length(*array) - 1; i >= 0; i--)
	{
		(*array).A[i] = temp[Length(*array) - i - 1];
	}
	free(temp);
}

/**
 * Fungsi untuk melakukan copy suatu ArrayDin.
 * Prekondisi: array terdefinisi
 */
ArrayDin CopyArrayDin(ArrayDin array){
    int i;
	ArrayDin temp;
	temp.A = (ElType *)malloc(sizeof(ElType) * GetCapacity(array));
	temp.Neff = Length(array);
	temp.Capacity = GetCapacity(array);
	for (i = 0; i < Length(array); i++)
	{
		temp.A[i] = array.A[i];
	}
	return temp;
}

/**
 * Fungsi untuk melakukan search suatu ArrayDin.
 * Index pertama yang ditemukan akan dikembalikan.
 * Jika tidak ditemukan, akan mengembalikan -1.
 * Prekondisi: array terdefinisi
 */
IdxType SearchArrayDin(ArrayDin array, ElType el){
    int i;
	for (i = 0; i < Length(array); i++)
	{
		if (array.A[i] == el) return i;
	}
	return -1;
}