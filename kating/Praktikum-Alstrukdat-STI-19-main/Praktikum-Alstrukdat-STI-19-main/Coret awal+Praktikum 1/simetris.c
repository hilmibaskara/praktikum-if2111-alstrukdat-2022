#include<stdio.h>
#include<stdbool.h>
/*int main(){
    int x,i,a[6]={4,3,5,2,1};
    bool ketemu=true;
    scanf("%d",&x);
    for (i=0;i<6;i++){
        if (a[i]==x){
            ketemu=false;
        }
    }
    if (ketemu){
        a[5]=x;
        printf("%d\n",a[5]);
    }
    else{
        printf("Elemen double\n");
    }
    return 0;
}*/

/*int main(){
    int n,x,count,i,j;
    count=0;
    printf("Masukkan panjang array: ");
    scanf("%d",&n);
    printf("Masukkan nilai yang ingin dihitung: ");
    scanf("%d",&x);
    int a[n];
    printf("Masukkan nilai array: ");
    for (i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for (i=0;i<n;i++){
        if (a[i]==x){
            count+=1;
        }
    }
    printf("%d\n",count);
    return 0;
}*/
/*int main(){
    int n,x,i,j;
    printf("Masukkan panjang array: ");
    scanf("%d",&n);
    printf("Masukkan nilai yang ingin dicari: ");
    scanf("%d",&x);
    int a[n];
    printf("Masukkan nilai array: ");
    for (i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    j=0;
    while ((j<(n-1))&&(a[j]!=x)){
        j+=1;
    }
    if (a[j]==x){
        printf("%d\n",j);
    }
    else{
        printf("Tidak ditemukan\n");
    }
    return 0;
}
*/
/*int kali2(int n[]);

int main(){
    int i,total;
    int a[10];
    for (i=0;i<5;i++){
        scanf("%d",&a[i]);
    }
    total=kali2(a);
    printf("%d\n",total);
    return 0;
}

int kali2(int n[]){
    int i,x,sum;
    x=0;
    sum=0;
    for (i=0;i<5;i++){
        sum+=n[i];
    }
    return sum;
}*/



/*int main(){
    int n1,n2,i;
    bool check=true;
    printf("Masukkan panjang list pertama:");
    scanf("%d",&n1);
    printf("Masukkan panjang list kedua:");
    scanf("%d",&n2);
    int a[n1],b[n2];
    for (i=0;i<n1;i++){
        scanf("%d",&a[i]);
    }
    for (i=0;i<n2;i++){
        scanf("%d",&b[i]);
    }
    if (n1!=n2){
        printf("List tidak sama\n");
    }
    else{
        for (i=0;i<n1;i++){
            if (a[i]!=b[i]){
                check=false;
            }
        }
        if (check){
            printf("Sama\n");
        }
        else{
            printf("Berbeda\n");
        }
    }
    return 0;
}*/

/*int main(){
    int n,i;
    scanf("%d",&n);
    int a[n],b[n],c[n];
    printf("Isi elemen pertama\n");
    for (i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Isi elemen kedua\n");
    for (i=0;i<n;i++){
        scanf("%d",&b[i]);
    }
    for (i=0;i<n;i++){
        c[i]=a[i]+b[i];
    }
    printf("Hasil penjumlahan kedua list\n");
    for (i=0;i<n;i++){
        printf("%d\n",c[i]);
    }
    return 0;
}*/


/*int main(){
    int i,j,n,count;
    scanf("%d",&n);
    int a[n];

    count=0;
    for (j=0;j<n;j++){
        scanf("%d",&a[j]);
    }
    for (j=0;j<n;j++){
        if (a[j]==a[n-1-j]){
            count+=1;
        }
    }
    printf("%d\n",count);
    if(n==count){
        printf("Simetris\n");
    }
    else{
        printf("Tidak simetris\n");
    }
    return 0;
}*/
