#include<bits/stdc++.h>
using namespace std;
int dp[100009];
int a[100009],br;
int n,mx;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    if(n==1)cout<<1<<endl,exit(0);
    if(n==2)cout<<2<<endl,exit(0);
    for(int i=1;i<=n;i++)cin>>a[i];
    br=2;
    for(int i=3;i<=n;i++)
    {
        //cout<<i<<" "<<br<<endl;
        if(a[i]==a[i-1]+a[i-2])br++;
        else br=2;
        mx=max(mx,br);
    }
    for(int i=1;i<=n;i++)mx=max(mx,dp[i]);
    cout<<mx<<endl;
    return 0;
}
