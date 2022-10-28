#include <stdio.h>

int IsWithinRange(double nilai, double min, double max)
{
    if (nilai >= min && nilai <= max){
        return 1;
    } else {
        return 0;
    }
}

int main()
{
    float ip, average, sum_ip;
    int mahasiswa = 0;
    int lulus = 0;
    int not_lulus = 0;
    int sum = 0;
    int check;
    scanf("%f", &ip);
    while (ip != -999){
        while (IsWithinRange(ip, 0.0, 4.0) == 0) {
            scanf("%f", &ip);
        }
        mahasiswa = mahasiswa + 1;
        sum_ip = sum_ip + ip;
        if (ip >= 2.75)
        {
            lulus += 1;
        } else {
            not_lulus += 1;
        }
        scanf("%f", &ip);
    }
    printf("%d\n", mahasiswa);
    printf("%d\n", lulus);
    printf("%d\n", not_lulus);
    average = sum_ip / mahasiswa;
    printf("%.2f\n", average);
    return 0;
}