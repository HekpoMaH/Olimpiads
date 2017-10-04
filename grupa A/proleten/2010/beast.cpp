#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
const lli mod=1e9+7;
const int nmax=1e6+9;
int n,k;
lli dp[nmax],pw[nmax];
void prep(){
   pw[0]=1;
   for(int i=1;i<=n;i++){
      pw[i]=(pw[i-1]*10LL)%mod;
   }
}
void solve(){
   cin>>n>>k;
   prep();
   dp[0]=1;
   dp[1]=8;
   lli sum=dp[0]+dp[1];
   for(int i=2;i<k;i++){
      dp[i]=pw[i-2]*9LL%mod*9LL%mod;
      sum=(sum+dp[i])%mod;
   }
   if(k==1){
      sum-=dp[0];
   }
   for(int i=k+(k==1);i<n;i++){
      dp[i]=sum*9%mod;
      sum=(sum+dp[i]-dp[i-k]+mod)%mod;
   }
   lli ans=0;
   for(int i=0;i<=n-k;i++){
      ans=(ans+dp[i]*pw[n-k-i])%mod;
   }
   cout<<ans<<"\n";
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   solve();
}
