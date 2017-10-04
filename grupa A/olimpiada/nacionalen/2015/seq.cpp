//dp[i+1]=((lli)i*dp[i]%mod+((dp[i-2]*(lli)i*((lli)i-1ll))>>1)%mod)%mod;
#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
const int mod=987654321;
const int nmax=1e7+9;
lli dp[nmax];
int main(){
   int n;
   cin>>n;
   dp[0]=1;dp[1]=0;dp[2]=0;
   for(int i=2;i<n;i++){
      lli ii=i;
      dp[i+1]=(ii*dp[i]%mod+((dp[i-2]*((ii*(ii-1ll)>>1)%mod))%mod))%mod;

   }
   cout<<dp[n]%mod<<"\n";
}
