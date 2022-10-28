/* NIM: 18219006
NAMA: Marcelino Feihan
TANGGAL: 8 Oktober 2020
TOPIK: Praktikum 4
DESKRIPSI: circular_queue.c
*/
#include<stdio.h>
#include<stdlib.h>
#include"circular_queue.h"
/* ********* Prototype ********* */
boolean IsEmpty (Queue Q){
/* Mengirim true jika Q kosong: lihat definisi di atas */
    return (Q.HEAD==NIL)&&(Q.TAIL==NIL);
}
boolean IsFull (Queue Q){
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
    if(Q.TAIL>=Q.HEAD){
        return ((Q.TAIL-Q.HEAD+1)==Q.MaxEl);
    }
    else{
        return (Q.HEAD-Q.TAIL<=1);
    }
}
int Length (Queue Q){
/* Mengirimkan banyaknya elemen Q, 0 jika kosong */
    if (IsEmpty(Q)){
        return 0;
    }
    else if (Q.TAIL>=Q.HEAD){
        return Q.TAIL-Q.HEAD+1;
    }
    else{
        return Q.TAIL+Q.MaxEl+1-Q.HEAD;
    }
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
    Q.Tab=(ElType*)malloc(Max*sizeof(ElType));
    if (Q.Tab!=NULL){
        Q.MaxEl=Max;
        Q.HEAD=NIL;
        Q.TAIL=NIL;
    }
    else{
        Q.MaxEl=0;
    }
   
    return Q;
}
/* *** Destruktor *** */
void DeleteQueue (Queue * Q){
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. membebaskan memori Tab, Q.MaxEl di-set 0 */
    free(Q->Tab);
    Q->MaxEl=0;
}

/* *** Primitif Add/Delete *** */
void Push (Queue * Q, ElType X){
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru,
        TAIL "maju" dengan mekanisme circular buffer
        Jika Q kosong, HEAD dimulai dari 0 */
    if (IsEmpty(*Q)){
        (*Q).HEAD=0;
        (*Q).TAIL=0;
        (*Q).Tab[(*Q).TAIL]=X;
    }
    else{
        if ((*Q).TAIL==(*Q).MaxEl-1){
            (*Q).TAIL=0;
        }
        else{
            (*Q).TAIL=(*Q).TAIL+1;
        }
        (*Q).Tab[(*Q).TAIL]=X;
    }
}
ElType Pop (Queue * Q){
/* Proses: Menghapus indeks HEAD pada Q dengan aturan FIFO, lalu mengembalikan nilainya */
/* I.S. Q tidak mungkin kosong */
/* F.S. mengembalikan nilai Q pada indeks HEAD;
        HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
    ElType X;
    X=(*Q).Tab[(*Q).HEAD];
    if ((*Q).HEAD==(*Q).TAIL){
        (*Q).Tab[(*Q).HEAD]=NIL;
        (*Q).Tab[(*Q).TAIL]=NIL;
    }
    else
    {
        (*Q).HEAD=((*Q).HEAD+1)%(*Q).MaxEl;
    }
    return X;
}
ElType Front (Queue Q){
/* Proses: Mengembalikan nilai Q pada indeks HEAD tanpa penghapusan */
/* I.S. Q tidak mungkin kosong */
/* F.S. mengembalikan nilai Q pada indeks HEAD;
        Q pasti tetap tidak kosong */
    return Q.Tab[Q.HEAD];
}
/* *** Utilitas *** */
Queue CopyQueue (Queue Q){
/* Proses: Mengembalikan Queue baru dengan isi antrean sama seperti Q */
/* I.S. Q pernah dialokasi */
/* F.S. Queue baru dengan nilai isi antrean sama seperti Q;
        HEAD pada Queue baru dimulai dari 0 */
    Queue temp;
    temp=CreateQueue(Q.MaxEl);
    while (Q.HEAD!=Q.TAIL){
        temp.Tab[Q.HEAD]=Q.Tab[Q.HEAD];
        Q.HEAD=(Q.HEAD+1)%Q.MaxEl;
    }
    temp.HEAD=Q.HEAD;
    temp.TAIL=Q.TAIL;
    return temp;
}
