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
    int i = 0 ;
    boolean asc = true ;
    boolean dsc = true ;

    //Algoritma
    readList(&L);
    while ((i<length(L)-1) && (asc || dsc)) {
        if (ELMT(L,i) > ELMT(L,i+1)) {
            asc = false;
        }
        if (ELMT(L,i) < ELMT(L,i+1)) {
            dsc = false;
        }
        i++ ;
    }
    if (asc == true && dsc == false) {
        printf("Non-descending Monotonic List\n");
    }
    else if (asc == false && dsc == true) {
        printf("Non-ascending Monotonic List\n");
    }
    else if (asc == true && dsc == true) {
        printf("Static Monotonic List\n");
    }
    else {
        printf("Non-monotonic List\n");
    }
    return 0;
}
