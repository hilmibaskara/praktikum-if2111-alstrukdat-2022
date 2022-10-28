/*#include<stdio.h>
#include<stdbool.h>
int main(){
    int n,i,j,count,check;
    bool found;
    scanf("%d",&n);
    int a[n],l[n];
    count=0;
    for (i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for (i=0;i<n;i++){
        check=a[i];
        found=true;
        j=i+1;
        while ((j<n)&&(found)){
            if (a[j]==check){
                count=count+1;
                found=false;
            }
            j=j+1;
        }
    }
    printf("%d\n",count);
    return 0;
}*/
#include <stdio.h>

void main()
{
    int arr1[100];
	int arr2[100];
	int arr3[100];
    int n,mm=1,ctr=0;
    int i, j;	
	
	
       printf("\n\nCount total number of duplicate elements in an array:\n");
       printf("---------------------------------------------------------\n");	

       printf("Input the number of elements to be stored in the array :");
       scanf("%d",&n);
   
       printf("Input %d elements in the array :\n",n);
       for(i=0;i<n;i++)
        {
	      printf("element - %d : ",i);
	      scanf("%d",&arr1[i]);
	    }
/*----------------- copy in other array ------------------------------------*/
		for(i=0;i<n; i++)
        {
		arr2[i]=arr1[i];
		arr3[i]=0;
        }
/*------------------- mark the elements are duplicate -------------------------*/
	for(i=0;i<n; i++)
        {
		for(j=0;j<n;j++)
			{
				if(arr1[i]==arr2[j])
				{
				arr3[j]=mm;
				mm++;
				}
			}
			mm=1;
        }		
/*--------------- Prints the array ------------------------------------*/
   for(i=0; i<n; i++)
    {
      if(arr3[i]==2){ctr++;}  
    }
      printf("The total number of duplicate elements found in the array is: %d \n", ctr);
    
	  printf("\n\n");		
}
