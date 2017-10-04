#include<bits/stdc++.h>
using namespace std;
const int nmax=1009;
int used[nmax];
int n,m;
int a[nmax][nmax];
void dfs(int node){
   used[node]=1;
   for(int i=1;i<=n;i++){
      if(a[node][i]==0&&used[i]==0)dfs(i);
   }
}
int main(){
   ios_base::sync_with_stdio(false);
   cin>>n>>m;
   for(int i=1;i<=m;i++){
      int x,y;
      cin>>x>>y;
      a[x][y]=a[y][x]=1;
   }
   int br=0;
   for(int i=1;i<=n;i++){
      if(used[i]==0){
         dfs(i);
         br++;
      }
   }
   cout<<br-1<<"\n";
}
