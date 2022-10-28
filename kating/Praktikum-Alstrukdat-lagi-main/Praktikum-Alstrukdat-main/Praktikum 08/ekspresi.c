// NAMA  : SAUL SAYERS
// NIM   : 13520094 / 16520075
// KELAS : K02 Alstrukdat
// PRAKTIKUM  8 ADT STACK

#include <stdio.h>
#include "stack.h"
#include <math.h>
#include "tokenmachine.h"

int charkeint(char s){
    int i = s - '0';
    return i;
}

int hitung(int a, int b, char c) {
    int hasil ;
    if (c =='+'){
        hasil = a+b;
    }
    if (c =='-'){
        hasil = a-b;
    }
    if (c =='*'){
        hasil = a*b;
    }
    if (c =='/'){
        hasil = a/b;
    }
    if (c =='^'){
        hasil = pow(a,b);
    }
}

int main() {
    Stack s ;
    int bil1, bil2, hasil;
    CreateStack(&s);
    startToken();
    if (endToken) {
        printf("Ekspresi kosong\n");
    }
    else {
        while (!endToken) {
            if (currentToken.tkn != '+' && currentToken.tkn != '-' && currentToken.tkn != '*' && currentToken.tkn != '/' && currentToken.tkn != '^') {
                printf("%d\n", currentToken.val);
                push(&s, currentToken.val);
            }
            else{
                pop(&s, &bil2);
                pop(&s, &bil1);
                printf("%d %c %d\n",bil1,currentToken.tkn,bil2);
                hasil = hitung(bil1,bil2,currentToken.tkn);
                printf("%d\n", hasil);
                push(&s,hasil);
            }
            advToken();
        }
        pop(&s,&bil1);
        printf("Hasil=%d\n",bil1);
    }
    return 0;
}