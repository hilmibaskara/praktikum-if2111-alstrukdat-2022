/*
NIM         : 18221072
Nama        : Hilmi Baskara Radanto
Tanggal     : 15 Oktober 2022
Topik       : PraPraktikum 6 - Queue Soal 2
Deskripsi   : Implementasi circular_queue.h
*/

#include <stdio.h>
#include <stdlib.h>
#include "circular_queue.h"

/* ********* Prototype ********* */
boolean IsEmpty (Queue Q){
/* Mengirim true jika Q kosong: lihat definisi di atas */
        return (Q.HEAD == NIL && Q.TAIL == NIL);
}

boolean IsFull (Queue Q){
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
        return (Length(Q) == MaxLength(Q));
}

int Length (Queue Q){
/* Mengirimkan banyaknya elemen Q, 0 jika kosong */
        int len;
        if (IsEmpty(Q)){
                len = 0;
        } else {
                if (Q.HEAD <= Q.TAIL){
                        len = Q.TAIL - Q.HEAD + 1;
                } else {
                        len = Q.TAIL + 1;
                        len = len + (Q.MaxEl - Q.HEAD);
                }
        }
        return len;
}

int MaxLength (Queue Q){
/* Mengirimkan kapasitas jumlah elemen Q */
        return Q.MaxEl;
}

/* *** Kreator *** */
Queue CreateQueue (int Max){
/* Proses : Melakukan alokasi memori, membuat sebuah Q kosong */
/* I.S. sembarang */
/* F.S. mengembalikan Q kosong dengan kondisi sbb: */
/*   Jika alokasi berhasil, Tab dialokasi berukuran Max */
/*   Jika alokasi gagal, Q kosong dengan MaxEl=0 */
        Queue Q;
        Q.Tab = (ElType*)malloc(Max*sizeof(ElType));
        if (Q.Tab != NULL){
                Q.MaxEl = Max;
                Q.HEAD = NIL;
                Q.TAIL = NIL;
        } else {
                Q.MaxEl = 0;
        }

        return Q;
}

/* *** Destruktor *** */
void DeleteQueue (Queue * Q){
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. membebaskan memori Tab, Q.MaxEl di-set 0 */
        free(Q->Tab);
        Q->MaxEl = 0;
}

/* *** Primitif Add/Delete *** */
void Push (Queue * Q, ElType X){
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru,
        TAIL "maju" dengan mekanisme circular buffer
        Jika Q kosong, HEAD dimulai dari 0 */
        if (IsEmpty(*Q)){
                Q->HEAD = 0;
                Q->TAIL = 0;
                Q->Tab[0] = X;
        } else {
                if (Q->TAIL == ((Q->MaxEl)-1)){
                        Q->TAIL = 0;
                } else {
                        Q->TAIL += 1;
                }
                Q->Tab[Q->TAIL] = X;
        }
}
ElType Pop (Queue * Q){
/* Proses: Menghapus indeks HEAD pada Q dengan aturan FIFO, lalu mengembalikan nilainya */
/* I.S. Q tidak mungkin kosong */
/* F.S. mengembalikan nilai Q pada indeks HEAD{}
        HEAD "maju" dengan mekanisme circular buffer{}
        Q mungkin kosong */
        int val = Q->Tab[Q->HEAD];      
        if (Q->HEAD == Q->TAIL){
                Q->HEAD = NIL;
                Q->TAIL = NIL;
        } else {
                if (Q->HEAD == Q->MaxEl - 1){
                        Q->HEAD == 0;
                } else {
                        Q->HEAD += 1;
                }
        }
        return val;
}

ElType Front (Queue Q){
/* Proses: Mengembalikan nilai Q pada indeks HEAD tanpa penghapusan */
/* I.S. Q tidak mungkin kosong */
/* F.S. mengembalikan nilai Q pada indeks HEAD{}
        Q pasti tetap tidak kosong */
        return (Q.Tab[Q.HEAD]);
}