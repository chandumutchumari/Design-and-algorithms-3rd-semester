
#include<stdio.h>
#include<stdlib.h>

int board[20][20],n;

int isSafe(int row,int col)
{
int i,j;

for(i=0;i<col;i++)
if(board[row][i])
return 0;

for(i=row,j=col;i>=0&&j>=0;i--,j--)
if(board[i][j])
return 0;

for(i=row,j=col;i<n&&j>=0;i++,j--)
if(board[i][j])
return 0;

return 1;
}

int solveNQueen(int col)
{
int i,j;

if(col==n)
return 1;

for(i=0;i<n;i++)
{
if(isSafe(i,col))
{
board[i][col]=1;

if(solveNQueen(col+1))
return 1;

board[i][col]=0;
}
}

return 0;
}

int main()
{
int i,j;

printf("Enter number of queens: ");
scanf("%d",&n);

if(n<1||n>20)
{
printf("Invalid input");
return 0;
}

if(solveNQueen(0))
{
printf("Solution:\n");

for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
printf("%d ",board[i][j]);

printf("\n");
}
}
else
printf("No solution exists");

return 0;
}
