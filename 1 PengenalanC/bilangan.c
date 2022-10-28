#include <stdio.h>

int main()
{
    int a;
    scanf("%d", &a);
    if (1 <= a <= 100)
    {
        if (a % 2 == 0 && a != 2) printf("Ya");
        else printf("Tidak");
    }
    printf("\n");
    return 0;
}