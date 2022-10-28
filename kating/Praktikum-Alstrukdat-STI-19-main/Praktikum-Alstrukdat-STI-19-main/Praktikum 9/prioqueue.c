/*
NAMA:Marcelino Feihan
NIM:18219006
TANGGAL:19 November 2020
TOPIK: Praktikum 9
DESKRIPSI: Prioqueue.c
*/

#include<stdio.h>
#include<stdlib.h>
#include"prioqueue.h"
/* Prototype manajemen memori */
void Alokasi (address *P, infotype X, int prio){
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X,
        Next(P)=Nil, dan Prio(P)=prio */
/*      P=Nil jika alokasi gagal */
    *P=(address)malloc(sizeof(ElmtQueue));
    if(*P!=Nil){
        Info(*P)=X;
        Prio(*P)=prio;
        Next(*P)=Nil;
    }
}
void Dealokasi (address  P){
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
    free(P);
}
boolean IsEmpty (Queue Q){
/* Mengirim true jika Q kosong: HEAD(Q)=Nil and TAIL(Q)=Nil */
    return ((Head(Q)==Nil))&&(Tail(Q)==Nil);
}
int NbElmt(Queue Q){
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
    int count=0;
    if(!IsEmpty(Q)){
        address P=Head(Q);
        while (P!=Nil){
            count+=1;
            P=Next(P);
        }
    }
    return count;
}
/*** Kreator ***/
void CreateEmpty(Queue * Q){
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk (i.e. Head(Q) = Nil dan Tail(Q) = Nil) */
/*** Primitif Add/Delete ***/
    Head(*Q)=Nil;
    Tail(*Q)=Nil;
}
void Enqueue (Queue * Q, infotype X, int prio){
/* Proses: Mengalokasi X dan menambahkan X pada posisi setelah element dengan 
   prioritas yang lebih tinggi/sama, dan sebelum element dengan prioritas yang 
   lebih rendah jika alokasi berhasil; jika alokasi gagal Q tetap */
/* I.S. Q mungkin kosong */
/* F.S. X diletakkan setelah setelah element dengan prioritas yang lebih 
   tinggi/sama, dan sebelum element dengan prioritas yang lebih rendah.
   Apabila X diletakkan di posisi terakhir, maka TAIL = element X. */
    address P;
    Alokasi(&P,X,prio);
    if(P!=Nil){
        if (IsEmpty(*Q)){
            Head(*Q)=P;
            Tail(*Q)=P;
        }
        else{
            address now=Head(*Q),prec=Nil;
            while((now!=Nil)&&(Prio(now)>=Prio(P))){
                prec=now;
                now=Next(now);
            }
            if(prec==Nil){
                Next(P)=Head(*Q);
                Head(*Q)=P;
            }
            else{
                Next(P)=Next(prec);
                Next(prec)=P;
                if(now==Nil){
                    Tail(*Q)=P;
                }
            }
            
        }
    }
}
void Dequeue (Queue * Q, infotype * X){
/* Proses: Menghapus X pada bagian HEAD dari Q dan mendealokasi
   elemen HEAD */
/* Pada dasarnya operasi delete first */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur" */
    address P=Head(*Q);
    *X=Info(P);
    if (Head(*Q)==Tail(*Q)){
        Head(*Q)=Nil;
        Tail(*Q)=Nil;
    }
    else{
        Head(*Q)=Next(Head(*Q));
    }
    Next(P)=Nil;
    Dealokasi(P);
}
