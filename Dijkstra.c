#include<stdio.h>
void main()
{
    int i,j,n,v,cost[10][10],dist[10];
    printf("Enter the No of Nodes:");
    scanf("%d",&n);
    printf("Enter the Cost of Matrix:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
        }
    }
    printf("Enter the Source Node:");
    scanf("%d",&v);
    dij(v,cost,dist,n);
    printf("\n Shortest Path:");
    for(i=1;i<=n;i++)
    {
        if(i!=v)
            printf("\n%d->%d,cost=%d",v,i,dist[i]);
    }
}
void dij(int v,int cost[10][10],int dist[],int n)
{
    int i,j,s[10],min,u,w;
    for(i=1;i<=n;i++)
    {
        s[i]=0;
        dist[i]=cost[v][i];
    }
    s[v]=1;
    dist[v]=0;
    for(j=2;j<n;j++)
    {
        min=99;
        for(w=1;w<=n;w++)
        {
            if(dist[w]<min && !s[w])
            {
                min=dist[w];
                u=w;
            }
        }
        s[u]=1;
        for(w=1;w<=n;w++)
        {
           if(dist[w]>dist[u]+cost[u][w])
              dist[w]=dist[u]+cost[u][w];
        }
    }
}
