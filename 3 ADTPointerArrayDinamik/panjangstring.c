/*
NIM         : 18221072
Nama        : Hilmi Baskara Radanto
Tanggal     : 18 September 2022
Topik       : Pra-Praktikum 3
Deskripsi   : Implementasi fungsi panjangString yang menerima argumen pointer kepada 
              karakter pertama dari sebuah string yang panjangnya tidak diketahui
*/

#include <stdio.h>
#include "panjangstring.h"

int a, p;

int panjangString(char*a)
{
    int p = 0;
    while (*a != '\0')
    {
        p++;
        *a++;
    }
    return p;
}