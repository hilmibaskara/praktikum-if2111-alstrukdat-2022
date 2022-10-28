/*NAMA:Marcelino Feihan
NIM: 18219006
TANGGAL: 5 November 2020
TOPIK: Praktikum 7
DESKRIPSI: Diantarakita.c
*/
/* Definisi list : */
/* List kosong : First(L) = Nil */
/* List dengan 1 elemen: First(L) = Next(First(L)) */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list : jika addressnya Last, maka Next(Last)=First(List) */
#include<stdio.h>
#include<stdlib.h>
#include"diantarakita.h"
/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L){
/* Mengirim true jika list kosong */
    return First(L)==Nil;
}
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L){
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
    First(*L)=Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X){
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=P */
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
void Dealokasi (address *P){
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
    free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
boolean FSearch (List L, infotype X){
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan true. */
/* Jika tidak ada, mengirimkan false */
    if(IsEmpty(L)){
        return false;
    }
    else{
        address p=First(L);
        boolean found=false;
        while (Next(p)!=First(L)&&Info(p)!=X){
            p=Next(p);
        }
        if (Info(p)==X){
            found=true;
        }
        return found;
    }
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsertFirst (List *L, infotype X){
/* I.S. L mungkin kosong */
/* F.S. Mengecek apakah X ada di List. */
/* Jika ada, hapus X dari list. */
/* Selanjutnya melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
    if (FSearch(*L,X)){
        DeleteElement(L,X);
    }
    address p=Alokasi(X);
    if (p!=Nil){
        if (IsEmpty(*L)){
            First(*L)=p;
            Next(p)=First(*L);
        }
        else{
            address cari=First(*L);
            while (Next(cari)!=First(*L)){
                cari=Next(cari);
            }
            Next(p)=First(*L);
            First(*L)=p;
            Next(cari)=First(*L);
        }
    }
    /*address p=Alokasi(X);
    if (p!=Nil){
        if (IsEmpty(*L)){
            Next(p)=p;
        }
        else{
            if (FSearch(*L,X)){
                DeleteElement(L,X);
            }
            address cari=First(*L);
            while(Next(cari)!=First(*L)){
                cari=Next(cari);
            }
            Next(p)=First(*L);
            Next(cari)=p;
        }
        First(*L)=p;
    }*/
}
void InsertLast (List *L, infotype X){
/* I.S. L mungkin kosong */
/* F.S. Mengecek apakah X ada di List. */
/* Jika ada, hapus X dari list. */
/* Selanjutnya melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    if (FSearch(*L,X)){
        DeleteElement(L,X);
    }
    address p=Alokasi(X);
    if (p!=Nil){
        if (IsEmpty(*L)){
            First(*L)=p;
            Next(p)=First(*L);
        }
        else{
            address cari=First(*L);
            while (Next(cari)!=First(*L)){
                cari=Next(cari);
            }
            Next(p)=First(*L);
            Next(cari)=p;
        }
    }
}
void InsertAfter (List *L, infotype X, infotype Y){
/* I.S. List L mungkin kosong, Y mungkin ada di list, */
/*      Mungkin elemen X tidak ada pada list  */
/* F.S. Mencari X dan Y pada list. Jika X tidak ada I.S.=F.S. */
/*      Jika Y ada pada list, hapus Y dari list */
/*      Selanjutnya alokasi Y dan masukkan di list setelah X. */
    if (FSearch(*L,X)){
        if (FSearch(*L,Y)){
            DeleteElement(L,Y);
        }
        address p=Alokasi(Y);
        if (p!=Nil){
            address cari=First(*L);
            while (Next(cari)!=First(*L)&&Info(cari)!=X){
                cari=Next(cari);
            }
            Next(p)=Next(cari);
            Next(cari)=p;
        }
    }
}
void InsertBefore (List *L, infotype X, infotype Y){
/* I.S. List L mungkin kosong, Y mungkin ada di list, */
/*      Mungkin elemen X tidak ada pada list  */
/* F.S. Mencari X dan Y pada list. Jika X tidak ada I.S.=F.S. */
/*      Jika Y ada pada list, hapus Y dari list */
/*      Selanjutnya alokasi Y dan masukkan di list sebelum X. */
/*      Jika X pada I.S. adalah First, maka Y menjadi First pada F.S. */
    if (FSearch(*L,X)){
        if (FSearch(*L,Y)){
            DeleteElement(L,Y);
        }
        address p=Alokasi(Y);
        if (p!=Nil){
            address cari=First(*L),sebelum=Nil;
            while (Next(cari)!=First(*L)&&Info(cari)!=X){
                sebelum=cari;
                cari=Next(cari);
            }
            if (Next(First(*L))==First(*L)){
                Next(p)=First(*L);
                Next(First(*L))=p;
                First(*L)=p;
            }   
            else{
                Next(p)=cari;
                Next(sebelum)=p;
            }
        }
    }
}
/*** PENGHAPUSAN ELEMEN ***/
void DeleteFirst (List *L, infotype *X){
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
    address p=First(*L);
    *X=Info(p);
    if (Next(p)==First(*L)){
        First(*L)=Nil;
    }
    else{
        address q=First(*L);
        while(Next(q)!=First(*L)){
            q=Next(q);
        }
        First(*L)=Next(First(*L));
        Next(q)=First(*L);
    }
    Dealokasi(&p);
}
void DeleteLast (List *L, infotype *X){
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
    address p=First(*L),sebelum=Nil;
    while(Next(p)!=First(*L)){
        sebelum=p;
        p=Next(p);
    }
    *X=Info(p);
    if (sebelum==Nil){
        First(*L)=Nil;
    }
    else{
        Next(sebelum)=First(*L);
    }
    Dealokasi(&p);
}
void DeleteElement (List *L, infotype X){
/* I.S. list mungkin kosong */
/* F.S. Mencari X. Jika ada, hapus X */
/*      Jika pada I.S., X adalah First, maka elemen setelah X menjadi First, */
/*      KECUALI X adalah satu-satunya elemen */
    if (FSearch(*L,X)){
        address p=First(*L),sebelum=Nil;
        if (Info(p)==X){
            First(*L)=Nil;
        }
        else{
            while(Info(p)!=X){
                sebelum=p;
                p=Next(p);
            }
            if(sebelum==Nil){
                First(*L)=Nil;
            }
            else{
                Next(sebelum)=Next(p);   
            }
        }
        Next(p)=Nil;
        
    }
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L){
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak ke kanan: [e1,e2,...,en] */
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

int CountElement (List L){
/* List L mungkin kosong */
/* Output banyaknya jumlah elemen pada list L */
    int count=0;
    if (!IsEmpty(L)){
        address p=First(L);
        while(Next(p)!=First(L)){
            count+=1;
            p=Next(p);
        }
        if(Next(p)==First(L)){
            count+=1;
        }
    }
    return count;
}
/****************** PROSES TERHADAP LIST ******************/
void MoveLastToFirst(List *L){
/* I.S. List mungkin kosong */
/* F.S. Jika list memiliki lebih dari 1 elemen, pindahkan elemen terakhir menjadi elemen pertama */
/* Tips: Perkara mudah jangan dibuat sulit */
    address p=First(*L),sebelum=Nil;
    while(Next(p)!=First(*L)){
        sebelum=p;
        p=Next(p);
    }
    First(*L)=p;
    Next(sebelum)=First(*L);
}