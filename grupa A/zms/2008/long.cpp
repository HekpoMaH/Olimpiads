#include<bits/stdc++.h>
using namespace std;
const int nmax=1009;
vector<pair<int,int> > g[nmax];
#define pb push_back
#define mp make_pair
int dp[nmax];
int n,m;
void dfs(int node){
   if(g[node].size()==0){
      dp[node]=0;
      return;
   }
   for(int i=0;i<g[node].size();i++){
      int u=g[node][i].first,len=g[node][i].second;
      if(dp[u]==-1)dfs(u);
      dp[node]=max(dp[u]+len,dp[node]);
   }
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n>>m;
   for(int i=1;i<=m;i++){
      int x,y,z;
      cin>>x>>y>>z;
      g[x].pb(mp(y,z));
   }
   memset(dp,-1,sizeof(dp));
   dfs(1);
   cout<<dp[1]<<"\n";
}
