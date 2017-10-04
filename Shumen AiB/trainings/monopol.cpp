#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int nmax=2005;
const int mmax=400005;
vector<int> g[nmax];
int a[nmax];
int b[nmax];
int n,m;
int comp[nmax];
int col[nmax];
int num[nmax][2];
int u[nmax][2];
int collision[nmax];
int ncomp;
int r1,r2,res;
void read(){
   cin>>n;
   for(int i=1;i<=n;i++){
      cin>>b[i];
   }
   cin>>m;
   for(int i=1;i<=m;i++){
      int x,y;
      cin>>x>>y;
      g[x].pb(y);
      g[y].pb(x);
   }
}
void dfs(int x,int k){
   comp[x]=ncomp;
   col[x]=k;
   num[ncomp][k]++;
   for(int i=0;i<g[x].size();i++){
      if(!comp[g[x][i]])dfs(g[x][i],1-k);
      if(col[g[x][i]]!=1-k)collision[ncomp]=1;
   }
}
void solve(){
   ncomp=0;
   for(int i=1;i<=n;i++){
      if(!comp[i]){
         ncomp++;
         dfs(i,0);
      }
   }
   for(int i=1;i<=n;i++)res+=b[i];
   for(int i=1;i<=n;i++)u[comp[i]][col[i]]|=b[i];
   for(int i=1;i<=ncomp;i++){
      if(num[i][0]+num[i][1]>1&&(u[i][0]||u[i][1])){
         if((u[i][0]&&u[i][1])||collision[i]){
            r1+=num[i][0]+num[i][1];
            r2+=num[i][0]+num[i][1];
         }
         else if(u[i][0]){
            r1+=num[i][0];
            r2+=num[i][1];
         }
         else{
            r1+=num[i][1];
            r2+=num[i][0];
         }
      }
   }
   res=max(max(res,r1),r2);
   cout<<res<<"\n";
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   read();
   solve();
}
