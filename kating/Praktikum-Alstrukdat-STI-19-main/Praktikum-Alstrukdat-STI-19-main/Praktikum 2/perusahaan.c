#include<stdio.h>
#include"list.h"
int main(){
    int N;
    IdxType i;
    List L1,L2,L3;
    scanf("%d",&N);
    MakeEmpty(&L1);
    MakeEmpty(&L2);
    MakeEmpty(&L3);
    SetNeff(&L1,N);
    SetNeff(&L2,N);
    SetNeff(&L3,N);
    for (i=FirstIdx(L1);i<L1.Neff;i++){
        scanf("%d",&L1.A[i]);
    }
    for (i=FirstIdx(L2);i<L2.Neff;i++){
        scanf("%d",&L2.A[i]);
    }
    for (i=FirstIdx(L2);i<L2.Neff;i++){
        L3.A[i]=L1.A[i]+L2.A[i];
    }
    for (i=FirstIdx(L3);i<L3.Neff;i++){
        if (i==L3.Neff-1){
            printf("%d %d",i+1,L3.A[i]);
        }
        else{
            printf("%d %d\n",i+1,L3.A[i]);
        }
    }
    return 0;
}