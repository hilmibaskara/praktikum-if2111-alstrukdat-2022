#include<stdio.h>
#include"mesinkata1.h"

boolean EndKata;
Kata CKata;

void IgnoreBlank(){
    while(CC==BLANK){
        ADV();
    }
}
void STARTKATA(){
    START();
    IgnoreBlank();
    if (CC==MARK){
        EndKata=true;
    }
    else{
        EndKata=false;
        SalinKata();
    }
}
void ADVKATA(){
    IgnoreBlank();
    if (CC==MARK){
        EndKata=true;
    }
    else{
        EndKata=false;
        SalinKata();
    }
}
void SalinKata(){
    int i=0;
    while(CC!=MARK&&CC!=BLANK){
        CKata.TabKata[i]=CC;
        i+=1;
        ADV();
    }
    CKata.length=i;
}