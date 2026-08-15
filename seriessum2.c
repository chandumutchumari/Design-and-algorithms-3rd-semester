#include<stdio.h>
#include<math.h>

int main(){
    int x,n,i;
    double sum=0;

    printf("Enter the values of x and n: ");
    scanf("%d %d",&x,&n);

    for(i=0;i<=n;i++){
        sum+=pow(x,i);
    }

    printf("The sum of the series is: %lf",sum);
    return 0;
}
//time complexity is O(n).
