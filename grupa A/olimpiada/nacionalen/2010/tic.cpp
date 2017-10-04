#include<bits/stdc++.h>
using namespace std;
const int nmax=1009;
typedef long long lli;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n,t,d,s;
int f[nmax];
vector<int> in[nmax];
int h[nmax][nmax];
lli dp[nmax][nmax];
int used[nmax][nmax];
int dist[nmax][nmax];
vector<pii> a[nmax];
void read(){
   cin>>n>>t>>d>>s;
   for(int i=1;i<=n;i++){
      cin>>f[i];
      f[i]*=t;
   }
   for(int i=1;i<n;i++){
      int x,y,z;
      cin>>x>>y>>z;
      a[x].pb(mp(y,z));
      a[y].pb(mp(x,z));
   }
   a[0].pb(mp(1,d+1));
   a[1].pb(mp(0,d+1));
}
void dfs2(int x,int y,int st,int z){
   dist[st][x]=z;
   for(int i=0;i<(int)a[x].size();i++){
      if(a[x][i].fi!=y){
         dfs2(a[x][i].fi,x,st,z+a[x][i].se);
      }
   }
}
void dfs(int x,int y){
   for(int i=0;i<(int)a[x].size();i++){
      if(a[x][i].fi==y){
         a[x].erase(a[x].begin()+i);
         i--;
      }
      else{
         dfs(a[x][i].fi,x);
         for(int j=1;j<=n;j++){
            h[x][j]|=h[a[x][i].fi][j];
         }
      }
   }
   h[x][x]=1;
   for(int i=1;i<=n;i++){
      if(h[x][i]){
         in[x].pb(i);
      }
   }
}
lli go(int x,int y){
   lli &ans=dp[x][y];
   if(used[x][y])return ans;
   used[x][y]=1;
   ans=0;
   lli cur;
   int idx=-1;
   if(h[x][y]){
      for(int i=0;i<(int)a[x].size();i++){
         if(h[a[x][i].fi][y])idx=i;
      }
   }
   for(int i=0;i<(int)in[x].size();i++){
      if(dist[x][in[x][i]]<dist[x][y]){
         if(idx!=-1&&in[a[x][idx].first][in[x][i]])continue;
         cur=-s;
         if(dist[x][in[x][i]]<=d)cur+=f[x];
         for(int j=0;j<(int)a[x].size();j++){
            if(j==idx){
               cur+=go(a[x][j].fi,y);
            }
            else{
               cur+=go(a[x][j].fi,in[x][i]);
            }
         }
         if(cur>ans)ans=cur;
      }
      else break;
   }
   cur=0;
   if(dist[x][y]<=d)cur+=f[x];
   for(int j=0;j<(int)a[x].size();j++){
      cur+=go(a[x][j].first,y);
   }
   ans=max(ans,cur);
   return ans;
}
int sorting_now;
bool cmp(int x,int y){
   return dist[sorting_now][x]<dist[sorting_now][y];
}
void solve(){
   for(int i=1;i<=n;i++){
      dfs2(i,-1,i,0);
   }
   dfs(0,-1);
   for(int i=1;i<=n;i++){
      sorting_now=i;
      sort(in[i].begin(),in[i].end(),cmp);
   }
   cout<<go(1,0)<<"\n";
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   read();
   solve();
}
