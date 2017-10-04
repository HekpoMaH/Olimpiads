#include<bits/stdc++.h>
using namespace std;
const int nmax=1009;
vector<int> g[nmax];
int used[nmax];
int n,k;
int mx;
void dfs(int node,int len){
   used[node]=1;
   mx=max(len,mx);
   for(int i=0;i<g[node].size();i++){
      if(used[g[node][i]]==0){
         dfs(g[node][i],len+1);
      }
   }
}
void bfs(int node){
   memset(used,0,sizeof(used));
   queue<int> q;
   q.push(node);
   used[node]=1;
   while(!q.empty()){
      int cur=q.front();
      q.pop();
      mx=max(mx,used[cur]);
      for(int i=0;i<g[cur].size();i++){
         if(used[g[cur][i]]==0){
            q.push(g[cur][i]);
            used[g[cur][i]]=used[cur]+1;
         }
      }
   }
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n>>k;
   for(int i=1;i<=n;i++){
      int x,y;
      cin>>x>>y;
      g[x].push_back(y);
      g[y].push_back(x);
   }
   dfs(k,1);
   bfs(k);
   cout<<mx<<"\n";
}
