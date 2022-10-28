/*
NIM         : 18221072
Nama        : Hilmi Baskara Radanto
Tanggal     : 19 September 2022
Topik       : Praktikum 3
Deskripsi   : Implementasi fungsi panjangString yang menerima argumen pointer kepada 
              karakter pertama dari sebuah string yang panjangnya tidak diketahui
*/

#include <stdio.h>

char vowel[] = {'a', 'A', 'i', 'I', 'u', 'U', 'e', 'E', 'O', 'o', '\0'};

int isAlphabet(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int isVowel (char c)
{
    char* it = vowel;
    while(*it != '\0')
    {
        if (c == *it)
        {
            return 1;
        }
    it++;
    }
}

void jumlahKonsonanVokal(char* str, int* kons, int* vok)
{
    while (*str != '\0')
    {
        if (isAlphabet(*str))
        {
            if(isVowel(*str))
            {
                (*vok)++;
            } 
            else
            {
                (*kons)++;
            }
        }
        str++;
    }
}