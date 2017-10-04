#include<bits/stdc++.h>
using namespace std;
long long a,b,n;
long long calcforoddn(long long st,long long le)
{
    //cout<<"st="<<st<<" le="<<le<<endl;
    long long beg,xr;
    if(st&1)
    {
        //cout<<"le%4="<<(le%4)<<" le&3="<<(le&3)<<endl;
        beg=st+le-(le&3);
        if(beg>=st+le)beg-=4;
        xr=st;

    }
    else
    {
        beg=st+le-1-(le&3);
        xr=0;
    }//cout<<"beg="<<beg<<endl;
    for(long long i=beg+1;i<=st+le-1;i++)xr^=i;
        //cout<<"xr="<<xr<<endl;
        return xr;

}
long long calceven(long long st,long long le)
{
    if(le%4==0&&st%2==0)return 0;
    if(le%4!=0&&st%2==0)return 1;
    if(le%4==2)return st^(st+le-1);
    return st^(st+le-1)^1;
}
int main()
{
    cin>>a>>b>>n;long long t=a&b,s;
    if(n%2==1)
    {
        cout<<max(calcforoddn(b-n+1,n),calcforoddn(b-n,n))<<endl;
    }
    //cout<<(~n)^a<<endl;
    a=max(a,t-n+1);
    b=min(b,t+n-1);
    long long ans=0;
    for(long long i=a;i<=b;i++)
    {
        ans=max(ans,calceven(i,n));
    }
    cout<<ans<<endl;
}
