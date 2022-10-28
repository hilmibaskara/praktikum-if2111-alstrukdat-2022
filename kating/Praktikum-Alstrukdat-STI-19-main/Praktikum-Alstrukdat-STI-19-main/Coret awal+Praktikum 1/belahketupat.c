#include<stdio.h>
#include"boolean.h"
int notvalid(int x){
    return x%2==0;
}
int main(){
    int row,pusat,kuncup;
    scanf("%d",&row);
    while(notvalid(row)){
        scanf("%d",&row);
    }
    pusat=(row-1)/2;
    kuncup=pusat-1;
    for(int i=0;i<=pusat;i++){
        for(int j=0;j<row;j++){
            if (j<(pusat-i)||(j>(pusat+i))){
                printf(" ");
            }
            else{
                printf("*");
            }
        }
        printf("\n");
    }
    for(int i=0;i<pusat;i++){
        for (int j=0;j<row;j++){
            if((j<(pusat-(kuncup-i)))||(j>(pusat+(kuncup-i)))){
                printf(" ");
            }
            else{
                printf("*");
            }
        }
        printf("\n");
    }
    printf("------------------------\n");
    for(int i=0;i<=pusat;i++){
        for(int j=0;j<row;j++){
            if (j<(pusat-i)||(j>(pusat+i))){
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
    for(int i=0;i<pusat;i++){
        for (int j=0;j<row;j++){
            if((j<(pusat-(kuncup-i)))||(j>(pusat+(kuncup-i)))){
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}