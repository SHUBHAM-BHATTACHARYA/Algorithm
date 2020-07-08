#include<stdio.h>
int toh(int,char,char,char);
int main()
{
    int disk;
    char source='S',temp='T',dest='D';
    printf("Enter the NO. of disks");
    scanf("%d",&disk);
    printf("Sequence is :\n");
    toh(disk,source,temp,dest);
}
int toh(int disk,char source,char temp,char dest)
{
    if(disk==1)
        printf("Move disk %d from %c to %c\n",disk,source,dest);
        else
        {
            toh(disk-1,source,dest,temp);
            printf("Move disk %d from %c to %c\n",disk,source,dest);
            toh(disk-1,temp,source,dest);
        }
}

