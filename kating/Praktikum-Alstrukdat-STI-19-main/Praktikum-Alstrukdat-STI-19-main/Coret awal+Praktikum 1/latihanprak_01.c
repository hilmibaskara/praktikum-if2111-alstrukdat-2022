#include<stdio.h>
#include<stdbool.h>
bool IsWithinRange(float a){
    return (a>=0)&&(a<=4);
}
bool IsSame(int a,int b){
    return a==b;
}
int main(){
    /*
    NOMOR 1:
    printf("Hello, World!\n");

    NOMOR 2:
    int a,b,c;
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    if ((a>=b)&&(a>=c)){
        printf("%d\n",a);
    }
    else if((b>=a)&&(b>=c)){
        printf("%d\n",b);
    }
    else{
        printf("%d\n",c);
    }

    NOMOR 3:
    float suhu;
    char kar;
    scanf("%f\n",&suhu);
    scanf("%c",&kar);
    if (kar=='R'){
        suhu=suhu*0.8;
    }
    else if(kar=='K'){
        suhu=suhu+273.15;
    }
    else{
        suhu=(1.8*suhu)+32;
    }
    printf("%.2f\n",suhu);

    NOMOR 4:
    float ip,total;
    int count,lulus,gagal;
    count=0;
    lulus=0;
    gagal=0;
    total=0;
    scanf("%f",&ip);
    while (ip!=-999){
        if (IsWithinRange(ip)){
            count+=1;
            if (ip>=2.75){
                lulus+=1;
            }
            total+=ip;
        }
        scanf("%f",&ip);
    }
    if (count==0){
        printf("Tidak ada data\n");
    }
    else{
        gagal=count-lulus;
        printf("%d\n",count);
        printf("%d\n",lulus);
        printf("%d\n",gagal);
        printf("%.2f\n",total/count);
    }

    NOMOR 5:
    float ip,pot;
    scanf("%f",&ip);
    scanf("%f",&pot);
    if ((ip>=3.5)&&(ip<=4)){
        printf("4\n");
    }
    else if((ip<2)&&(ip>=0)){
        printf("2\n");
    }
    else if((ip>=2)&&(ip<3.5)){
        if (pot<5){
            printf("1\n");
        }
        else{
            printf("0\n");
        }
    }
    else{
        printf("0\n");
    }

    NOMOR 6:
    int n,mid,i,j,minus;
    scanf("%d",&n);
    if (n%2==1){
        mid=(n-1)/2;
        minus=1;
        for (i=0;i<=mid;i++){
            for(j=0;j<n;j++){
                if((j>=(mid-i))&&(j<=(mid+i))){
                    printf("*");
                }
                else{
                    printf(" ");
                }
            }
            printf("\n");
        }
        for (i=0;i<mid;i++){
            for (j=0;j<n;j++){
                if((j>=minus)&&(j<=(n-1-minus))){
                    printf("*");
                }
                else{
                    printf(" ");
                }
            }
            minus+=1;
            printf("\n");
        }
    }
    else{
       printf("Masukkan tidak valid\n");
    }
     
    CORET2AN INI GUS. GAUSA DIPEDULIIN :)
     
    int n,i,j,start,tengah,rata;
    scanf("%d",&n);
    start=n-1;
    rata=0;
    tengah=(n-1)/2;
    for (i=0;i<n;i++){
        for (j=0;j<=i;j++){
            printf("*");
        }
        printf("\n");
    }
    printf("-------------------\n");
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            if(j>=start){
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        start-=1;
        printf("\n");
    }
    printf("-------------------\n");
    for (i=0;i<=tengah;i++){
        for (j=0;j<n;j++){
            if ((j>=rata)&&(j<(n-rata))){
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        rata+=1;
        printf("\n");
    }
    int num,n,i;
    printf("Masukkan bilangan yang ingin dikali: ");
    scanf("%d",&num);
    printf("Masukkan berapa kali: ");
    scanf("%d",&n);
    for (i=1;i<=n;i++){
        if (i==n){
            printf("%d x %d = %d",num,i,num*i);
        }
        else{
            printf("%d x %d = %d, ",num,i,num*i);
        }
    }
    printf("\n");*/
    return 0;
}
