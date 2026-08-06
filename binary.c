#include<stdio.h>
int main(){
int n,a[100],i,key,low=0,high,mid;
scanf("%d",&n);
for(i=0;i<n;i++)scanf("%d",&a[i]);
scanf("%d",&key);
high=n-1;
while(low<=high){
mid=(low+high)/2;
if(a[mid]==key){
printf("Element found at position %d",mid+1);
return 0;
}
if(a[mid]<key)low=mid+1;
else high=mid-1;
}
printf("Element not found");
return 0;
}