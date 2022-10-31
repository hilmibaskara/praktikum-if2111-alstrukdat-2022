/*
    NIM         : 18221072
    Nama        : Hilmi Baskara Radanto
    Tanggal     : 28 Oktober 2022
    Topik       : Praktikum 8
    Deskripsi   : Implementasi hashmap.h
*/

#include "hashmap.h"

/* Definisi HashMap M kosong : M.Count = Nil */
/* M.Count = jumlah element HashMap */
/* M.Elements = tempat penyimpanan element HashMap */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmpty(HashMap *M){
    (*M).Count = Nil;
    
    for (int i = 0; i < MaxEl; i++)
    {
        (*M).Elements[i].Key = Undefined;
        (*M).Elements[i].Value = Undefined;
    }
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah HashMap M kosong berkapasitas MaxEl */
/* Ciri HashMap kosong : count bernilai Nil dengan seluruh isi key & value map Undefined */

/* *** Index Penyimpanan dengan modulo *** */
address Hash(keytype K){
    return (K % MaxEl);
}
/* Menghasilkan indeks penyimpanan dengan operasi modulo ke MaxEl */

/* ********** Operator Dasar HashMap ********* */
valuetype Value(HashMap M, keytype k){
    
    address i = Hash(k);

    while (M.Elements[i].Key != k && M.Elements[i].Key != Undefined){
        i = (i + 1) % MaxEl;
    }

    if (M.Elements[i].Key == k){
        return M.Elements[i].Value;
    } else {
        return Undefined; 
    }

}
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */

void Insert(HashMap *M, keytype k, valuetype v){

    address i = Hash(k);

    while ((*M).Elements[i].Key != Undefined)
    {
        i = (i + 1) % MaxEl;
    }

    (*M).Elements[i].Key = k;
    (*M).Elements[i].Value = v;
    (*M).Count++;

}
    
/* Menambahkan Elmt sebagai elemen HashMap M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan 
        index yang digunakan untuk menyimpan v adalah hash dari k
        gunakan open addressing linear probing dengan interval 1 jika index sudah terisi    */
