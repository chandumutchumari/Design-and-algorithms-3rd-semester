#include<stdio.h>
#define SIZE 100
int main(){
    int a[SIZE],hash[SIZE],n,T,i,index,j,found=0;
    for(i=0;i<SIZE;i++)
        hash[i]=-1;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("Enter elements:\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter target value: ");
    scanf("%d",&T);
    for(i=0;i<n;i++){
        index=(T-a[i])%SIZE;
        if(index<0)
            index+=SIZE;
        j=0;
        while(hash[(index+j)%SIZE]!=-1){
            if(hash[(index+j)%SIZE]==T-a[i]){
                found=1;
                break;
            }
            j++;
        }
        if(found){
            printf("Two elements are %d and %d\n",T-a[i],a[i]);
            break;
        }
        index=a[i]%SIZE;
        if(index<0)
            index+=SIZE;
        j=0;
        while(hash[(index+j)%SIZE]!=-1)
            j++;
        hash[(index+j)%SIZE]=a[i];
    }
    if(!found)
        printf("No two elements have sum equal to %d\n",T);
    return 0;
}