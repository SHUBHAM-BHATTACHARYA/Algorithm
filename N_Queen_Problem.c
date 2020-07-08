#include<stdio.h>
#include<math.h>
#define true 1;
#define false 0;
int x[10],count;
int main()
{
    int n;
    printf("Enter the No of Queen:");
    scanf("%d",&n);
     NQueen(1,n);
     return 0;
}
NQueen(k,n)
{
    int i;
    for(i=1;i<=n;i++)
    {
        if(place(k,i))
        {
            x[k]=i;
            if(k==n)
                 print(n);
            else NQueen(k+1,n);
        }

    }
}
place(k,i)
{
    int j;
    for(j=1;j<=k-1;j++)
    {
        if((x[j]==i)||(abs(x[j]-i)==abs(j-k)))
            return false;
    }
    return true;
}
void print(int n)
{
 int i,j;
 printf("\n\nSolution %d:\n\n",++count);

 for(i=1;i<=n;++i)
  printf("\t%d",i);

 for(i=1;i<=n;++i)
 {
  printf("\n\n%d",i);
  for(j=1;j<=n;++j)
  {
   if(x[i]==j)
    printf("\tQ");
   else
    printf("\t-");
  }
 }
}
