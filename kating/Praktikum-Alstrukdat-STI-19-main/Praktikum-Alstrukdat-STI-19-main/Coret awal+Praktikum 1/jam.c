#include "jam.h"
#include<stdio.h>
Jam MakeJam(int H,int M,int S){
    Jam J1;
    Hour(J1)=H;
    Minute(J1)=M;
    Second(J1)=S;
    return J1;
}
boolean IsJValid(int H,int M,int S){
    return ((H>=0&&H<=23)&&(M>=0&&M<=59)&&(S>=0&&S<=59));
}
void BacaJam(Jam *J){
    int H,M,S;
    do{
        printf("Masukkan jam: ");
        scanf("%d",&H);
        printf("Masukkan menit: ");
        scanf("%d",&M);
        printf("Masukkan detik: ");
        scanf("%d",&S);
    }while(!IsJValid(H,M,S));
    *J=MakeJam(H,M,S);
}
void TulisJam(Jam J){
    printf("%d:%d:%d",Hour(J),Minute(J),Second(J));
}
int JamToDetik(Jam J){
    return (3600*Hour(J)+60*Minute(J)+Second(J));
}
Jam DetikToJam(int N){
    int sisa;
    Jam JOut;
    N=N%86400;
    Hour(JOut)=N/3600;
    sisa=N%3600;
    Minute(JOut)=sisa/60;
    Second(JOut)=sisa%60;
    return JOut;
}
