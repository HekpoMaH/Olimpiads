#include<iostream>
#include<cstdio>
using namespace std;
long long n,p;
struct za
{
    long long t1,t2;
};
za a[123456];
bool chk(long long x)
{
    long long br=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i].t2<x)br+=(x-a[i].t2)/a[i].t1;
    }
    if(br>=p)return true;
    return false;
}
void solve()
{
    long long l=1,r=1;
    for(int i=1;i<=45;i++)r*=2;
    long long mid;
    long long ans;
    //cout<<r<<endl;
    while(l<=r)
    {
        mid=(l+r)/2;
        //cout<<mid<<" "<<chk(mid)<<endl;
        if(chk(mid)==true)ans=mid,r=mid-1;
        else l=mid+1;
    }
    cout<<ans<<endl;
}
int main()
{
    scanf("%lld%lld",&n,&p);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld%lld",&a[i].t1,&a[i].t2);
    }
    solve();//batkaaaaaaaaa
    //cout<<chk(30)<<endl;
}

