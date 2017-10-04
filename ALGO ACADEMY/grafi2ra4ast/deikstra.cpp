#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
typedef pair<lli,lli> pii;
const long long inf=1e15;
const int nmax=1e4;
#define mp make_pair
#define pb push_back
vector<pii> a[nmax];
lli n,m,h,g,u,v;
lli mn=inf;
lli d[nmax],pred[nmax];
priority_queue<pii, vector<pii>, greater<pii> >pq;
void chek(lli s){
   for(int i=1;i<=n;i++){
      d[i]=inf;
   }
   d[s]=0;
   pred[s]=-1;
   pii current;
   pq.push(mp(0,s));
   lli node,len,node2,len2;
   while(pq.size()){
      current=pq.top();
      pq.pop();
      len=current.first;
      node=current.second;
      if(d[node]<len)continue;
      d[node]=len;
      for(int i=0;i<a[node].size();i++){
         len2=a[node][i].second;
         node2=a[node][i].first;
         if(d[node2]>len+len2){
            d[node2]=len+len2;
            pred[node2]=node;
            pq.push(mp(len+len2,node2));
         }
      }
   }
   for(int i=1;i<=n;i++){
      cout<<i<<"->"<<d[i]<<"\n";
   }
}
void read(){
   cin>>n>>m;
   for(int i=1;i<=m;i++){
      int x,y,z;
      cin>>x>>y>>z;
      a[x].pb(mp(y,z));
      a[y].pb(mp(x,z));
   }
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   read();
   chek(1);
}
