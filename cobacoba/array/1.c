#include <stdio.h>

int main(){
    int arr[10];
    int i;
    for (i = 0; i < 10; i++){
        printf("Input elemen ke %d: ", i);
        scanf("%d", &arr[i]);
    }
    printf("Elements in array are:");
    for (i = 0; i < 10; i ++){
        printf(" %d", arr[i]);
    }
    return 0;
}