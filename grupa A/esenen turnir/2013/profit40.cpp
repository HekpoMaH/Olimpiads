#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
const int nmax=1e5+9;
const int dpmax=1e3+9;
typedef pair<int,int> pii;
int n,m;
vector<int> g[nmax];
vector<pii> s[nmax];
int dp[dpmax][dpmax];
int used[dpmax];
int bon(int x){
   int re=0;
   for(int i=0;i<s[x].size();i++)
      if(used[s[x][i].first]==1)
         re+=s[x][i].second;
   return re;
}
void calcdp(int a,int b,int prev){
   used[b]=1;
   if(a==b)
      dp[a][b]=0;
   if(a!=b)
      dp[a][b]=dp[a][prev]+bon(b);
   for(int i=0;i<g[b].size();i++){
      if(used[g[b][i]]==0){
         calcdp(a,g[b][i],b);
         used[g[b][i]]=0;
      }
   }
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   int a,b,c;
   int mx=0;
   for(int i=1;i<n;i++){
      cin>>a>>b;
      g[a].pb(b);
      g[b].pb(a);
   }
   cin>>m;
   for(int i=1;i<=m;i++){
      cin>>a>>b>>c;
      s[a].pb(mp(b,c));
      s[b].pb(mp(a,c));
   }
   for(int i=1;i<=n;i++){
      memset(used,0,sizeof(used));
      calcdp(i,i,-1);
      for(int j=1;j<=n;j++)
         if(mx<dp[i][j]){
            mx=max(mx,dp[i][j]);
            a=i,b=j;
         }
   }
   cout<<a<<" "<<b<<" "<<mx<<"\n";
}
