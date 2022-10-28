//Nama : Saul Sayers
//NIM  : 13520094
//Kelas: K02 Alstrukdat
//PRAKTIKUM 5

#include "matrix.h"
#include <stdio.h>

float rowMean (Matrix m, Index i){
    float total=0;
    int j;
    for (j=0; j<COLS(m) ; j++) {
        total += ELMT(m,i,j);
    }
    return total/COLS(m);
}
/* Menghasilkan rata-rata dari elemen pada baris ke-i */
/* Prekondisi: i adalah indeks baris efektif dari M */

float colMean (Matrix m, Index j){
    float total=0;
    int i;
    for (i=0; i<ROWS(m) ; i++) {
        total += ELMT(m,i,j);
    }
    return total/ROWS(m);
}
/* Menghasilkan rata-rata dari elemen pada kolom ke-j */
/* Prekondisi: j adalah indeks kolom efektif dari M */

void rowExtremes (Matrix m, Index i, ElType * max, ElType * min){
    int j;
    *max = ELMT(m,i,0);
    *min = ELMT(m,i,0);
    for (j=1; j< COLS(m);j++) {
        if (ELMT(m,i,j) > *max) {
            *max = ELMT(m,i,j);
        }
        if (ELMT(m,i,j) < *min) {
            *min = ELMT(m,i,j);
        }       
    }
}
/* I.S. i adalah indeks baris efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada baris i dari M
           min berisi elemen minimum pada baris i dari M */

void colExtremes (Matrix m, Index j, ElType * max, ElType * min){
    int i;
    *max = ELMT(m,0,j);
    *min = ELMT(m,0,j);
    for (i=1; i< ROWS(m);i++) {
        if (ELMT(m,i,j) > *max) {
            *max = ELMT(m,i,j);
        }
        if (ELMT(m,i,j) < *min) {
            *min = ELMT(m,i,j);
        }       
    }
}
/* I.S. j adalah indeks kolom efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada kolom j dari M
           min berisi elemen minimum pada kolom j dari M */

int countValOnRow (Matrix m, Index i, ElType val){
    int j ;
    int banyak = 0 ;
    for (j=0; j<COLS(m); j++) {
        if (ELMT(m,i,j) == val){
            banyak += 1;
        }
    }
    return banyak;
}
/* Menghasilkan banyaknya kemunculan X pada baris i dari M */

int countValOnCol (Matrix m, Index j, ElType val){
    int i ;
    int banyak = 0 ;
    for (i=0; i<ROWS(m); i++) {
        if (ELMT(m,i,j) == val){
            banyak += 1;
        }
    }
    return banyak;   
}
/* Menghasilkan banyaknya kemunculan X pada kolom j dari M */

