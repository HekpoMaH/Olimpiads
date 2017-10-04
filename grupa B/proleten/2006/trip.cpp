#include<bits/stdc++.h>
using namespace std;
const int nmax=1009;
int n,m,k;
vector<int> g[nmax];
int v[nmax];
int used[nmax];
int mx;
void read(){
   cin>>n>>m>>k;
   for(int i=1;i<=m;i++){
      int x,y;
      cin>>x>>y;
      g[x].push_back(y);
      g[y].push_back(x);
   }
   for(int i=1;i<=k;i++){
      int x;
      cin>>x;
      v[x]=1;
   }
}
void bfs(int start){
   queue<pair<int,int> > q;
   q.push(make_pair(start,1));
   memset(used,0,sizeof(used));
   used[start]=1;
   int tmax=0;
   while(!q.empty()){
      pair<int,int> cur;
      cur=q.front();q.pop();
      tmax=max(tmax,cur.second);
      for(int i=0;i<g[cur.first].size();i++){
         if(used[g[cur.first][i]]==0){
            used[g[cur.first][i]]=1;
            pair<int,int> nxt;
            nxt.first=g[cur.first][i];
            if(v[nxt.first])nxt.second=cur.second;
            else nxt.second=cur.second+1;
            q.push(nxt);
         }
      }
   }
   mx=max(mx,tmax);
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   read();
   for(int i=1;i<=n;i++){
      if(v[i]==0)bfs(i);
   }
   cout<<mx<<"\n";
}
