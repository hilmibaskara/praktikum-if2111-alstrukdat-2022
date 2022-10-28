#include <stdio.h>

int main()
{
    int b;
    int* a = &b;
    b = 5;
    printf("%d", &b);
    return 0;
}