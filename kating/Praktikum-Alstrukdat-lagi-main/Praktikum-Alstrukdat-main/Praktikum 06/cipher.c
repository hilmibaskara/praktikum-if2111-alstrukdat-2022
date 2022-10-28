//Nama : Saul Sayers
//NIM  : 13520094
//Kelas: K02 Alstrukdat
//PRAKTIKUM 6

#include <stdio.h>
#include "wordmachine.h"

int main() {
    int panjangkatapertama,k;
    startWord();
    panjangkatapertama = currentWord.length;
    while (!endWord) {
        for (k=0; k<currentWord.length; k++) {
            if (currentWord.contents[k] + panjangkatapertama > 90) {
                printf("%c", (((currentWord.contents[k]+ panjangkatapertama -65) %26) +65)); 
            }
            else {
                printf("%c", (currentWord.contents[k] + panjangkatapertama));
            }
        }
        if (currentChar != MARK) {
            printf(" ");
        }
        advWord();
    }
    printf(".\n");
    return 0;
}