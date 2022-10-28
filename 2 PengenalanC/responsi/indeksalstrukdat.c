// NIM             : 18221072
// Nama            : Hilmi Baskara Radanto
// Tanggal         : 17 September 2022
// Topik praktikum : Responsi Praktikum 2
// Deskripsi       : Program cari banyak jumlah siswa lulus, indexex rata-rata, serta indexex akhir kelas

#include <stdio.h>

int main(){
    float ip,sum = 0;

    int count = 0, lulus = 0;
    while(ip != -999){
        scanf("%f", &ip);
        if(ip == -999) break;

        if(ip < 0 || ip > 4 ) continue;

        sum = sum + ip;
        count = count + 1;

        if(ip >= 3.0){
            lulus = lulus + 1;
        };

    }

    if (count == 0) {
        printf("Tidak ada data\n");
    } else {
        char index;
        float avg = sum / count;
        printf("Jumlah mahasiswa yang lulus = %d\n", lulus);
        printf("Nilai rata-rata = %.2f\n", avg);

        if (avg == 4.00) index = 'A';
        else if (avg >= 3.00 && avg < 4.00) index = 'B';
        else if (avg >= 2.00 && avg < 3.00) index = 'C';
        else if (avg >= 1.00 && avg < 2.00) index = 'D';
        else if (avg >= 0.00 && avg < 1.00) index = 'E';
        printf("Indeks akhir kelas = %c\n", index);
    }
    return 0;
}