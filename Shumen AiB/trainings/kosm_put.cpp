#include<iostream>
#include<vector>
using namespace std;
const int nmax=2*1e5+9;
#define pb push_back
int br;
vector<int> g[nmax];
int lowest[nmax],prenum[nmax],used[nmax],timer,n;
void read(){
   cin>>n;
   for(int i=1;i<n;i++){
      int x,y;
      cin>>x>>y;
      g[x].pb(y);
      g[y].pb(x);
   }
}
void dfs(int v,int pp){
   used[v]=1;
   prenum[v]=lowest[v]=++timer;
   for(int i=0;i<g[v].size();i++){
      int to=g[v][i];
      if(!used[to]){
         dfs(to,v);
      }
      if(pp!=to)lowest[v]=min(lowest[v],lowest[to]);
      //if(pp!=to)lowest[v]=min(lowest[v],prenum[to]);
   }
}
void solve(){
   timer=0;
   if(g[1].size()>1)br++;
   for(int i=2;i<=n;i++){
      for(int j=0;j<g[i].size();j++){
         if(lowest[g[i][j]]>=prenum[i]){
            timer++;
            break;
         }
      }
      if(timer==1)br++;
      timer=0;
   }
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   read();
   dfs(1,-1);
   //for(int i=1;i<=n;i++){
   //   cout<<prenum[i]<<" ";
   //}
   //cout<<"\n";
   //for(int i=1;i<=n;i++){
   //   cout<<lowest[i]<<" ";
   //}
   //cout<<"\n";
   solve();
   cout<<br<<"\n";
}
