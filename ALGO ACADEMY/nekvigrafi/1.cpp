#include<bits/stdc++.h>
using namespace std;
const int nmax=59;
int a[nmax][nmax];
int used[nmax];
int n;
void dfs(int node){
   used[node]=1;
   for(int i=1;i<=n;i++){
      if(a[node][i]==1&&used[i]==0)dfs(i);
   }
}
void solve(){
   cin>>n;
   string s;
   for(int i=1;i<=n;i++){
      cin>>s;
      for(int j=0;j<n;j++){
         a[i][j+1]=s[j]-'0';
      }
   }
   memset(used,0,sizeof(used));
   int br=0;
   for(int i=1;i<=n;i++){
      if(used[i]==0){
         dfs(i);
         br++;
      }
   }
   cout<<br<<"\n";
}
int main(){
   int t;
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>t;
   while(t--){
      solve();
   }
}
