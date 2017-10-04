#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<cmath>
#include<cstdio>
using namespace std;
const long long MOD=1000000009;
long long n,m,k,ans;
void read()
{
    scanf("%I64d%I64d%I64d",&n,&m,&k);
}
long long step(int multi)
{
    long long x;
    if(multi==0)return 0;
    if(multi==1)return 2;
    if(multi%2==0)
    {
        x=step(multi/2)%MOD;
        x*=x;
        x%=MOD;
    }
    else
    {
        x=step(multi/2)%MOD;
        x*=x;x%=MOD;
        x*=2;
        x%=MOD;
    }
    return x;
}
int main()
{
    long long rest,multi;
    read();
    rest=n-m;
    if(rest*k>=n)
    {
        cout<<m<<endl;
        return 0;
    }
    ans+=rest*(k-1);
    ans%=MOD;
    m=n-(rest*(k));
    //cout<<m<<endl;
    multi=m/k;
    ans+=m%k;
    //cout<<m%k<<endl;
    ans%=MOD;
    //cout<<ans<<' '<<multi<<endl;
    if(multi>=2)ans+=k*(step(multi+1)-2);
    if(multi==1)ans+=2*k;
    ans%=MOD;
    cout<<ans<<endl;
}
