#ifndef jam_H
#define jam_H
#include "boolean.h"

#define Hour(J) (J).HH
#define Minute(J) (J).MM
#define Second(J) (J).SS

typedef struct{
    int HH;
    int MM;
    int SS;
}Jam;

Jam MakeJam(int H,int M, int S);
boolean IsJValid(int H,int M,int S);
void BacaJam(Jam *J);
void TulisJam(Jam J);
int JamToDetik(Jam J);
Jam DetikToJam(int N);
#endif
