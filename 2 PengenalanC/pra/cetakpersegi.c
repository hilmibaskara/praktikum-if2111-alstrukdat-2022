#include <stdio.h>

int main(){
    int num;
    scanf("%d", &num);
    int i = 0;
    
    for (i; i<2*num-1; i++){
        int j = 0;
        for (j; j<2*num-1; j++){
            if((i+j) % 2 == 0){
                    printf("O");
            } else {
                printf("X");
            }
        }
        printf("\n");
    }
    return 0;
}