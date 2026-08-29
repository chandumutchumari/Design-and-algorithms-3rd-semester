#include<stdio.h>
#define SIZE 100
int main(){
    int a[SIZE],hash[SIZE],freq[SIZE],n,i,key,index,j;
    for(i=0;i<SIZE;i++){
        hash[i]=-1;
        freq[i]=0;
    }
    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("Enter elements:\n");
    for(i=0;i<n;i++){
        scanf("%d",&key);
        index=key%SIZE;
        if(index<0)
            index+=SIZE;
        j=0;
        while(hash[(index+j)%SIZE]!=-1&&hash[(index+j)%SIZE]!=key)
            j++;
        if(hash[(index+j)%SIZE]==-1)
            hash[(index+j)%SIZE]=key;
        freq[(index+j)%SIZE]++;
    }
    printf("Frequency of elements:\n");
    for(i=0;i<SIZE;i++)
        if(hash[i]!=-1)
            printf("%d : %d\n",hash[i],freq[i]);
    return 0;
}