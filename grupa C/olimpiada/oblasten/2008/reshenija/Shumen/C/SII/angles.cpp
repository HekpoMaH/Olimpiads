#include<iostream>
#include<cstdio>
using namespace std;
int n,b[1024][1024],a[1024][1024],k1,k2,p1,p2,i,j,k,c[1024][1024],m1,m2;
long long m,p;
int main()
{
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    {
        scanf("%d",&a[i][j]);
        b[i][j]=b[i][j-1]+a[i][j];
    }
    for(j=1;j<=n;j++)
    for(i=1;i<=n;i++)
    {
        c[i][j]=c[i-1][j]+a[i][j];
    }
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    {
        k1=i;
        p1=j;
        k2=i+k;
        p2=j+k;
        if(k2>n)k2=n;
        if(p2>n)p2=n;
        p=b[i][p2]-b[i][p1]+c[k2][j]-c[k1][j]+a[i][j];
        if(p>m){m=p;m1=i;m2=j;}
    }
    cout<<m1<<' '<<m2<<endl;
}
