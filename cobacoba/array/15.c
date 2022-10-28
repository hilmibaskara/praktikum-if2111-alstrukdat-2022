#include <stdio.h>

int main(){
    int a;
    printf("Input the size of array: ");
    scanf("%d", &a);
    int arr[a];
    int i = 0;
    printf("Input 5 elements in the array in ascending order: ");
    while (i < a){
        printf("Input 5 elements in the array in ascending order\nelement - %d: ", arr[i]);
        scanf("%d", &arr[i]);
    }
    
}