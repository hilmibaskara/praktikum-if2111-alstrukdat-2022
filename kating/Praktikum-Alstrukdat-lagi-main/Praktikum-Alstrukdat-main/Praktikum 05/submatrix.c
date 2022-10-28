//Nama : Saul Sayers
//NIM  : 13520094
//Kelas: K02 Alstrukdat
//PRAKTIKUM 5

#include "matrix.h"
#include <stdio.h>

int main() {
    int M,N,maks,i,j,k,l,total,TC,ujikasus;
    Matrix matriks;
    scanf("%d", &TC);
    for (ujikasus=0;ujikasus<TC;ujikasus++){
        scanf("%d", &N);
        maks = 0;
        CreateMatrix(N,N,&matriks);
        readMatrix(&matriks,N,N);
        scanf("%d", &M);
        for (i=0;i<=N-M;i++){
            for (j=0;j<=N-M;j++){
                total = 0;
                for(k=0;k<M;k++){
                    for(l=0;l<M;l++){
                        total += ELMT(matriks,i+k,j+l);
                    }
                }
                if (total > maks) {
                    maks = total;
                }
            }
        }
        printf("%d\n",maks);
    }
    return 0;
}