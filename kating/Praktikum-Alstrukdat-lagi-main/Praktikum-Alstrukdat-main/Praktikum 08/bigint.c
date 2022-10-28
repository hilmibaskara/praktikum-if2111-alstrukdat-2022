// NAMA  : SAUL SAYERS
// NIM   : 13520094 / 16520075
// KELAS : K02 Alstrukdat
// PRAKTIKUM  8 ADT STACK

#include <stdio.h>
#include "stack.h"

int charkeint(char s){
    int i = s - '0';
    return i;
}

int main() {
    Stack s1,s2,splus ;
    CreateStack(&s1);
    CreateStack(&s2);
    CreateStack(&splus);
    char str[100];
    int i, hasil, sisa=0,val;
    scanf("%s", str); // SCAN STRING PERTAMA
    i = 0;
    while (str[i] != '#') {
        push(&s1,charkeint(str[i]));
        i += 1;
    }
    scanf("%s", str); // SCAN STRING KEDUA
    i = 0;
    while (str[i] != '#') {
        push(&s2,charkeint(str[i]));
        i += 1;
    }
    while (!isEmpty(s1) && !isEmpty(s2)) {
        if (TOP(s1) + TOP(s2) + sisa < 10) {
            hasil = TOP(s1) + TOP(s2) + sisa;
            sisa= 0;
        }
        else{
            hasil = TOP(s1) + TOP(s2) + sisa - 10;
            sisa= 1;
        }
        push(&splus, hasil); 
        pop(&s1,&val);
        pop(&s2,&val);
    }
    if (isEmpty(s1) && isEmpty(s2) && sisa==1){
        push(&splus, sisa);
    }
    while (!isEmpty(s1)) {
        push(&splus, TOP(s1) + sisa);
        sisa = 0;
        pop(&s1, &val);
    }
    while (!isEmpty(s2)) {
        push(&splus, TOP(s2) + sisa);
        sisa = 0;
        pop(&s2,&val);
    }
    while (!isEmpty(splus)) {
        printf("%d", TOP(splus));
        pop(&splus, &val);
    }
    printf("\n");
    return 0;
}