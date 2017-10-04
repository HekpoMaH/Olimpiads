#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
const int nmax=(2.5*1e5)+9;
const int inf=1e9;
int n;
int active[nmax];
int used[nmax];
vector<pair<int,int> > edges[nmax];
int dfs(int at,int par){
   if(used[at]){
      return inf;
   }
   int res=0;
   for(int i=0;i<edges[at].size();i++){
      int nxt=edges[at][i].fi;
      if(nxt==par)
         continue;
      int cres=dfs(nxt,at);
      if(cres>edges[at][i].se)
         cres=edges[at][i].se;
      res+=cres;
   }
   return res;
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   for(int i=1;i<n;i++){
      int x,y,z;
      cin>>x>>y>>z;
      edges[x].pb(mp(y,z));
      edges[y].pb(mp(x,z));
   }
   int queries;
   cin>>queries;
   while(queries--){
      int root;
      cin>>root;
      int cnt;
      cin>>cnt;
      memset(used,0,sizeof(used));
      for(int i=1;i<=cnt;i++){
         cin>>active[i];
         used[active[i]]=1;
      }
      cout<<dfs(root,-1)<<"\n";
   }
}
