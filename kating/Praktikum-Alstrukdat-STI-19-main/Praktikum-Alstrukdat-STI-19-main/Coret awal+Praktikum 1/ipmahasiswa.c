#include<stdio.h>
#include"boolean.h"
int IsWithinRange(float x){
    return x>=0 && x<=4;
}
int main(){
    float ip,total,rata;
    int count,lulus,gagal;
    scanf("%f",&ip);
    count=0;lulus=0;gagal=0;
    while (ip!=-999){
        if(IsWithinRange(ip)){
            count+=1;
            total+=ip;
            if (ip>=2.75){
                lulus+=1;
            }
            else{
                gagal+=1;
            }
        }
        scanf("%f",&ip);
    }
    if (count==0){
        printf("Tidak ada data yang dimasukkan");
    }
    else{
        rata=total/count;
        printf("%d\n",count);
        printf("%d\n",lulus);
        printf("%d\n",gagal);
        printf("%.2f\n",rata);
    }
    return 0;
}