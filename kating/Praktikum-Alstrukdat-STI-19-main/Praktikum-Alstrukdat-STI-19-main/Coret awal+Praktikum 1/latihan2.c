#include<stdio.h>
#include<stdbool.h>
int main(){
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
}