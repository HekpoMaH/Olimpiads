#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int nmax=1e5;
vector<int> g[nmax];
int n,m;
int d[nmax],nwnom[nmax];
int br;
void solve(int node){
   nwnom[node]=++br;
   for(int i=0;i<g[node].size();i++){
      d[g[node][i]]--;
      if(d[g[node][i]]==0)solve(g[node][i]);
   }
}
void read(){
   cin>>n>>m;
   for(int i=1;i<=m;i++){
      int x,y;
      cin>>x>>y;
      a[x].pb(y);
      d[y]++;
   }
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   read();
   solve();
   for(int i=1;i<=n;i++){
      coit<<nwnom[i]<<"\n";
   }
}
