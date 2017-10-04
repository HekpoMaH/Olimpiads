#include<iostream>
using namespace std;
int n,k;
int a[1009],r,l=-1,mid;
int nxt(int pp,int xx)
{
    while(pp<n&&a[pp]<=xx)xx-=a[pp],pp++;
    return pp;
}
int chk(int x)
{
    int p=1,ans=0;
    while(p<=n)
    {
        p=nxt(p,x);
        p=nxt(p,x)+1;
        ans++;
    }
    return ans;
}
int main()
{
    cin>>n>>k;
    for(int i=1;i<n;i++)cin>>a[i],r+=a[i];
    while(l+1<r)
    {
        mid=(l+r)/2;
        if(chk(mid)>k)l=mid;
        else r=mid;
    }
    cout<<r<<endl;
}
