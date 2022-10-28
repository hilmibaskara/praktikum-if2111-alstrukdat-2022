#include <stdio.h>
#include <stdlib.h>

int main(){
    int N;
    scanf("%d", &N);
    int *arr = (int *) malloc (sizeof(int)*N);
    int i;
    for (i = 0; i < N; i++){
        int x;
        scanf("%d", &x);
        arr[i] = x;
    }
    int m;
    scanf("%d", &m);
    while (m--){
        int l, r;
        long result = 0;
        scanf("%d %d", &l, &r);
        for (l; l<= r; l++){
            result += arr[(l-1) % N];
        }
        printf("%d\n", result);
    }
}