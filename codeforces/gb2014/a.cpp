#include<bits/stdc++.h>
using namespace std;
const int nmax=3e4+9;
int used[nmax];
int a[nmax];
void dfs(int x){
   used[x]=1;
   if(used[x+a[x]]==0)dfs(x+a[x]);
}
int main(){
   int n,t;
   cin>>n>>t;
   for(int i=1;i<n;i++){
      cin>>a[i];
   }
   dfs(1);
   cout<<(used[t] ? "YES" : "NO") <<"\n";
}
