/*
    NIM         : 18221072
    Nama        : Hilmi Baskara Radanto
    Tanggal     : 28 Oktober 2022
    Topik       : Praktikum 8
    Deskripsi   : Implementasi set.h
*/

#include "set.h"

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Set *S){
    S->Count = Nil;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmpty(Set S){
    return (S.Count == Nil);
}

boolean IsFull(Set S){
    return (S.Count == MaxEl);
}

/* ********** Operator Dasar Set ********* */
void Insert(Set *S, infotype Elmt){
    if (!isMember(S, Elmt)){
        S->Count += 1;
        S->Elements[S->Count] == Elmt;
    }
}
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */

void Delete(Set *S, infotype Elmt){
    // Kalo ketemu
    boolean found = false;
    int i = 0;
    int idx;

    while (i <= S->Count && found == false){
        if (S->Elements[i] == Elmt){
            found = true;
            idx = i;
        }
        i++;
    }

    // geser elemen supaya rata kiri
    for (i = idx; i < S->Count; i++){
        S->Elements[i] = S->Elements[i+1];
    }

    S->Count -= 1;
}
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */

boolean IsMember(Set S, infotype Elmt){
    boolean found = false;
    int i = 1;
    while (i <= S.Count && found == false){
        if (S.Elements[i] == Elmt) found = true;
    }
}
/* Mengembalikan true jika Elmt adalah member dari S */