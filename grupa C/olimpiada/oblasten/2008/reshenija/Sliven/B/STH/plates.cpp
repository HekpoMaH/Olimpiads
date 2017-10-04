#include<stdio.h>
#include<stdlib.h>
int main()
{
    int m,n,i,j=0;
    scanf("%d %d",&m,&n);
    int a[m*n];
    for(i=0;i<m*n;i++)
    scanf("%d",&a[i]);
    for(i=0;i<m*n;i+=n)
     if(a[i]==a[i+n]&&a[n-i]==a[2*n-i]||a[i]==a[2*n-i]&&a[i+n]==a[n-i])
         j+=2;
    printf("%d\n",j);

    return 0;
} 
