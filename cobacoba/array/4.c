#include <stdio.h>

int main()
{
    int n, i;
    int arr[n], arr2[n];
    printf("Input number of elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        printf("Input elemen ke %d: ", i);
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < n; i++){
        arr2[i] = arr[i];
    }
    return 0;
}