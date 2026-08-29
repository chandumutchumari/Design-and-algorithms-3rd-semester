#include<stdio.h>
#define SIZE 10
int main(){
    int hash[SIZE],n,key,i,index,j;
    for(i=0;i<SIZE;i++)
        hash[i]=-1;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("Enter elements:\n");
    for(i=0;i<n;i++){
        scanf("%d",&key);
        index=key%SIZE;
        j=0;
        while(hash[(index+j*j)%SIZE]!=-1)
            j++;
        hash[(index+j*j)%SIZE]=key;
    }
    printf("Hash Table:\n");
    for(i=0;i<SIZE;i++)
        printf("%d : %d\n",i,hash[i]);
    return 0;
}