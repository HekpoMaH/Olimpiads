#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
const int nmax=2*(1e5)+9;
struct edge{
   lli a,b,c1,c2,idx;
   edge(){}
   edge(lli _a,lli _b,lli _c1,lli _c2,lli _idx){
      a=_a;
      b=_b;
      c1=_c1;
      c2=_c2;
      idx=_idx;
   }
};
int n,m;
vector<edge> e;

int parent[nmax],level[nmax];
int get(int x){
   int x2=x;
   while(x!=parent[x])x=parent[x];
   int nxt;
   while(x2!=parent[x2]){
      nxt=parent[x2];
      parent[x2]=x;
      x2=nxt;
   }
   return x;
}
void uni(int x,int y){
   int rx=get(x),ry=get(y);
   if(level[rx]<level[ry]){
      parent[rx]=ry;
      return;
   }
   if(level[rx]>level[ry]){
      parent[ry]=rx;
      return;
   }
   parent[ry]=rx;
   level[rx]++;
}
bool cmp(edge f,edge s){
   if(f.c1!=s.c1)return f.c1<s.c1;
   return f.c2>s.c2;
}
void read(){
   cin>>n>>m;
   for(int i=1;i<=m;i++){
      lli x,y,z,k;
      x=y=z=k=0;
      cin>>x>>y>>z>>k;
      e.push_back(edge(x,y,z,k,(lli)i));
   }
}
void solve(){
   sort(e.begin(),e.end(),cmp);
   for(int i=0;i<m;i++){
      if(get(e[i].a)!=get(e[i].b)){
         cout<<e[i].idx<<"\n";
         uni(e[i].a,e[i].b);
      }
   }
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   read();
   for(int i=1;i<=n;i++)parent[i]=i,level[i]=1;
   solve();
}
