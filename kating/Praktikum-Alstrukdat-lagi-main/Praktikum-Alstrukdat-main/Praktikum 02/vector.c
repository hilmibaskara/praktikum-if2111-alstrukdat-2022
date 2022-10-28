//Nama : Saul Sayers
//NIM  : 13520094 / 16520075
//Kelas: K02
//PRAKTIKUM 2 SOAL 3

#include <stdio.h>
#include "vector.h"
#include <math.h>

VECTOR MakeVector(float x, float y){
    VECTOR v ;
    AbsisComponent(v) = x ;
    OrdinatComponent(v) = y;
    return v ;
}

void TulisVector (VECTOR v){
    printf("<%.2f,%.2f>", AbsisComponent(v), OrdinatComponent(v) );
}

float Magnitude(VECTOR v){
    return sqrt(OrdinatComponent(v)*OrdinatComponent(v) + AbsisComponent(v)*AbsisComponent(v));
}

VECTOR Add(VECTOR a, VECTOR b) {
    VECTOR v;
    OrdinatComponent(v) = OrdinatComponent(a) + OrdinatComponent(b);
    AbsisComponent(v) = AbsisComponent(a) + AbsisComponent(b);
    return v ;
}

VECTOR Substract(VECTOR a, VECTOR b) {
    VECTOR v ;
    OrdinatComponent(v) = OrdinatComponent(a) - OrdinatComponent(b);
    AbsisComponent(v) = AbsisComponent(a) - AbsisComponent(b);
    return v ;
}

float Dot(VECTOR a, VECTOR b) {
    return (AbsisComponent(a)*AbsisComponent(b) + OrdinatComponent(a)*OrdinatComponent(b)) ;
}

VECTOR Multiply(VECTOR v, float s) {
    AbsisComponent(v) = AbsisComponent(v)*s  ;
    OrdinatComponent(v) = OrdinatComponent(v)*s;
    return v ;
}