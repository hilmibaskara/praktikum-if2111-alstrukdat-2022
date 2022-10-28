/* Nama    : Saul Sayers */
/* NIM     : 13520094 / 16520075 */
/* Kelas   : K02 */
/* Tanggal : 9 September 2021 */
/* PRAKTIKUM 3 */

#include "listpos.h"
#include <stdio.h>

int main(){
    // Kamus
    ListPos L ;
    int X, indeks ;
    int maks, minim, med ;

    //Algoritma
    readList(&L);
    displayList(L);
    printf("\n");
    scanf("%d", &X);
    if (!(isEmpty(L))){
        indeks = indexOf(L,X);
        if (indeks == IDX_UNDEF) {
            printf("%d tidak ada\n", X) ;
        }
        else {
            printf("%d\n", indeks) ;
        }
        extremes(L,&maks,&minim);
        if (X==maks) {
            printf("maksimum\n");
        }
        if (X==minim) {
            printf("minimum\n");
        }
        sort(&L, true);
        if (length(L) % 2 == 0 ) {
            med = ELMT(L, length(L)/2 -1);
        }
        else {
            med = ELMT(L, length(L)/2);
        }
        if (X==med) {
            printf("median\n");
        }
    }
    else {
        printf("%d tidak ada\n", X);
    }
    return 0;
}

