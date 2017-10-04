#include<iostream>
#include<algorithm>
#define MAXN 512
#define MAXX 2000000000.000
using namespace std;
int n,p;
double DP[MAXN][MAXN];
double a[MAXN];
double c[MAXN][MAXN];
void read()
{
    int i;
    cin>>n>>p;
    for(i=0;i<n;++i)cin>>a[i];
}
double calc(int x,int y)
{
    int i;
    double res=0,s=0;
    for(i=x;i<=y;++i)s+=a[i];
    s/=(double)(y-x+1);
    for(i=x;i<=y;++i)res+=(a[i]-s)*(a[i]-s);
    return res;
}
void solve()
{
    int i,j,k;
    for(i=0;i<n;++i)
        for(j=i;j<n;++j)c[i][j]=calc(i,j);
    for(i=0;i<n;++i)
        for(j=1;j<=p;++j)DP[i][j]=MAXX;
    for(i=0;i<n;++i)DP[i][1]=c[0][i];
    for(i=0;i<n;++i)
        for(j=2;j<=min(p,i+1);++j)
        {
            for(k=0;k<i;++k)DP[i][j]=min(DP[i][j],DP[k][j-1]+c[k+1][i]);
        }
    printf("%.4lf\n",DP[n-1][p]);
}
int main()
{
    read();
    solve();
    return 0;
}
