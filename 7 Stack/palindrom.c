/*
    NIM         : 18221072
    Nama        : Hilmi Baskara Radanto
    Tanggal     : 23 Oktober 2022
    Topik       : Pra-Praktikum 7
    Deskripsi   : Membuat program yang akan mengecek apakah input dalam bentuk palindrom atau tidak?
*/

#include "stack.h"
#include <stdio.h>

int main(){
    Stack stack;
    int inp;

    CreateEmpty(&stack);
    scanf("%d", &inp);

    if (inp == 0){
        printf("Stack kosong");
    } else {
        while (inp != 0){
            Push(&stack, inp);
            scanf("%d", &inp);
        }

        boolean palindrom = true;
        infotype j = Top(stack);

        for(address i = 0; i <= (Top(stack)/2); i++){
            if ((stack).T[(i)] != (stack).T[(j)]) palindrom = false;
            j--;
        }

        if (palindrom == true) printf("Palindrom");
        else printf("Bukan Palindrom");
    }

    printf("\n");
    return 0;
}