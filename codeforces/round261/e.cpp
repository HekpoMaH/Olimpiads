#include<bits/stdc++.h>
#define mp(a,b) make_pair(a,b)
#define pb(a,b) push_back(a,b)
using namespace std;
const int nmax=3*1e5+9;
typedef long long lli;
vector<pair<int,int> > w[nmax];
int dp[nmax],tmp[nmax];
int n,m;
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n>>m;
   for(int i=1;i<=m;i++){
      int u,v,len;
      cin>>u>>v>>len;
      w[len].push_back(mp(u,v));
   }
   for(int i=0;i<nmax;i++){
      for(int j=0;j<w[i].size();j++){
         int u=w[i][j].first,v=w[i][j].second;
         tmp[v]=0;
      }
      for(int j=0;j<w[i].size();j++){
         int u=w[i][j].first,v=w[i][j].second;
         tmp[v]=max(tmp[v],dp[u]+1);
      }
      for(int j=0;j<w[i].size();j++){
         int u=w[i][j].first,v=w[i][j].second;
         dp[v]=max(dp[v],tmp[v]);
      }
   }
   int ans=0;
   for(int i=1;i<=n;i++)
      ans=max(ans,dp[i]);
   cout<<ans<<"\n";
}
