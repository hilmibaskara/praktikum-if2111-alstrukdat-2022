/*
NAMA: Marcelino Feihan
NIM: 18219006
TANGGAL: 22/10/2020
DESKRIPSI: set.c
TOPIK: Praktikum 5
*/

#include"set.h"
#include<stdio.h>

void CreateEmpty(Set *S){
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
/* Ciri Set kosong : count bernilai Nil */
    (*S).Count=0;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
bool IsEmpty(Set S){
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai Nil */
    return S.Count==0;
}
bool IsFull(Set S){
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai MaxEl */
    return S.Count==MaxEl;
}
/* ********** Operator Dasar Set ********* */
void Insert(Set *S, infotype Elmt){
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */
    if(!IsMember(*S,Elmt)){
        (*S).Elements[S->Count]=Elmt;
        (*S).Count+=1;
    }

}
void Delete(Set *S, infotype Elmt){
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */
    if (IsMember(*S,Elmt)){
        int i=0,j;
        while (i<(*S).Count && (*S).Elements[i]!=Elmt){
            i+=1;
        }
        for (j=i+1;j<(*S).Count;j++){
            (*S).Elements[j-1]=(*S).Elements[j];
        }
        (*S).Count-=1;
    }

}
bool IsMember(Set S, infotype Elmt){
/* Mengembalikan true jika Elmt adalah member dari S */
    int i=0;
    bool found=false;
    while (i<S.Count&&!found){
        if (S.Elements[i]==Elmt){
            found=true;
        }
        i+=1;
    }
    return found;
}