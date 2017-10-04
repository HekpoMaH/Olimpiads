#include<cstdio>
using namespace std;
int n,m,k,sum,a[1024][1024];
void read()
{
    int i,j;
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    {
        scanf("%d",&a[i][j]);
        sum+=a[i][j];
    }
}
void solve()
{
    int i,j,l,h,s=0,ms=-1,g;
    for(i=1;i<=n-k+1;i++)
    {
        if(i==1)
        {
            for(l=1;l<=k;l++)
            for(h=1;h<=k;h++)
            s+=a[l][h];
            g=s;
            if(s>ms)ms=s;

        }
        else
        {
            s=g;
            for(l=1;l<=k;l++)
            {
                s-=a[i-1][l];
                s+=a[i+k-1][l];
            }
            g=s;
            if(s>ms)ms=s;
        }
        for(j=2;j<=m-k+1;j++)
        {
            for(l=i;l<=i+k-1;l++)
            {
                s-=a[l][j-1];
                s+=a[l][j+k-1];
            }
            if(s>ms)ms=s;
        }
    }
    printf("%d\n",sum-ms);
}
int main()
{
    read();
    solve();
    return 0;
}
