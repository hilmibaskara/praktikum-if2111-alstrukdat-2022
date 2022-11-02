/*
	NIM			: 18221072
	Nama		: Hilmi Baskara Radanto
	Tanggal		: 31 Oktober 2022
	Topik		: Praktikum 8
	Deskripsi	: SOAL 1 - Implementasi duplicate.h
*/

#include "duplicate.h"

/*
    Masukkan semua elemen array arr ke suatu Set, kemudian kembalikan Set tersebut
        Contoh:
            arrToSet
                <- arr = [1, 1, 3]
                <- arrSize = 3
            -> [1, 3]
*/
Set arrToSet(int* arr, int arrSize){
	Set S;
	CreateEmpty(&S);

	for (int i = 0; i < arrSize; i++){
		Insert(&S, arr[i]);
	}

	return S;
}

/*
    Dengan memanfaatkan fungsi arrToSet, hapuslah elemen duplikat pada array arr
    kemudian kembalikan isinya secara menurun

    Penjelasan Parameter:n 
    Parameter 1: arr, merupakan array masukan yang perlu dihapus elemen duplikatnya
    Parameter 2: arrSize, merupakan panjang arr
    Parameter 3: arrRes, merupakan array keluaran, hasil pengapusan elemen duplikat
        dan elemen-elemennya terurut menurun
    Parameter 4: arrResSize, merupakan panjang arrRes

    Contoh: 
        removeDuplicate
            <- arr = [1, 1, 2, 3]
            <- arrSize = 4
            -> arrRes = [3, 2, 1]
            -> arrResSize = 3
        removeDuplicate
            <- arr = [3, 1, 1]
            <- arrSize = 3
            -> arrRes = [3, 1]
            -> arrResSize = 2
*/
void removeDuplicateDesc(int* arr, int arrSize, int* arrRes, int* arrResSize){
	Set S;
	S = arrToSet(arr, arrSize);
	int len_set = S.Count;
	*arrResSize = len_set;

	int max;
	for (int i = 0; i < len_set; i++){
		max = S.Elements[0];
		for (int j = 0; j < S.Count; j++){
			if (S.Elements[j] > max){
				max = S.Elements[j];
			}
		}
		arrRes[i] = max;
		Delete(&S, max);
	}
}