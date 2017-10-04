/*
 * levit's Algo O(mlogn) (tva e experimentalna slojnost) 
 * zada4ata e 2004 Noi2 Fast
*/
#include<bits/stdc++.h>
#define mp(a,b) make_pair(a,b)
using namespace std;
const int nmax=1e4+9,mmax=1e5+9,inf=1e8;
int n,m;
typedef pair<int,int> pii;
vector<pii> g[nmax];
int d[nmax];
int id[nmax];
int pred[nmax];
void read(){
   cin>>n>>m;
   for(int i=1;i<=m;i++){
      int x,y,z;
      cin>>x>>y>>z;
      g[x].push_back(mp(y,z));
      g[y].push_back(mp(x,z));
   }
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   read();
   memset(d,0,sizeof(d));
   memset(pred,-1,sizeof(pred));
   d[1]=inf;
   deque<int> q;
   q.push_back(1);
   while(!q.empty()){
      int v=q.front();
      q.pop_front();
      id[v]=2;//id==2 ->v e v M0
      for(int i=0;i<g[v].size();i++){
         int to=g[v][i].first,len=g[v][i].second;
         if(d[to]<min(d[v],len)){
            d[to]=min(d[v],len);
            if(id[to]==0)q.push_back(to);//id==0 -> v e v M2
            else if(id[to]==2)q.push_front(to);
            pred[to]=v;
            id[to]=1;//id==1 -> v e v M1
         }
      }
   }
   cout<<d[n]<<"\n";
}
