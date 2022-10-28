#include<stdlib.h>
#include<stdio.h>
#include"listsirkuler.h"
/* Definisi list : */
/* List kosong : First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list: jika addressnya Last, maka Next(Last)=First(L) */

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L){
/* Mengirim true jika list kosong. Lihat definisi di atas. */
    return First(L)==Nil;
}
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L){
/* I.S. L sembarang             */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
    First(*L)=Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X){
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
    ElmtList *P=(ElmtList*)malloc(sizeof(ElmtList));
    if (P!=Nil){
        Info(P)=X;
        Next(P)=Nil;
        return P;
    }
    else
    {
        return Nil;
    }
    
    
}
void Dealokasi (address P){
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
    free(P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X){
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
    address p=First(L);
    address ketemu=Nil;
    if(!IsEmpty(L)){
        while (Next(p)!=First(L)&&Info(p)!=X){
            p=Next(p);
        }
        if (Info(p)==X){
            ketemu=p;
        }
    }
    return ketemu;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X){
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
    address p=Alokasi(X);
    if(p!=Nil){
        InsertFirst(L,p);
    }
}
void InsVLast (List *L, infotype X){
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    address p=Alokasi(X);
    if (p!=Nil){
        InsertLast(L,p);
    }
}
/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype * X){
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
    address P;
    DelFirst(L,&P);
    *X=Info(P);
    Dealokasi(P);
}
void DelVLast (List *L, infotype * X){
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
    address P;
    DelLast(L,&P);
    *X=Info(P);
    Dealokasi(P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P){
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
    if(IsEmpty(*L)){
        Next(P)=P;
    }
    else
    {
        address cari=First(*L);
        while(Next(cari)!=First(*L)){
            cari=Next(cari);
        }
        Next(P)=First(*L);
        Next(cari)=P;
    }
    First(*L)=P;
    
}
void InsertLast (List *L, address P){
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
    if(IsEmpty(*L)){
        InsertFirst(L,P);
    }
    else
    {
        address cari=First(*L);
        while (Next(cari)!=First(*L)){
            cari=Next(cari);
        }
        InsertAfter(L,P,cari);
    }
    
}
void InsertAfter (List *L, address P, address Prec){
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
    if (Next(Prec)==First(*L)){
        Next(P)=First(*L);
    }
    else
    {
        Next(P)=Next(Prec);
    }
    Next(Prec)=P;
    
}
/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P){
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
    *P=First(*L);
    if (Next(*P)==First(*L)){
        First(*L)=Nil;
    }
    else
    {
        address check=First(*L);
        while (Next(check)!=First(*L))
        {
            check=Next(check);
        }
        First(*L)=Next(*P);
        Next(check)=First(*L);
    }
    
}
void DelLast (List *L, address *P){
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
    address cari=First(*L);
    address sebelum=Nil;
    while (Next(cari)!=First(*L)){
        sebelum=cari;
        cari=Next(cari);
    }
    DelAfter(L,P,sebelum);

}
void DelAfter (List *L, address *Pdel, address Prec){
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
    *Pdel=Next(Prec);
    if(Next(*Pdel)==First(*L)){
        Next(Prec)=First(*L);
    }
    else if(Next(Prec)==First(*L)){
        First(*L)=Next(First(*L));
        Next(Prec)=First(*L);
    }
    else{
        Next(Prec)=Next(*Pdel);
    }
    Next(*Pdel)=Nil;
}
void DelP (List *L, infotype X){
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
    if(!IsEmpty(*L)){
        address p=Search(*L,X);
        if(p!=Nil){
            if(Next(p)==p){
                First(*L)=Nil;
            }
            else{
                address last=First(*L);
                while (Next(last)!=p){
                    last=Next(last);
                }
                DelAfter(L,&p,last);

            }
           /*if (Next(p)==First(*L)){
               First(*L)=Nil;
           }
           else
           {
               address cari=First(*L),p;
               while(Next(cari)!=p){
                   cari=Next(cari);
               }
               DelAfter(L,&p,cari);
           }*/
           Dealokasi(p);
        }
    }
}
/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L){
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    if(IsEmpty(L)){
        printf("[]");
    }
    else
    {
        address p=First(L);
        printf("[");
        do{
            if (Next(p)==First(L)){
                printf("%d",Info(p));
            }
            else
            {
                printf("%d,",Info(p));
            }
            p=Next(p);
        }while (p!=First(L));
        
        printf("]");
    }
    
}
