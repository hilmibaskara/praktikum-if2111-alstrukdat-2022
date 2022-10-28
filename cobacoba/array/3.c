#include <stdio.h>

int main(){
    int n;
    printf("Input number of elements: ");
    scanf("%d", &n);
    int arr[n];
    int i;
    int sum = 0;
    for (i = 0; i < n; i++){
        printf("Input elemen ke %d: ", i);
        scanf("%d", &arr[i]);
    }
    
    for (i = 0; i < n; i ++){
        sum = arr[i] + sum;
    }
    printf("Sum of elements in array are: %d", sum);
    return 0;
}