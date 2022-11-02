/*
    NIM         : 18221072
    Nama        : Hilmi Baskara Radanto
    Tanggal     : 23 Oktober 2022
    Topik       : Praktikum 7
    Deskripsi   : Membuat program menghitung pengurangan dua integer besar yang mungkin berdigit 100
*/

#include "stack.h"
#include <stdio.h>
#include <math.h>

int main(){

    // Inisialisasi & deklarasi variabel
    char str1[100], str2[100];
    Stack s1, s2, s; 
    CreateEmpty(&s1), CreateEmpty(&s2), CreateEmpty(&s);
    int i = 0, j = 0, k = 0;
    int temp = 0 , temp1, temp2, res;
    boolean isneg = false, startnull = true;
    
    // Membaca input
    scanf("%s\n%s", str1, str2);
    
    // Memasukkan input ke dalam stack
    while (str1[i] != '\0'){
        Push(&s1, (int)str1[i] - '0');
        i++;
    }

    while (str2[j] != '\0')
	{
		Push(&s2, (int)str2[j] - '0');
		j++;
	}

    if (j > i) isneg = true;
    else if (i == j){
        while (k <= i && !isneg){
            if (str2[k] > str1[k]) isneg = true;
            k++;
        }
    }

    while (!IsEmpty(s1) || !IsEmpty(s2)){
		if (!IsEmpty(s1)) Pop(&s1, &temp1);
		else temp1 = 0;
		if (!IsEmpty(s2)) Pop(&s2, &temp2);
		else temp2 = 0;
		
		if (!isneg) res = temp1 - temp2 - temp;
		else res = temp2 - temp1 - temp;
		if (res < 0) res += 10;
		Push(&s, res);
		if ((temp1 < temp2 && !isneg) || (temp2 < temp1 && isneg))
			temp = 1;
		else if ((temp1 > temp2 && !isneg) || (temp2 > temp1 && isneg))
			temp = 0;        
    }

	if (isneg) printf("-");
	while (!IsEmpty(s))
	{
		Pop(&s, &temp);
		if (startnull && temp != 0) startnull = false;
		if (!startnull) printf("%d", temp);
	}
	if (IsEmpty(s) && startnull) printf("0");
	printf("\n");
}