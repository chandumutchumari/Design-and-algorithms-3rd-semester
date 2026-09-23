#include<stdio.h>
#define INF 9999
int main()
{
    int n,i,j,u,v,min,mincost=0,count=0;
    int cost[20][20],visited[20]={0};
    printf("Enter number of vertices: ");
    scanf("%d",&n);
    printf("Enter cost adjacency matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&cost[i][j]);
    visited[0]=1;
    printf("Edges in MST:\n");
    while(count<n-1)
    {
        min=INF;
        u=v=-1;
        for(i=0;i<n;i++)
            if(visited[i])
                for(j=0;j<n;j++)
                    if(!visited[j]&&cost[i][j]<min&&cost[i][j]!=0)
                    {
                        min=cost[i][j];
                        u=i;
                        v=j;
                    }
        if(u==-1)
            break;
        printf("%d - %d = %d\n",u,v,min);
        mincost+=min;
        visited[v]=1;
        count++;
    }
    printf("Minimum Cost = %d",mincost);
    return 0;
}