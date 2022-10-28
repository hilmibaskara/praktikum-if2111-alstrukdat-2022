#include<stdio.h>
#include "lat_mesinkar.h"
#include "lat_mesinkar.c"

int main(){
    start();
    char rn,next;
    while (!eop){
        rn=cc;
        adv();
        next=cc;
        adv();
        if ((cc=='+')||(cc=='-')||(cc=='*')||(cc=='/')||(cc=='^')){
            printf("%c %c %c\n",rn,cc,next);
        }
        adv();
    }
    return 0;
}