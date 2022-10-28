#include<stdio.h>
#include"queue.h"
#include<stdlib.h>
/* File : queue.h */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */

/* ********* Prototype ********* */
boolean IsEmpty (Queue Q){
/* Mengirim true jika Q kosong: lihat definisi di atas */
    return Head(Q)==Nil && Tail(Q)==Nil;
}
boolean IsFull (Queue Q){
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
    if (Head(Q)!=0){
        return Head(Q)-Tail(Q)==1;
    }
    else{
        return Tail(Q)-Head(Q)==MaxEl(Q)-1;
    }
}
int NBElmt (Queue Q){
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
    if (Tail(Q)>Head(Q)){
        return (Tail(Q)-Head(Q))+1;
    }
    else{
        return (Tail(Q)+MaxEl(Q)+1)-Head(Q);
    }
}

/* *** Kreator *** */
void CreateEmpty (Queue * Q, int Max){
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
    (*Q).T=(infotype*)malloc(Max*sizeof(infotype));
    MaxEl(*Q)=Max;
    Head(*Q)=Nil;
    Tail(*Q)=Nil;
}
/* *** Destruktor *** */
void DeAlokasi(Queue * Q){
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
    free(Q->T);
    MaxEl(*Q)=0;
    Head(*Q)=Nil;
    Tail(*Q)=Nil;
}
/* *** Primitif Add/Delete *** */
void Add (Queue * Q, infotype X){
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
    if (IsEmpty(*Q)){
        Head(*Q)+=1;
        Tail(*Q)+=1;
        InfoHead(*Q)=X;
    }
    else{
        if (Tail(*Q)==MaxEl(*Q)-1){
            Tail(*Q)=0;
        }
        else{
            Tail(*Q)+=1;
        }
        InfoTail(*Q)=X;
    }
}
void Del (Queue * Q, infotype * X){
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer; 
        Q mungkin kosong */
    X=&InfoHead(*Q);
    if (Head(*Q)==Tail(*Q)){
        Head(*Q)=Nil;
        Tail(*Q)=Nil;
    }
    else{
        if (Head(*Q)==MaxEl(*Q)-1){
            Head(*Q)=0;
        }
        else{
            Head(*Q)+=1;
        }
    }
}
