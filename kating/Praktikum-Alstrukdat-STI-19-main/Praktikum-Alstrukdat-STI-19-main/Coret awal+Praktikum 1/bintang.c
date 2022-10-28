#include<stdio.h>
int main(){
    int row;
    scanf("%d",&row);
    for (int i=0;i<row;i++){
        for (int j=0;j<row;j++){
            if (j<(row-i)){
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
    for (int i=1;i<row;i++){
        for (int j=0;j<=row;j++){
            if (j<=i){
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("--------------\n");
    for (int i=0;i<row;i++){
        for (int j=0;j<row;j++){
            if (j>=i){
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