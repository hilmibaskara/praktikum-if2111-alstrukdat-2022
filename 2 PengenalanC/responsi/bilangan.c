/*
NIM         : 18221072
Nama        : Hilmi Baskara Radanto
Tanggal     : 17 September 2022
Topik       : Responsi Praktikum 2
Deskripsi   : Soal 6. Menghitung banyaknya bilangan cantik dari test case.
*/

#include <stdio.h>
#include <stdbool.h>

bool cekTujuh(int x)
{
    while (x > 0)
    {
        if (x % 10 == 7)
            break;
 
        x = x / 10;
    }
 
    return (x > 0);
}

int main(){
    int N;
    scanf("%d", &N);

    int i,j;
    for (i = 1; i <= N; i++){
        int sum, M;
        scanf("%d", &M);
        sum = 0;
        for (j = 1; j <= M; j++){
            if (cekTujuh(j) || j % 7 == 0){
                sum += j;
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}


