#include<stdio.h>

int main(){
    int a[100],i,j,k,temp,n;

    printf("Enter the size of the array: ");
    scanf("%d",&n);

    printf("Enter the elements of the array: ");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    printf("Enter the value of k: ");
    scanf("%d",&k);

    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(a[i]>a[j]){
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }

    printf("The %dth smallest element is: %d",k,a[k-1]);
    return 0;
}
