#include<bits/stdc++.h>
#define mp(a,b) make_pair(a,b)
using namespace std;
typedef pair<int,int> pii;
const int mmax=1e5+9,nmax=1e4+9,inf=1e8;
vector<pii> g[nmax];
int n,m;
int main(){
   cin>>n>>m;
   for(int i=1;i<=m;i++){
      int x,y,z;
      cin>>x>>y>>z;
      g[x].push_back(mp(y,z));
      g[y].push_back(mp(x,z));
   }
   priority_queue<pii> pq;
   int d[nmax];
   memset(d,0,sizeof(d));
   d[1]=inf;
   pq.push(mp(inf,1));
   while(!pq.empty()){
      pii cur=pq.top();
      pq.pop();
      if(d[cur.second]>cur.first)continue;
      for(int i=0;i<g[cur.second].size();i++){
         int teg,nxt;
         teg=min(d[cur.second],g[cur.second][i].second);
         nxt=g[cur.second][i].first;
         if(d[nxt]<teg){
            d[nxt]=teg;
            pq.push(mp(teg,nxt));
         }
      }
   }
   if(d[n]==inf)cout<<"0\n";
   cout<<d[n]<<"\n";
}
