#include<iostream>
#include<string>
using namespace std;
string s;
int m;
int a,b,ss;
long long h[100006],p=101,mod=1000000009,pw[100006],ms;
long long gth(int l,int r)
{
    if(l==0)return h[r];
    return (h[r]+mod-(h[l-1]*pw[r-l+1])%mod)%mod;
}
void check(long long mid,long long &lef,long long &righ)
{
    long long a1,a2;
    a1=gth(a,a+mid-1);a2=gth(b,b+mid-1);
    if(a1==a2)
    {
        if(ms<mid)ms=mid;
        lef=mid+1;
    }
    else
    {
        righ=mid-1;
    }
}
void solve()
{
    ms=-1;
    long long lef=0,righ=min(ss-a,ss-b),mid;
    while(lef<=righ)
    {
        mid=(lef+righ)/2;
        check(mid,lef,righ);
    }
    cout<<ms<<endl;
}
int main()
{
    cin>>s;
    cin>>m;
    h[0]=(int)(s[0]-'a');
    ss=s.size();
    pw[0]=1;
    for(int i=1;i<ss;i++)pw[i]=pw[i-1]*p%mod;
    for(int i=1;i<ss;i++)
    {
        h[i]=(h[i-1]*p+(int)(s[i]-'a'))%mod;
    }
    for(int i=1;i<=m;i++)
    {
        cin>>a>>b;
        solve();
    }
    
    return 0;
}