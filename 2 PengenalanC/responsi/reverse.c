/*
NIM         : 18221072
Nama        : Hilmi Baskara Radanto
Tanggal     : 17 September 2022
Topik       : Responsi Praktikum 2
Deskripsi   : Soal 4. Program menerima satu bilangan integer positif 
              dan memberi output integer yang tiap digitnya dibalik
*/

# include <stdio.h>


int main()
{
    int n, t, remainder;
    scanf("%d", &n);
    if (n < 10){
        printf("%d", n);
    }
    else if (n >= 10)
    {
        while (n >= 10)
        {
            remainder = n % 10;
            printf("%d", remainder);
            t         = n;
            n         = n / 10;
        }
        printf("%d", t/10);
    }
    printf("\n");
    return 0;
}