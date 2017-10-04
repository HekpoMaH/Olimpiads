#include<iostream>
#include<cstring>
#include<string>
#include<vector>
using namespace std;
long long n,ans,c;
long long mod=1000000007,bit[10009];
string s;
int main()
{
    ios::sync_with_stdio(false);
    cin>>s;n=s.size();
    bit[0]=1;
    for(int i=1;i<n;i++)bit[i]=bit[i-1]*2%mod;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='1')
        {
            c=bit[i]*bit[n-i-1]%mod;c*=bit[n-i-1];c%=mod;
            ans+=c;
            ans%=mod;
        }
    }
    cout<<ans<<endl;
}


