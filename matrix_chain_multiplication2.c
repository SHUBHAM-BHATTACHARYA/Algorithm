#include<stdio.h>
int m[20][20];
long int s[20][20];
void main()
{
    int n,i,a[10];
    printf("Enter No of Matrices:");
    scanf("%d",&n);
    printf("Enter Dimensions:\n");
    for(i=0;i<n+1;i++)
    {
        printf("Enter p%d:",i);
        scanf("%d",&a[i]);
    }
    matrix_chain_multi(a,n);
}
void matrix_chain_multi(int p[],int n)
{
    int i,j,L,k;
    long int q;
    for(i=1;i<=n;i++)
    {
        m[i][i]=0;
    }
    for(L=2;L<=n;L++)
    {
        for(i=1;i<=(n-L+1);i++)
        {
            j=(i+L-1);
            m[i][j]=20000;
            for(k=1;k<=j-1;k++)
            {
                q=m[i][k]+m[k+1][j]+(p[i-1]*p[k]*p[j]);
                if(q < m[i][j])
                {
                    m[i][j]=q;
                    s[i][j]=k;
                }
            }
        }
    }
    printf("Optimal Multiplication Sequence is");
    print_parenthesis(i-1,j,s);
    printf("\nMinimal no of multiplication is %ld",m[1][n]);
}
void print_parenthesis(int i,int j,int s[][20])
{
    if(i==j)
    {
        printf("A%d",i);
    }
    else
    {
        printf("(");
        print_parenthesis(i,s[i][j],s);
        print_parenthesis(s[i][j]+1,j,s);
        printf(")");
    }
}
