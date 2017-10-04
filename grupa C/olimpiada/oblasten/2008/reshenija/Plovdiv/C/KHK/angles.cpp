#include<stdio.h>
#include<iostream>
using namespace std;
int a[1001][1001],b[1001][1001];
int main()
{
    int x,y,i,j,n,k,ma=-2000000000,mi,mj;
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&x);
            if(j==0)
            b[i][j]=x;
            else b[i][j]=b[i][j-1]+x;
            if(i==0)
            a[i][j]=x;
            else a[i][j]=a[i-1][j]+x;
        }
    }      
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    {
        int s1,s2;
        if(i==0) s1=a[k][j];
        else
        {
            if(i+k>=n) s1=a[n-1][j]-a[i-1][j];
            else s1=a[i+k][j]-a[i-1][j];
        }
        if(j+k>=n) s2=b[i][n-1]-b[i][j];
        else s2=b[i][j+k]-b[i][j];
        if(s1+s2>ma){ ma=s1+s2; mi=i; mj=j; }
        else
        if(s1+s2==ma)
        {
            if(i<mi)
            { ma=s1+s2; mi=i; mj=j; }
            else
            if(mi==i&&mj>j) { ma=s1+s2; mi=i; mj=j; }
        }
    }
    printf("%d %d\n",mi+1,mj+1);
    return 0;
}

                
        
            
            
