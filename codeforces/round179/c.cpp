#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#include<map>
using namespace std;
long long n,m,k;
long long a[100009],b[100009],p[100009];
long long l[100009],r[100009],d[100009];
//int x[100009],y[100009];
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        //upd(i,a[i]);
    }
    for(int i=1;i<=m;i++)
    {
        cin>>l[i]>>r[i]>>d[i];
    }
    for(int i=1;i<=k;i++)
    {
        int x,y;
        cin>>x>>y;
        p[x]++;p[y+1]--;
    }
    for(int i=1;i<=m;i++)p[i]+=p[i-1];
    for(int i=1;i<=m;i++)
    {
        b[l[i]]+=d[i]*p[i];
        b[r[i]+1]-=d[i]*p[i];
    }
    for(int i=1;i<=n;i++)b[i]+=b[i-1];
    for(int i=1;i<=n;i++)
    {
        cout<<a[i]+b[i]<<" ";
    }
    cout<<endl;
}

