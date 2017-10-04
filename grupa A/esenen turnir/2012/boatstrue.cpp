#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int mmax=1e5+9;
const int nmax=1e3+9;
int n,m,k;
struct edge{
   int x,y,w;
   edge(){}
   edge(int _x,int _y,int _w){
      x=_x;
      y=_y;
      w=_w;
   }
};
vector<int> g[nmax];
vector<edge> e;
vector<pair<int,int> > tr[nmax];
int par[nmax];
int rank[nmax];
bool cmp(edge f,edge s){
   return f.w>s.w;
}
int find(int a){
   int a1=a;
   while(par[a1]!=a1)a1=par[a1];
   int nxt;
   while(par[a]!=a){
      nxt=par[a];
      par[a]=a1;
      a=nxt;
   }
   return a1;
}
void uni(int a,int b){
   int ar=find(a),br=find(b);
   if(rank[ar]<rank[br]){
      par[ar]=br;
      return;
   }
   if(rank[ar]>rank[br]){
      par[br]=ar;
      return;
   }
   par[br]=ar;
   rank[ar]++;
}
void read(){
   cin>>n>>m>>k;
   for(int i=1;i<=n;i++)
      par[i]=i,rank[i]=0;
   for(int i=1;i<=m;i++){
      int x,y,z;
      cin>>x>>y>>z;
      e.pb(edge(x,y,z));
   }
}
int o(int a,int b){
   int used[nmax],ans[nmax];
   memset(used,0,sizeof(used));
   memset(ans,31,sizeof(ans));
   stack<int> st;
   st.push(a);
   while(!st.empty()){
      int tp=st.top();
      st.pop();
      for(int i=0;i<tr[tp].size();i++){
         if(used[tr[tp][i].first]==0){
            st.push(tr[tp][i].first);
            ans[tr[tp][i].first]=min(ans[tp],tr[tp][i].second);
            used[tr[tp][i].first]=1;
         }
      }
   }
   return ans[b];
}
void solve(){
   int br=0;
   sort(e.begin(),e.end(),cmp);
   for(int i=1;i<=m;i++){
      if(find(e[i].x)!=find(e[i].y)){
         tr[e[i].x].pb(make_pair(e[i].y,e[i].w));
         tr[e[i].y].pb(make_pair(e[i].x,e[i].w));
         uni(e[i].x,e[i].y);
         br++;
      }
      if(br==n-1)break;
   }
   for(int i=1;i<=k;i++){
      int qa,qb;
      cin>>qa>>qb;
      cout<<o(qa,qb)<<"\n";
   }
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   read();
   solve();
}
