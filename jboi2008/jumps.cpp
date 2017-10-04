#include<bits/stdc++.h>
using namespace std;
int n;
const int mod=1000000;
int main()
{
    cin>>n;
    long long ans=((n%6+n)/2%mod * ((1+n/6)%mod));
    if(n%6==0)ans++;
    cout<<ans%mod<<endl;
}
