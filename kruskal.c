#include<stdio.h>
int parent[20];
int find(int i)
{
    while(parent[i]!=i)
        i=parent[i];
    return i;
}
void unite(int i,int j)
{
    int a=find(i),b=find(j);
    parent[a]=b;
}
int main()
{
    int n,e,i,j,u,v,w,mincost=0,count=0;
    int edge[50][3];
    printf("Enter number of vertices: ");
    scanf("%d",&n);
    printf("Enter number of edges: ");
    scanf("%d",&e);
    printf("Enter edges (u v w):\n");
    for(i=0;i<e;i++)
        scanf("%d%d%d",&edge[i][0],&edge[i][1],&edge[i][2]);
    for(i=0;i<n;i++)
        parent[i]=i;
    for(i=0;i<e-1;i++)
        for(j=0;j<e-i-1;j++)
            if(edge[j][2]>edge[j+1][2])
            {
                int t0=edge[j][0],t1=edge[j][1],t2=edge[j][2];
                edge[j][0]=edge[j+1][0];
                edge[j][1]=edge[j+1][1];
                edge[j][2]=edge[j+1][2];
                edge[j+1][0]=t0;
                edge[j+1][1]=t1;
                edge[j+1][2]=t2;
            }
    printf("Edges in MST:\n");
    for(i=0;i<e&&count<n-1;i++)
    {
        u=edge[i][0];
        v=edge[i][1];
        w=edge[i][2];
        if(find(u)!=find(v))
        {
            unite(u,v);
            printf("%d - %d = %d\n",u,v,w);
            mincost+=w;
            count++;
        }
    }
    printf("Minimum Cost = %d",mincost);
    return 0;
}