#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+9;
const int inf=1e9;
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
int n,root;
vector<int> tree[nmax];
int weight[nmax],parent[nmax],best_u[nmax],best_d[nmax],best[nmax];
bool poss_u[nmax],trader[nmax];
void read(){
   scanf("%d%d", &n,&root);
   int x,y;
   for(int i=1;i<n;i++){
      scanf("%d%d", &x,&y);
      tree[x].pb(y);
      tree[y].pb(x);
   }
   for(int i=1;i<=n;i++)cin>>weight[i];
   int q;
   scanf("%d", &q);
   for(int i=1;i<=q;i++){
      scanf("%d%d", &x,&y);
      weight[x]-=y;
   }
   scanf("%d", &q);
   for(int i=1;i<=q;i++){
      scanf("%d", &x);
      trader[x]=1;
   }
}
void dfs(int curr){
   int best_sum=0;
   int sz=tree[curr].size();
   for(int i=0;i<sz;i++){
      int nxt=tree[curr][i];
      if(parent[curr]!=nxt){
         parent[nxt]=curr;
         dfs(nxt);
         best_sum+=best[nxt];
      }
   }
   if(trader[curr]){
      best_u[curr]=weight[curr]+best_sum;
      poss_u[curr]=1;
   }
   else{
      best_u[curr]=-inf;
      poss_u[curr]=false;
   }
   for(int i=0;i<sz;i++){
      int nxt=tree[curr][i];
      if(parent[curr]!=nxt&&poss_u[nxt]){
         best_u[curr]=max(best_u[curr],best_sum-best[nxt]+best_u[nxt]+weight[curr]);
         poss_u[curr]=1;
      }
   }
   best_d[curr]=weight[curr]+best_sum;
   for(int i=0;i<sz;i++){
      int nxt=tree[curr][i];
      if(parent[curr]!=nxt){
         best_d[curr]=max(best_d[curr],best_sum-best[nxt]+best_d[nxt]+weight[curr]);
      }
   }
   best[curr]=best_sum;
   if(poss_u[curr]){
      best[curr]=max(best[curr],best_u[curr]);
   }
   if(trader[curr]){
      best[curr]=max(best[curr],best_d[curr]);
   }
}

int main(){
   //ios_base::sync_with_stdio(false);
   //cin.tie(0);
   read();
   dfs(root);
   cout<<best[root]<<"\n";
}
