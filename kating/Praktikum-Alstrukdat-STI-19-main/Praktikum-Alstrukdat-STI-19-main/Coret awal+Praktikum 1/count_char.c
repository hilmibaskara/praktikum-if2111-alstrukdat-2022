/*NAMA: MARCELINO FEIHAN
NIM: 18219006
TANGGAL: 01/10/2020
JUDUL: PRAKTIKUM 3
DESKRIPSI: COUNT CHAR 
*/



#include "mesin_kar.h"

/**
 * Menghitung jumlah kemunculan karakter pada suatu pita karakter
 * needle merupakan huruf yang akan dihitung
 * filename merupakan nama file
 * Fungsi mengembalikan jumlah karakter yang muncul pada pita karakter
 */
int count_char(char needle, char *filename) {
    int count = 0;
    START(filename);
    while (!IsEOP()) {
        if (GetCC() == needle) {
            count++;
        }
        ADV();
    }

    return count;
}