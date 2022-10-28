#include<stdio.h>
int main(){
    int suhu;
    char faktor;
    scanf("%d\n",&suhu);
    scanf(" %c",&faktor);
    if (faktor=='R'){
        printf("%.2lf\n",0.8 * suhu);
    }
    else if (faktor=='F'){
        printf("%.2lf\n",(1.8*suhu)+32);
    }
    else{
        printf("%.2lf\n",273.15+suhu);
    }
    return 0;
}