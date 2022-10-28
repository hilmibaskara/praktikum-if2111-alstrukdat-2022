#include<stdio.h>
int main(){
    float ip,pot;
    scanf("%f",&ip);
    scanf("%f",&pot);
    if (ip<3.5){
        if(pot<1){
            printf("1\n");
        }
        else{
            if (ip<2){
                printf("2\n");
            }
            else{
                printf("3\n");
            }      
        }
    }
    else if(ip>=3.5){
        printf("4\n");
    }
    else{
        printf("0\n");
    }
    return 0;
}