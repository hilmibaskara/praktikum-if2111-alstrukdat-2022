/*
NIM         : 18221072
Nama        : Hilmi Baskara Radanto
Tanggal     : 03 Oktober 2022
Topik       : Pra-praktikum 5
Deskripsi   : Membuat fungsi hitungkarakter yang dapat menghitung junmlah kemunculan karakter pada suatu pita karakter dari stdin
*/

#include <stdio.h>
#include "mesinkarakter.h"

int hitungkarakter(char karakter){
    START();
    int count = 0;
    while (!IsEOP()){
        if (GetCC() == karakter){
            count += 1;
        }
    ADV();
    }
    return count;
}