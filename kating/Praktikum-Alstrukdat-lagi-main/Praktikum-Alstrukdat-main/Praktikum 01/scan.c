// NAMA      : Saul Sayers
// NIM       : 13520094
// Tanggal   : 
// Topik     : Testing input
// Deskripsi : Uji coba pertama bahasa C

#include <stdio.h>

int main() 
{
    char kata[10] ;
    char huruf;
    int angka ;
    scanf("%s", &kata);
    scanf(" %c", &huruf);
    scanf("%d", &angka);
    printf("%s %c %d", kata, huruf, angka);
    return 0;
}