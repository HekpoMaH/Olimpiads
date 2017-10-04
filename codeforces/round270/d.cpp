#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
const int nmax=2009;
typedef long long lli;
struct edge{
   int n1,n2,pr;
   edge(){}
   edge(int _n1,int _n2,int _pr){
      n1=_n1;
      n2=_n2;
      pr=_pr;
   }
};
vector<pair<int,int> > g[nmax];
vector<edge> e,tree;
int n;
int a[nmax][nmax],parent[nmax],level[nmax];
void read(){
   cin>>n;
   for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
         cin>>a[i][j];
         if(i==j&&a[i][j]!=0){
            cout<<"NO\n";
            exit(0);
         }
         if(i!=j&&a[i][j]==0){
            cout<<"NO\n";
            exit(0);
         }
         if(j>i){
            e.push_back(edge(i,j,a[i][j]));
         }
      }
   }
   for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
         if(a[i][j]!=a[j][i]){
            cout<<"NO\n";
            exit(0);
         }
      }
   }
}
bool cmp(edge f,edge s){
   if(f.pr<s.pr)return true;
   return false;
}
int get(int x){
   int cx=x;
   while(x!=parent[x]){
      x=parent[x];
   }
   int nxt;
   while(cx!=parent[cx]){
      nxt=parent[cx];
      parent[cx]=x;
      cx=nxt;
   }
   return x;
}
void uni(int x,int y){
   int px=get(x);
   int py=get(y);
   if(level[px]<level[py]){
      parent[x]=py;
   }
   else if(level[px]>level[py]){
      parent[y]=px;
   }
   else{
      parent[y]=px;
      level[x]++;
   }
}
lli pl[nmax][nmax];
int begin;
int used[nmax];
void dfs(int node,lli len){
   used[node]=1;
   pl[begin][node]=len;
   pair<int,int> cur;
   for(int i=0;i<g[node].size();i++){
      cur=g[node][i];
      if(used[cur.first]==0){
         dfs(cur.first,len+cur.second);
      }
   }
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   read();
   //for(int i=1;i<=n;i++){
   //   parent[i]=i;level[i]=1;
   //}
   //sort(e.begin(),e.end(),cmp);
   //for(int i=0;i<e.size();i++){
   //   if(get(e[i].n1)!=get(e[i].n2)){
   //      tree.pb(e[i]);
   //      uni(e[i].n1,e[i].n2);
   //      g[e[i].n1].pb(mp(e[i].n2,e[i].pr));
   //      g[e[i].n2].pb(mp(e[i].n1,e[i].pr));
   //   }
   //   if(tree.size()==n-1)break;
   //}
   ////for(int i=0;i<tree.size();i++){
   ////   cout<<tree[i].n1<<" "<<tree[i].n2<<" "<<tree[i].pr<<"\n";
   ////}
   //for(int i=1;i<=n;i++){
   //   begin=i;
   //   memset(used,0,sizeof(used));
   //   dfs(i,0);
   //}
   //for(int i=1;i<=n;i++){
   //   for(int j=1;j<=n;j++){
   //      if(pl[i][j]!=a[i][j]){
   //         cout<<"NO\n";
   //         exit(0);
   //      }
   //   }
   //}
   for(int i=1;i<=n;i++){
      int pos,mn=1e9+9;
      for(int j=1;j<=n;j++){
         if(i==j)continue;
         if(a[i][j]<mn){
            mn=a[i][j];
            pos=j;
         }
      }
      for(int j=1;j<=n;j++){
         if(j==i||j==pos)continue;
         if(abs(a[i][j]-a[pos][j])!=mn){
            cout<<"NO\n";
            exit(0);
         }
      }
   }
   cout<<"YES\n";
}
