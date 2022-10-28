#include <stdio.h>

int main(){
    int arr[3];
    int i, j, k;
    for (i = 0; i < 3; i++){
        printf("Input elemen ke %d: ", i);
        scanf("%d", &arr[i]);
    };
    printf("The values store in array are:");
    for (j = 0; j < 3; j++){
        printf(" %d", arr[j]);
    };
    printf("\nThe values store in reverse array are:");
    for (k = 2; k > -1; k--){
        printf(" %d", arr[k]);
    };
    return 0;
}