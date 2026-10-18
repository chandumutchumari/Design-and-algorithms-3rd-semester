#include<stdio.h> 
#include<stdlib.h> 
struct Node{ 
int data; 
char ch; 
struct Node *left,*right; 
}; 
struct Node* newNode(int data,char ch){ 
struct Node* node=(struct Node*)malloc(sizeof(struct Node)); 
node->data=data; 
node->ch=ch; 
node->left=node->right=NULL; 
return node; 
} 
void sort(struct Node* a[],int n){ 
int i,j; 
struct Node* temp; 
for(i=0;i<n-1;i++) 
for(j=0;j<n-i-1;j++) 
if(a[j]->data>a[j+1]->data){ 
temp=a[j]; 
a[j]=a[j+1]; 
a[j+1]=temp; 
} 
} 
void printCodes(struct Node* root,int code[],int top){ 
int i; 
if(root->left){ 
code[top]=0; 
printCodes(root->left,code,top+1); 
} 
if(root->right){ 
code[top]=1; 
printCodes(root->right,code,top+1); 
} 
if(!root->left&&!root->right){ 
printf("%c: ",root->ch); 
for(i=0;i<top;i++) 
printf("%d",code[i]); 
printf("\n"); 
} 
} 
int main(){ 
int n,i,code[100]; 
char ch; 
struct Node* a[100]; 
printf("Enter number of characters: "); 
scanf("%d",&n); 
printf("Enter character and frequency:\n"); 
for(i=0;i<n;i++){ 
scanf(" %c%d",&ch,&code[i]); 
a[i]=newNode(code[i],ch); 
} 
while(n>1){ 
sort(a,n); 
struct Node* left=a[0]; 
struct Node* right=a[1]; 
struct Node* parent=newNode(left->data+right->data,'$'); 
parent->left=left; 
parent->right=right; 
a[0]=parent; 
for(i=1;i<n-1;i++) 
a[i]=a[i+1]; 
n--; 
} 
printf("Huffman Codes:\n"); 
printCodes(a[0],code,0); 
return 0; 
} 
