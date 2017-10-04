#include<bits/stdc++.h>
using namespace std;
const int nmax=109;
pair<int,int> sug[nmax];
int n,s;
int dp[nmax];
int main(){
   cin>>n>>s;
   for(int i=1;i<=n;i++){
      cin>>sug[i].second>>sug[i].first;
   }
   int ans=-1;
   for(int i=1;i<=n;i++){
      if(sug[i].first!=0&&sug[i].second+min(sug[i].first,1)<=s)ans=max(ans,100-sug[i].first);
      if(sug[i].first==0&&sug[i].second+min(sug[i].first,1)<=s)ans=max(ans,0);
   }
   cout<<ans<<"\n";
   return 0;
   memset(dp,-1,sizeof(dp));
   dp[0]=0;
   for(int i=1;i<=s;i++){
      for(int j=1;j<=n;j++){
         int dlp=sug[j].second+min(sug[j].first,1);
         if(i-dlp<0)continue;
         if(sug[j].first!=0)dp[i]=max(dp[i],dp[i-dlp]+100-sug[j].first);
         else dp[i]=max(dp[i],dp[i-dlp]);
      }
      if(i!=1)dp[i]=max(dp[i],dp[i-1]);
   }
   cout<<dp[s]<<"\n";
}
