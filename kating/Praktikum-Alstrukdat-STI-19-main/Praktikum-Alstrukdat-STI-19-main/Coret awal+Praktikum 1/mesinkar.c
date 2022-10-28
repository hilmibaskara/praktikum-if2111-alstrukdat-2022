#include<stdio.h>
#include"mesinkar.h"

char CC;
boolean EOP;

static FILE *pita;
static int retval;

void START(){
    pita=fopen("pitakar.txt","r");
    ADV();
}
void ADV(){
    retval=fscanf(pita,"%c",&CC);
    EOP=(CC==MARK);
    if (EOP){
        fclose(pita);
    }
}