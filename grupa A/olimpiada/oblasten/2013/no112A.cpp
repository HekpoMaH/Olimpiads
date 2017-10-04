#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int nmax=1009;
int n,m,q;
int comp[nmax];
int cpnum;
int code,from,to;
vector<int> roads[nmax];
void read(){
   cin>>n>>m;
   int x,y;
   for(int i=1;i<=m;i++){
      cin>>x>>y;
      roads[x].pb(y);
      roads[y].pb(x);
   }
   cin>>q;
   cin>>code>>from>>to;
   q--;
   while(code!=1&&q!=0){
      if(code==2){
         roads[from].pb(to);
         roads[to].pb(from);
      }
      if(code==3){
         for(int i=0;i<(int)roads[from].size();i++){
            if(roads[from][i]==to){
               roads[from][i]=from;
            }
         }
         for(int i=0;i<(int)roads[to].size();i++){
            if(roads[to][i]==from){
               roads[to][i]=to;
            }
         }
      }
      cin>>code>>from>>to;
      q--;
   }
}
void dfs(int node){
   comp[node]=cpnum;
   for(int i=0;i<(int)roads[node].size();i++){
      if(comp[roads[node][i]]==0){
         dfs(roads[node][i]);
      }
   }
}
void solve(){
   for(int i=1;i<=n;i++){
      if(comp[i]==0){
         cpnum++;
         dfs(i);
      }
   }
   int tmp;
   while(q>=0){
      if(code==1){
         if(comp[from]==comp[to]){
            cout<<1;
         }
         else cout<<0;
      }
      else if(code==2){
         roads[from].pb(to);
         roads[to].pb(from);
         tmp=comp[to];
         for(int i=1;i<=n;i++){
            if(comp[i]==tmp){
               comp[i]=comp[from];
            }
         }
      }
      else if(code==3){
         for(int i=0;i<(int)roads[from].size();i++){
            if(roads[from][i]==to){
               roads[from][i]=from;
            }
         }
         for(int i=0;i<(int)roads[to].size();i++){
            if(roads[to][i]==from){
               roads[to][i]=to;
            }
         }
         memset(comp,0,sizeof(comp));
         cpnum=0;
         for(int i=1;i<=n;i++){
            if(comp[i]==0){
               cpnum++;
               dfs(i);
            }
         }
      }
      if(q==0){
         break;
      }
      cin>>code>>from>>to;
      q--;
   }
   cout<<"\n";
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   read();
   solve();
}
