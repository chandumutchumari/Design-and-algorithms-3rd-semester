#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node*next;
};
struct node*top=NULL;
void push(int x){
struct node*newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=x;
newnode->next=top;
top=newnode;
}
void pop(){
struct node*temp;
if(top==NULL){
printf("Stack Underflow\n");
return;
}
temp=top;
printf("Deleted: %d\n",top->data);
top=top->next;
free(temp);
}
void display(){
struct node*temp=top;
if(top==NULL){
printf("Stack is empty\n");
return;
}
while(temp!=NULL){
printf("%d ",temp->data);
temp=temp->next;
}
printf("\n");
}
int main(){
int ch,x;
while(1){
printf("1.Push 2.Pop 3.Display 4.Exit\n");
scanf("%d",&ch);
switch(ch){
case 1:
scanf("%d",&x);
push(x);
break;
case 2:
pop();
break;
case 3:
display();
break;
case 4:
return 0;
}
}
}
