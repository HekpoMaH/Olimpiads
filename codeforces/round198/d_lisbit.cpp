#include<bits/stdc++.h>
using namespace std;
int a[100009];
int n;
int dp[100009],pos[100009],ans,it[100009],mx2;
int get(int ps)
{
    int mx=0;
    while(ps!=0)
    {
        mx=max(mx,it[ps]);
        ps-=(ps&-ps);
    }
    return mx;
}
void update(int ps,int val)
{
    dp[ps]=val;
    while(ps<=n)
    {
        it[ps]=max(it[ps],val);
        ps+=(ps&-ps);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],pos[a[i]]=i;
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        ans=get(pos[a[i]]-1);
        update(pos[a[i]],ans+1);
        mx2=max(ans+1,mx2);
    }
    cout<<mx2<<endl;
}
