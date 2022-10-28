#include <stdio.h>
#include <stdlib.h>
void fun(int arr[]){
    int i;
    int size_arr=sizeof(arr)/sizeof(arr[0]);
    printf("%lu\n",sizeof(arr));
    printf("%lu\n",sizeof(arr[0]));
    printf("--------------------\n");
    for(i=0;i<size_arr;i++){
        printf("%d\n",arr[i]);
    }
}
int main(){
   int pro[4]={10,20,30,40};
   printf("%lu\n",sizeof(pro));
   printf("%lu\n",sizeof(pro[0]));
   printf("--------------- Mulai fun\n");
   fun(pro);
   return 0;
}