#include<stdio.h>
#include<math.h>
void move(int n,char a,char c){
printf("Move disk %d from %c to %c\n",n,a,c);
}
void hanoi(int n,char a,char b,char c){
int i;
char x,y,z,temp;
x=a;
y=b;
z=c;
if(n%2==0){
temp=y;
y=z;
z=temp;
}
for(i=1;i<=pow(2,n)-1;i++){
if(i%3==1){
move((int)log2(i)+1,x,z);
}else if(i%3==2){
move((int)log2(i)+1,x,y);
}else{
move((int)log2(i)+1,y,z);
}
}
}
int main(){
int n;
scanf("%d",&n);
hanoi(n,'A','B','C');
return 0;
}