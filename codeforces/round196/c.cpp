#include<bits/stdc++.h>
using namespace std;
long long x,n,m,k;
const long long mod=1000000009LL;
long long fp2(long long st)
{
    long long re=1,wa=2;
    while(st!=0)
    {
        if(st%2==1)re=(re*wa)%mod;
        wa=(wa*wa)%mod;
        st/=2;
    }
    return re%mod;
}
int main()
{
    cin>>n>>m>>k;
    x=max(0LL, m - (n - n% k) / k * (k-1) - n % k);
    //cout<<m<<" "<<(n-n%k)/k*(k-1)<<" "<<n%k<<endl;
    //cout<<x<<" "<<fp2(x+1)<<endl;
    //cout<<fp2(1)<<" "<<fp2(4)<<" "<<fp2(10)<<endl;
    long long one=((fp2(x+1)+mod-2)*k)%mod,two=((m%mod-x*k%mod))%mod;
    cout<<(one+two)%mod<<endl;
}
