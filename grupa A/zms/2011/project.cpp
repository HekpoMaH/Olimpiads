#include<bits/stdc++.h>
using namespace std;
const int nmax=10009;
const int mmax=1e5+9;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
vector<pair<int,int> > g[nmax];
int d[nmax];
int n,m;
int x,y,z;
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n>>m;
   for(int i=1;i<=m;i++){
      cin>>x>>y>>z;
      g[y].push_back(mp(x,z));
   }
   for(int i=1;i<=n;i++){
      g[0].pb(mp(i,0));
   }
   memset(d,31,sizeof(d));
   int inf=d[0];
   d[0]=0;
   int fl=1;
   while(fl){
      fl=0;
      for(int i=0;i<=n;i++){
         for(int j=0;j<g[i].size();j++){
            int nv=g[i][j].fi,le=g[i][j].se;
            if(d[nv]>d[i]+le){
               d[nv]=d[i]+le;
               fl=1;
            }
         }
      }
   }
   int mn=inf;
   for(int i=1;i<=n;i++){
      mn=min(mn,d[i]);
   }
   for(int i=1;i<=n;i++){
      if(d[i]==inf)d[i]=mn;
   }
   for(int i=1;i<=n;i++){
      cout<<d[i]-mn<<" ";
   }
   cout<<"\n";
}
