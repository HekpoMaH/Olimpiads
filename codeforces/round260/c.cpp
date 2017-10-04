#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+9;
long long dp[nmax];
long long used[nmax];
int n,a;
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   for(int i=1;i<=n;i++){
      cin>>a;
      used[a]++;
   }
   dp[1]=used[1];
   for(long long i=2;i<=nmax-9;i++){
      dp[i]=used[i]*i+dp[i-2];
      dp[i]=max(dp[i],dp[i-1]);
   }
   cout<<dp[nmax-9]<<"\n";
}
