#include<bits/stdc++.h>
using namespace std;
const int nmax=59;
string s[nmax];
int n;
int used[nmax];
int br[nmax];
int br1;
void dfs(int node){
   used[node]=1;
   for(int i=1;i<=n;i++){
      if(s[node-1][i-1]=='1'){
         if(used[i]==0){
            used[i]=1;
            dfs(i);
         }
      }
   }
}
int main(){
   cin>>n;
   for(int i=0;i<n;i++){
      cin>>s[i];
   }
   for(int i=1;i<=n;i++){
      memset(used,0,sizeof(used));
      dfs(i);
      int l=1;
      for(int j=1;j<=n;j++){
         if(used[j]==0)l=0;
         br[j]+=used[j];
      }
      br1+=l;
   }
   cout<<br1<<"\n";
   br1=0;
   for(int i=1;i<=n;i++){
      if(br[i]==n)br1++;
   }
   cout<<br1<<"\n";
}
