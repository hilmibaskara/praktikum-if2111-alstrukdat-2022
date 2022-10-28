#include <stdio.h>

int main()
{
    int detik;
    scanf("%d", &detik);
    printf("%d detik = %d jam %d menit %d detik\n", detik, detik / 3600, detik / 60 % 60, detik % 60);
    return 0;
}