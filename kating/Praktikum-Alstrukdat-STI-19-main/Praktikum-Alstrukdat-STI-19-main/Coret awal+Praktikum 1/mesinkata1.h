#ifndef __MESINKATA1_H_
#define __MESINKATA1_H_

#include "mesinkar.h"

#define NMax 50
#define BLANK ' '

typedef struct{
    char TabKata[NMax];
    int length;
} Kata;

extern boolean EndKata;
extern Kata CKata;

void IgnoreBlank();
void STARTKATA();
void ADVKATA();
void SalinKata();

#endif
