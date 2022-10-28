#include<stdio.h>
#include "jam.h"
int main(){
    Jam J1,J2;
    BacaJam(&J1);
    printf("Jam sekarang: ");
    TulisJam(J1);printf("\n");
    printf("Konversi menjadi detik: %d\n",JamToDetik(J1));
    J2=DetikToJam(5000);
    printf("5000 detik sama dengan jam: \n");
    TulisJam(J2);
    return 0;
}
