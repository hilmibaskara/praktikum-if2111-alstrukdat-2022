/*
NIM:18219006
Nama: Marcelino Feihan
Tanggal: 17/09/2020
Topik Praktikum: Praktikum 1
Deskripsi:
*/
#include<stdio.h>
#include<math.h>
#include "point.h"

POINT MakePOINT (float X, float Y){
    POINT p1;
    Absis(p1)=X;
    Ordinat(p1)=Y;
    return p1;
}
/* Membentuk sebuah POINT dari komponen-komponennya */

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */                                                 
void BacaPOINT (POINT * P){
    /* Membaca nilai absis dan ordinat dari keyboard dan membentuk 
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2 
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
    float x,y;
    scanf("%f",&x);
    scanf("%f",&y);
    *P=MakePOINT(x,y);
}

void TulisPOINT (POINT P){
    /* Nilai P ditulis ke layar dengan format "(X,Y)" 
   tanpa spasi, enter, atau karakter lain di depan, belakang, 
   atau di antaranya */
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */  
    printf("(%.2f,%.2f)",Absis(P),Ordinat(P));
}
              

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2){
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
    return (Absis(P1)==Absis(P2)&&(Ordinat(P1)==Ordinat(P2)));
}
boolean NEQ (POINT P1, POINT P2){
/* Mengirimkan true jika P1 tidak sama dengan P2 */
    return (!EQ(P1,P2));
}
/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P){
/* Menghasilkan true jika P adalah titik origin */
    return ((Absis(P)==0)&&(Ordinat(P)==0));
}
boolean IsOnSbX (POINT P){
/* Menghasilkan true jika P terletak Pada sumbu X */
    return (Ordinat(P)==0);
}
boolean IsOnSbY (POINT P){
/* Menghasilkan true jika P terletak pada sumbu Y */
    return (Absis(P)==0);
}
int Kuadran (POINT P){
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan titik origin, */
/*              dan P tidak terletak di salah satu sumbu */
    if ((Absis(P)>0)&&(Ordinat(P)>0)){
        return 1;
    }
    else if ((Absis(P)<0)&&(Ordinat(P)>0)){
        return 2;
    }
    else if ((Absis(P)<0)&&(Ordinat(P)<0)){
        return 3;
    }
    else{
        return 4;
    }
}

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
POINT PlusDelta (POINT P, float deltaX, float deltaY){
/*Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
    float x,y;
    x=Absis(P);
    y=Ordinat(P);
    x+=deltaX;
    y+=deltaY;
    P=MakePOINT(x,y);
    return P;
}
void Geser (POINT *P, float deltaX, float deltaY){
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
    float xawal,yawal;
    xawal=Absis(*P)+deltaX;
    yawal=Ordinat(*P)+deltaY;
    *P=MakePOINT(xawal,yawal);
}
float Jarak0 (POINT P){
/* Menghitung jarak P ke (0,0) */
    float jarak;
    jarak=sqrt((Absis(P)*Absis(P))+(Ordinat(P)*Ordinat(P)));
    return jarak;
}
float Panjang (POINT P1, POINT P2){
/* Menghitung panjang garis yang dibentuk P1 dan P2. */
    float selisihx,selisihy,panjang;
    selisihx=Absis(P1)-Absis(P2);
    selisihy=Ordinat(P1)-Ordinat(P2);
    panjang=sqrt((selisihx*selisihx)*(selisihy*selisihy));
    return panjang;
}