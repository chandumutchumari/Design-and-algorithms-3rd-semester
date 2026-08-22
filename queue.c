#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node*next;
};
struct node*front=NULL;
struct node*rear=NULL;
void enqueue(int x){
struct node*newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=x;
newnode->next=NULL;
if(rear==NULL){
front=rear=newnode;
}else{
rear->next=newnode;
rear=newnode;
}
}
void dequeue(){
struct node*temp;
if(front==NULL){
printf("Queue Underflow\n");
return;
}
temp=front;
printf("Deleted: %d\n",front->data);
front=front->next;
if(front==NULL)
rear=NULL;
free(temp);
}
void display(){
struct node*temp=front;
if(front==NULL){
printf("Queue is empty\n");
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
printf("1.Enqueue 2.Dequeue 3.Display 4.Exit\n");
scanf("%d",&ch);
switch(ch){
case 1:
scanf("%d",&x);
enqueue(x);
break;
case 2:
dequeue();
break;
case 3:
display();
break;
case 4:
return 0;
}
}
}