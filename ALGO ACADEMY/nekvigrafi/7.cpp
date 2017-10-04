#include<bits/stdc++.h>
using namespace std;
const int offset=3500;
const int nmax=5009;
const int inf=1e8;
vector<int> g[2*nmax];
set<int> nodes;
int st[2*nmax];
int used[2*nmax];
int n,m;
int mx=-inf;
void read(){
   cin>>n>>m;
   for(int i=1;i<=m;i++){
      int x,y;
      cin>>x>>y;
      nodes.insert(x);
      nodes.insert(y);
      g[offset+x].push_back(y);
      g[offset+y].push_back(x);
      st[offset+x]++;
      st[offset+y]++;
   }
}
void dfs(int node,int sum){
   used[node+offset]=1;
   if(st[node+offset]<=1){
      mx=max(mx,sum);
   }
   for(int i=0;i<g[node+offset].size();i++){
      if(used[g[node+offset][i]+offset]==0){
         dfs(g[node+offset][i],sum+g[node+offset][i]);
      }
   }
}
int main(){
   read();
   set<int> ::iterator it;
   for(it=nodes.begin();it!=nodes.end();it++){
      memset(used,0,sizeof(used));
      if(st[*it+offset]==1){
         dfs(*it,*it);
      }
   }
   cout<<mx<<"\n";
}
