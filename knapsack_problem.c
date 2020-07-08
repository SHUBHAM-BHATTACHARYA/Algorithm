#include<stdio.h>
int main()
{
    int i,j,n;
    float p[10],w[10],r[10],tmp;
    printf("Enter the No of object:");
    scanf("%d",&n);
    printf("Enter the Profit:");
    for(i=0;i<n;i++)
        scanf("%f",&p[i]);
    printf("Enter the Weight:");
    for(i=0;i<n;i++)
        scanf("%f",&w[i]);
    for(i=0;i<n;i++)
        r[i]=(p[i]/w[i]);
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<=n-1-i;j++)
        {
            if(r[j]<r[j+1])
            {

                tmp=r[j];
                r[j]=r[j+1];
                r[j+1]=tmp;

                tmp=p[j];
                p[j]=p[j+1];
                p[j+1]=tmp;

                tmp=w[j];
                w[j]=w[j+1];
                w[j+1]=tmp;
            }
        }
    }
    printf("\nRatio in Descending Order:");
    for(i=0;i<n;i++)
        printf("%f\t",r[i]);
    knapsack(p,w,n);
}
void knapsack(float p[10],float w[10],int n)
{
    int i,j,m;
    float u,v,x[10];
    printf("\nEnter the Maximum Capacity of Knapsack:");
    scanf("%d",&m);
    for(i=0;i<n;i++)
    {
        x[i]=0.0;
    }
    u=m;
    v=0.0;
    for(i=0;i<n;i++)
    {
        if(w[i]>u)
            break;
        else
        {
            x[i]=1.0;
            u=u-w[i];
            v=v+(p[i]*x[i]);
        }
    }
    if(i<n)
        x[i]=u/w[i];
    v=v+(p[i]*x[i]);
    for(i=0;i<n;i++)
    {
        printf("%f\t",x[i]);
        printf("%f\n",v);
    }
}
