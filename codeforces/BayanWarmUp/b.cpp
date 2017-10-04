#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
const int nmax=409;
#define pb push_back
#define mp make_pair
int n,m;
vector<int> g[nmax];
string s1,s2;
int jnum[nmax][nmax];
void read(){
   cin>>n>>m;
   int br=0;
   for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
         br++;
         jnum[i][j]=br;
      }
   }
   cin>>s1;
   for(int i=0;i<n;i++){
      if(s1[i]=='<'){
         for(int j=2;j<=m;j++){
            g[jnum[i+1][j]].pb(jnum[i+1][j-1]);
         }
      }
      if(s1[i]=='>'){
         for(int j=1;j<m;j++){
            g[jnum[i+1][j]].pb(jnum[i+1][j+1]);
         }
      }
   }
   cin>>s2;
   for(int i=0;i<m;i++){
      if(s2[i]=='v'){
         for(int j=1;j<n;j++){
            g[jnum[j][i+1]].pb(jnum[j+1][i+1]);
         }
      }
      if(s2[i]=='^'){
         for(int j=2;j<=n;j++){
            g[jnum[j][i+1]].pb(jnum[j-1][i+1]);
         }
      }
   }
}
int used[nmax];
void dfs(int node){
   used[node]=1;
   for(int i=0;i<g[node].size();i++){
      if(used[g[node][i]]==0){
         dfs(g[node][i]);
      }
   }
}
bool chek(){
   for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
         if(used[jnum[i][j]]==0)return false;
      }
   }
   return true;
}
void solve(){
   for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
         memset(used,0,sizeof(used));
         dfs(jnum[i][j]);
         if(chek()==false){
            cout<<"NO\n";
            return;
         }
      }
   }
   cout<<"YES\n";
}
int main(){
   read();
   solve();
}
