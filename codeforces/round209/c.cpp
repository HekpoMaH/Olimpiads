#include<bits/stdc++.h>
using namespace std;
int n,x;
const long long mod=1000000007;
int a[100009];
long long sum;
long long fastpow(long long c,long long st)
{
    long long wtf=c,re=1;
    while(st!=0)
    {
        if(st&1)
        {
            re*=wtf;
            re%=mod;
        }
        wtf*=wtf;
        wtf%=mod;
        st>>=1;
    }
    return re%mod;
}
long long gcd(long long a,long long b)
{
    a%=mod;
    b%=mod;
    long long r;
    while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
void readsolve()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>x;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];sum+=a[i];
    }
    long long ms=(sum-a[n]),su=0;
    for(int i=1;i<=n;i++)
    {
        su+=fastpow(x,sum-a[i]-ms);
        //cout<<x<<" "<<sum-a[i]-ms<<endl;
        su%=mod;
    }
    //cout<<fastpow(4,3)<<endl;
    //cout<<su<<" "<<ms<<endl;
    cout<<(fastpow(x,ms)*gcd(su,fastpow(x,a[n])))%mod<<endl;
}
int main()
{
    readsolve();
}
