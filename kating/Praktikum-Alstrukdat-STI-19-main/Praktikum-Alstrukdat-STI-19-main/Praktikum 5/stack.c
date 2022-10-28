/*
NAMA: Marcelino Feihan
NIM: 18219006
TANGGAL: 22/10/2020
DESKRIPSI: stack.c
TOPIK: Praktikum 5
*/
#include"stack.h"
#include<stdio.h>

void CreateEmpty(Stack *S){
/* I.S. Sembarang */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
    (*S).TOP=Nil;
}
bool IsEmpty(Stack S){
/* Mengirim true jika Stack kosong*/
/* Ciri stack kosong : TOP bernilai Nil */
    return S.TOP==Nil;
}
bool IsFull(Stack S){
/* Mengirim true jika stack S penuh */
/* Ciri stack penuh : TOP bernilai MaxEl */
    return S.TOP==MaxEl;
}

/* ********** Operator Dasar Stack ********* */
void Push(Stack *S, infotype X){
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, S tidak penuh */
/* F.S. X menjadi element TOP yang baru, TOP bertambah 1 */
    (*S).T[(*S).TOP]=X;
    (*S).TOP+=1;
}
void Pop(Stack *S, infotype *X){
/* Menghapus X dari Stack S. */
/* I.S. S tidak kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
    *X=(*S).T[(*S).TOP-1];
    (*S).TOP-=1;
}
/* ********** Operator Tambahan ********* */
void ForcePush(Stack *S, infotype X){
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, S mungkin penuh */
/* F.S. X menjadi element TOP yang baru, TOP bertambah 1
        Apabila S penuh, buang element paling bawah dari S dan masukkan X sebagai TOP
        Contoh: S berisi a b c d e f g h i j, setelah melakukan ForcePush(S, "k")
        S berisi b c d e f g h i j k */
    if(IsFull(*S)){
        int i;
        for (i=1;i<S->TOP;i++){
            (*S).T[i-1]=(*S).T[i];
        }
        (*S).TOP-=1;
        Push(S,X);
    }
    else{
        Push(S,X);
    }
}