#include<stdio.h>
#include"list.h"
/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong */
void MakeEmpty(List *T){
/* I.S. sembarang */
/* F.S. Terbentuk list L kosong dengan kapasitas IdxMax-IdxMin+1 */
    (*T).Neff=0;
}

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int Length(List L){
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list kosong */
/* *** Daya tampung container *** */
    return L.Neff;
}
int MaxLength(List L){
/* Mengirimkan maksimum elemen yang dapat ditampung oleh list */
/* *** Selektor INDEKS *** */
    return IdxMax-IdxMin+1;
}
IdxType FirstIdx(List L){
/* Prekondisi : list L tidak kosong */
/* Mengirimkan indeks elemen pertama */
    return IdxMin;
}
IdxType LastIdx(List L){
/* Prekondisi : list L tidak kosong */
/* Mengirimkan indeks elemen terakhir */
/* *** Menghasilkan sebuah elemen *** */
    return IdxMin+L.Neff-1;
}
ElType Get(List L, IdxType i){
/* Prekondisi : list tidak kosong, i antara FirsLIdx(T)..LasLIdx(T) */
/* Mengirimkan elemen list yang ke-i */
    return L.A[i];
}

/* *** Selektor SET : Mengubah nilai list dan elemen list *** */
void Set(List *T, IdxType i, ElType v){
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
/* Operasi hanya dilakukan apabila apabila i berada dalam index efektif*/
    if (IsIdxEff((*T),i)){
        (*T).A[i]=v;
    }
}
void SetNeff(List *L, IdxType N){
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */
    (*L).Neff=N;
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid(List L, IdxType i){
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran list */
/* yaitu antara indeks yang terdefinisi untuk container*/
    return i>=FirstIdx(L) && i<=L.Neff-1;
}
boolean IsIdxEff(List L, IdxType i){
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara FirstIdx(L)..LastIdx(L) */
    return i>=FirstIdx(L) && i<=LastIdx(L);
}

/* ********** Operasi-operasi ********** */
IdxType Search(List L, ElType v){
/* I.S. L, i, v terdefinisi.*/
/* F.S. Mengembalikan indeks lojik elemen pertama L yang bernilai v (jika ada), */
/* atau mengembalikan IdxUndef jika tidak ada. */
    if (IsEmpty(L)){
        return IdxUndef;
    }
    else{
        IdxType i=FirstIdx(L),ans;
        boolean loss=true;
        while (i<=L.Neff-1&&loss){
            if (L.A[i]==v){
                loss=false;
                ans=i;
            }
            i++;
        }
        if (loss==true){
            return IdxUndef;
        }
        else{
            return ans;
        }
    }
}
void InsertFirst(List *L, ElType v){
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen pertama L. */
    if (IsEmpty(*L)){
        (*L).Neff=1;
        (*L).A[IdxMin]=v;
    }
    else{
        IdxType i;
        for (i=(*L).Neff-1;i>=IdxMin;i--){
            (*L).A[i+1]=(*L).A[i];
        }
        (*L).A[IdxMin]=v;
        (*L).Neff+=1;
    }
}
void InsertAt(List *L, IdxType i, ElType v){
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. v disisipkan dalam L pada indeks ke-i (bukan menimpa elemen di i). */
    IdxType j;
    for (j=(*L).Neff-1;j==i;j--){
        (*L).A[j+1]=(*L).A[j];
    }
    (*L).A[i]=v;
    (*L).Neff+=1;

}
void InsertLast(List *L, ElType v){
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen terakhir L. */
    if (IsEmpty(*L)){
        (*L).Neff=1;
        (*L).A[IdxMin]=v;
    }
    else{
        (*L).A[(*L).Neff]=v;
        (*L).Neff+=1;
    }
}
void DeleteFirst(List *L, ElType *F){
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen pertama L, elemen pertama L dihapus dari L. */
    IdxType i;
    *F=(*L).A[IdxMin];
    for (i=FirstIdx(*L)+1;i<(*L).Neff;i++){
        (*L).A[i-1]=(*L).A[i];
    }
    (*L).Neff-=1;
}
void DeleteAt(List *L, IdxType i){
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. Elemen L pada indeks ke-i dihapus dari L. */
    IdxType j;
    for (j=i+1;j<(*L).Neff;j++){
        (*L).A[j-1]=(*L).A[j];
    }
    (*L).Neff-=1;
}
void DeleteLast(List *L, ElType *F){
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen terakhir L, elemen terakhir L dihapus dari L. */
    IdxType i;
    *F=(*L).A[(*L).Neff-1];
    (*L).Neff-=1;
}
void Concat(List L1, List L2, List *L3){
/* I.S. L1 ≠ L2, L1 ≠ L3, dan L3 ≠ L2; L1, L2 mungkin kosong */
/* F.S. L3 adalah hasil Konkatenasi ("Menyambung") dua buah list, L2 */
/* ditaruh di belakang L1 */
    IdxType i,j=0;
    if (IsEmpty(L1)){
        for (i=FirstIdx(L2);i<L2.Neff;i++){
            (*L3).A[i]=L2.A[i];
            (*L3).Neff+=1;       
        }
    }
    else if (IsEmpty(L2)){
        for (i=FirstIdx(L1);i<L1.Neff;i++){
            (*L3).A[i]=L1.A[i];
            (*L3).Neff+=1;       
        }
    }
    else{
        for (i=FirstIdx(L1);i<L1.Neff;i++){
            (*L3).A[i]=L1.A[i];
            (*L3).Neff+=1;       
        }
        for (i=LastIdx(L1)+1;i<=(LastIdx(L1)+L2.Neff);i++){
            (*L3).A[i]=L2.A[j];
            j+=1;
            (*L3).Neff+=1;       
        }
    }
}
/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean IsEmpty(List L){
/* Mengirimkan true jika list L kosong, mengirimkan false jika tidak */
    return L.Neff==0;
}