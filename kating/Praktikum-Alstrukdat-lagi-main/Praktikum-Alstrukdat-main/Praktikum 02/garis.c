//Nama : Saul Sayers
//NIM  : 13520094 / 16520075
//Kelas: K02
//PRAKTIKUM 2 SOAL 2

#include <stdio.h>
#include "garis.h"
#include <math.h>

void MakeGARIS (POINT P1, POINT P2, GARIS * L){
    PAwal(*L) = P1;
    PAkhir(*L) = P2;
}

void BacaGARIS(GARIS *L) {
    POINT p1,p2 ;
    boolean benar = false ;
    while (benar == false) {
        BacaPOINT(&p1) ;
        BacaPOINT(&p2) ;
        if (NEQ(p1,p2)) {
            benar = true ;
        }
        if (benar == false) {
            printf("Garis tidak valid\n");
        }
        else {
            MakeGARIS(p1,p2,L);
        }
    }
}

void TulisGARIS (GARIS L) {
    printf("(");
    TulisPOINT(PAwal(L));
    printf(",");
    TulisPOINT(PAkhir(L));
    printf(")");
}

float PanjangGARIS (GARIS L) {
    return Panjang(PAwal(L), PAkhir(L));
}

float Gradien (GARIS L) {
    float pembilang, penyebut;
    pembilang = Ordinat(PAkhir(L)) - Ordinat(PAwal(L));
    penyebut = Absis(PAkhir(L)) - Absis(PAwal(L));
    return pembilang/penyebut ;
}

void GeserGARIS (GARIS * L, float deltaX, float deltaY) {
    Geser(&PAwal(*L), deltaX, deltaY) ;
    Geser(&PAkhir(*L), deltaX, deltaY) ;
}

boolean IsTegakLurus (GARIS L1, GARIS L2) {
    return (fabs(Gradien(L1)*Gradien(L2) + 1) < 1e-5) ;
}

boolean IsSejajar (GARIS L1, GARIS L2) {
    return (fabs(Gradien(L1) - Gradien(L2)) < 1e-5) ;
}