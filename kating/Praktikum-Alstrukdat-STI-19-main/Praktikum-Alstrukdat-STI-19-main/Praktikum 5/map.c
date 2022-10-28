/*
NAMA: Marcelino Feihan
NIM: 18219006
TANGGAL: 22/10/2020
DESKRIPSI: map.c
TOPIK: Praktikum 5
*/

#include<stdio.h>
#include"map.h"

void CreateEmpty(Map *M){
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */
    (*M).Count=Nil;
}
/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
bool IsEmpty(Map M){
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */
    return M.Count==Nil;
}
bool IsFull(Map M){
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */
    return M.Count==MaxEl;
}
/* ********** Operator Dasar Map ********* */
valuetype Value(Map M, keytype k){
/* Mengembalikan nilai value dengan key k dari M */
    int i,hasil=0;
    for (i=0;i<M.Count;i++){
        if (M.Elements[i].Key==k){
            hasil=M.Elements[i].Value;
        }
    }
    return hasil;
}
void Insert(Map *M, keytype k, valuetype v){
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */
    if (!IsMember(*M,k)){
        (*M).Elements[(*M).Count].Value=v;
        (*M).Elements[(*M).Count].Key=k;
        (*M).Count+=1;
    }
}
void Delete(Map *M, keytype k){
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */
    if (IsMember(*M,k)){
        int j=0,k,count=0;;
        while ((*M).Elements[j].Key!=k&&count<MaxEl){
            j=(j+1)%MaxEl;
            count+=1;
        }
        for (k=j;k<(*M).Count;k++){
            (*M).Elements[k].Key=(*M).Elements[k+1].Key;
            (*M).Elements[k].Value=(*M).Elements[k+1].Value;
        }
        (*M).Count-=1;
    }
}
bool IsMember(Map M, keytype k){
/* Mengembalikan true jika k adalah member dari M */
    bool found=false;
    int i=0;
    while (i<M.Count&&!found){
        if (M.Elements[i].Key==k){
            found=true;
        }
        i+=1;
    }
    return found;
}