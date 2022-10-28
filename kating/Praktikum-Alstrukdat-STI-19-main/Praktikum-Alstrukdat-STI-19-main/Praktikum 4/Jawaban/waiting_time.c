/* NIM: 18219006
NAMA: Marcelino Feihan
TANGGAL: 8 Oktober 2020
TOPIK: Praktikum 4
DESKRIPSI: waiting_time.c
*/
#include "circular_queue.h"
#include<stdio.h>
#include<stdlib.h>
/**
 * Menghitung waktu tunggu x pada Q, yaitu berapa banyak elemen yang ada
 * di depan elemen x pada Queue Q tanpa mengubah isi dari Q.Tab
 */
int WaitingTime(Queue Q, int x) {
    // TODO: Implementasi fungsi
    //   I.S. Q sudah dialokasi, bisa kosong
    //   F.S. integer yang berisi "waktu tunggu" seperti definisi di atas
    //        jika x tidak ada pada antrean Q, kembalikan -1
    int i=Q.HEAD,hasil=-999;
    boolean beda=true;
    if (IsEmpty(Q)){
        return -1;
    }
    else{
        while (i<=Q.TAIL&&beda){
            if (Q.Tab[i]==x){
                beda=false;
                hasil=i;
            }
            i=(i+1)%Q.MaxEl;
        }
        if (hasil==-999){
            return -1;
        }
        else{
            return hasil;
        }
    }
}