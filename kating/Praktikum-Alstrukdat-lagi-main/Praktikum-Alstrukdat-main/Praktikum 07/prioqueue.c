//NAMA  : Saul Sayers
//NIM   : 13520094 / 16520075
//KELAS : K02 Alstrukdat
//PRAKTIKUM 7

#include <stdio.h>
#include "prioqueue.h"

void CreatePrioQueue(PrioQueue *pq){
    IDX_HEAD(*pq) = IDX_UNDEF;
    IDX_TAIL(*pq) = IDX_UNDEF;
}
/* I.S. sembarang */
/* F.S. Sebuah pq kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah pq kosong */

boolean isEmpty(PrioQueue pq){
    return (IDX_HEAD(pq) == IDX_UNDEF && IDX_TAIL(pq) == IDX_UNDEF);
}
/* Mengirim true jika q kosong: lihat definisi di atas */

boolean isFull(PrioQueue pq){
    return (IDX_HEAD(pq) == 0 && IDX_TAIL(pq) == (CAPACITY -1));
}
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu jika index head bernilai 0 dan index tail bernilai CAPACITY-1 */

int length(PrioQueue pq){
    int panjang ;
    if (isEmpty(pq)) {
        panjang = 0;
    }
    else {
        panjang = IDX_TAIL(pq) - IDX_HEAD(pq) +1 ;
    }
    return panjang ;
}

void enqueue(PrioQueue *pq, ElType val){
    int i,awal;
    ElType nilai;
    if (isEmpty(*pq)) {
        IDX_HEAD(*pq) = 0;
        IDX_TAIL(*pq) = 0;
        HEAD(*pq) = val;
    }
    else {
        if ((IDX_TAIL(*pq) == 99)) {
            for (i = IDX_HEAD(*pq); i < IDX_TAIL(*pq) +1; i++){
                (*pq).buffer[i - IDX_HEAD(*pq)] = (*pq).buffer[i];
            }
            IDX_TAIL(*pq) = IDX_TAIL(*pq) - IDX_HEAD(*pq);
            IDX_HEAD(*pq) = 0;
        }
        IDX_TAIL(*pq) +=1  ;
        TAIL(*pq) = val ;
    }
}
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur".
        Jika q penuh semu, maka perlu dilakukan aksi penggeseran "maju" elemen-elemen q
        menjadi rata kiri untuk membuat ruang kosong bagi TAIL baru  */

void dequeue(PrioQueue *pq, ElType *val){
    *val = HEAD(*pq);
    if (length(*pq) == 1) {
        CreatePrioQueue(pq) ;
    }
    else {
        IDX_HEAD(*pq) += 1;
    }
}
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., HEAD dan IDX_HEAD "mundur";
        q mungkin kosong */
