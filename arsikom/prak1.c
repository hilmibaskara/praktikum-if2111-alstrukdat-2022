#include <stdlib.h>
#include <stdio.h>

int gura (int x, int y){
    return ~(~x & ~y);
}

unsigned int subtract (int x, int y){
    return x + (~y + 1);
}

unsigned int kobokan(int x, int n){
    return x & ((1<<n) + ~0);
}

int yamada(int x){
    int a, b, c, d;
    a = 135 + ~x;
    b = 183 + ~x;
    c = a >> 31;
    d = b >> 31;
    return c & !d;
}

int fauna(int x, int n){
    int a, b, c, d;
    a = x >> 24;
    b = x << 8 >> 16;
    c = x << 16 >> 8;
    d = x << 24;
    return a | b | c | d;
}

int main(){
    int x, y;
    scanf("%d", &x);
    scanf("%d", &y);
    printf("%d", fauna(x,y));
    // printf("%d", yamada(x));
    return 0;
}