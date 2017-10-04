#include<cstdio>
#include<map>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
int a[4020][4020];
map<int,int>m;
int main()
{
    int n,i,j,b,o=0;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>b;
        if(m[b]==0)m[b]=i;
        b=m[b];
        a[b][b]++;
        for(j=1;j<=n;j++)
        if(a[b][j]%2==0 && b!=j)a[b][j]++;
        for(j=1;j<=n;j++)
        if(a[j][b]%2==1 && b!=j)a[j][b]++;
    }
    if(n==1 || n==2)
    {
        cout<<n;
        return 0;
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)o=max(o,a[i][j]),cout<<a[i][j];
        cout<<endl;
    }
    cout<<o<<endl;
}
