#include<iostream>
#include<string>
using namespace std;
string s;
long long dp[1<<6];
const long long mod=9007199254740991LL;
int n;
long long tmp,sum;
int main()
{
    cin>>s;
    n=s.size();
    for(int i=n-1;i>=0;--i)
    {
        tmp=1;tmp+=sum;tmp%=mod;
        sum-=dp[s[i]-'a'];sum+=mod;sum%=mod;
        sum+=tmp;sum%=mod;
        dp[s[i]-'a']=tmp;
    }
    cout<<sum<<endl;
}
