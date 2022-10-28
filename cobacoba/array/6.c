#include <stdio.h>

int main()
{
    int n, i, j, check;
    int k = 0;
    int arr[n], unique[n-1];
    printf("Input number of elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        printf("Input elemen ke %d: ", i);
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < n-1; i++){
        for (j = 1; j < n; j++){
            if (arr[i] == arr[j]){
                check = 0;
                break;
            }
        }
        if (check = 1){
        unique[k] = arr[i];
        }
    }
    printf("unique numbers are: ");
    for (k = 0; k < n-1; k++){
        printf("%d ", unique[k]);
    }
    return 0;
}