#include <stdio.h>

int main(){
    int n, i, max, min;
    int arr[n];
    printf("Input number of elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        printf("Input elemen ke %d: ", i);
        scanf("%d", &arr[i]);
    }
    max = arr[0];
    min = arr[0];
    // mencari max
    for (i = 1; i < n; i++){
        if (arr[i] > max){max = arr[i];}
        ;
    }
    for (i = 1; i < n; i++){
        if (arr[i] < min){min = arr[i];}
    }
    printf("%d %d", max, min);
    return 0;
}