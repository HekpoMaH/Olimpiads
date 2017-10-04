#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
const int nmax=20009;
const int inf=1e9;
vector<pii> g[nmax];
int d[nmax];
priority_queue<pii, vector<pii>, greater<pii> > pq;
int n,m;
void dijkstra(int stnode,int endnode){
    for(int i=0;i<n;i++)d[i]=inf;
    d[stnode]=0;
    pii current;
    //while(pq.size())pq.pop();
    pq.push(make_pair(0,stnode));
    long long node,len,node2,len2;
    while(pq.size()){
       current=pq.top();
       pq.pop();
       len=current.first;
       node=current.second;
       //cerr<<node<<endl;
       if(d[node]<len)continue;
       d[node]=len;
       for(int i=0;i<(int)g[node].size();i++){
          len2=g[node][i].second;
          node2=g[node][i].first;
          if(d[node2]>len+len2){
             d[node2]=len+len2;
             pq.push(make_pair(len+len2,node2));
          }
       }
    }
    for(int i=0;i<n;i++){
       if(d[i]!=inf){
          cout<<d[i]<<"\n";
       }
       else cout<<"-1\n";
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
      g[y].pb(mp(x,z));
   }
   dijkstra(0,n-1);
}
