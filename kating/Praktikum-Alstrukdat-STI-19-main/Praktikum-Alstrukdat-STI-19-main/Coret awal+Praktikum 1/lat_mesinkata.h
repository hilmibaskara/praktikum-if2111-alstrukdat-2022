#ifndef __kata__
#define __kata__
#include"lat_mesinkar.h"
#define Nmax 50
#define blank ' '
typedef struct
{
    char tabkata[Nmax];
    int length;
}kata;
extern boolean endkata;
extern kata ckata;

void startkata();
void ignore_blank();
void advkata();
void salinkata();


#endif