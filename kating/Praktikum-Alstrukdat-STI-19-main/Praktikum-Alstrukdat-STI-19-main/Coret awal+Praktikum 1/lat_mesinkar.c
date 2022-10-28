#include<stdio.h>
#include"lat_mesikar.h"
char cc;
boolean eop;

static FILE *pita;
static int retval;
void start(){
    pita=fopen("latihan.txt","r");
    adv();
}
void adv(){
    retval=fscanf(pita,"%c",&cc);
    eop=(cc==mark);
    if (eop){
        fclose(pita);
    }
}