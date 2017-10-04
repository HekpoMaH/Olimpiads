#include<iostream>
#include<map>
#include<string>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;
long long n,a,b,aa,bb;
long long mod=1000000007;
long long dp[9000009],ans,nn,st[9000009],br;
int main()
{
    cin>>a>>b>>n;
    st[0]=1;
    for(int i=1;i<=9000009;i++)
    {
        st[i]=st[i-1]*i;
    }
    dp[a]=1;dp[b]=1;
    for(int i=1;i<=9000009;i++)
    {
        if(dp[i]==1)
        {
            if(i*10+a<=9000009)dp[i*10+a]=1;
            if(i*10+b<=9000009)dp[i*10+b]=1;
        }
    }
    for(int i=0;i<=n;i++)
    {
        long long x,y,sum;
        x=i,y=n-i;
        sum=x*a+y*b;
        //cout<<x<<" "<<y<<" "<<sum<<" "<<dp[sum]<<endl;
        if(dp[sum]==1)
        {
            ans+=(st[n]/(st[x]*st[y]));
            //ans%=mod;
        }
    }
    cout<<ans<<endl;
}

