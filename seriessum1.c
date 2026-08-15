#include<stdio.h> 
#include<math.h> 
int main(){ 
    int x,n,sum;
    printf("Enter the values of x and n: "); 
    scanf("%d %d",&x,&n); 
    if(x==1){ 
        sum=n+1; 
    }else{ 
        sum= (pow(x,n+1)-1)/(x-1); 
    } 
    printf("The sum of the series is: %d",sum); 
return 0; 
} 
//time complexity of this code is O(1). 
