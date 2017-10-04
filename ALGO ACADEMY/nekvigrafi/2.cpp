#include<bits/stdc++.h>
using namespace std;
const int nmax=20009;
vector<int> g[nmax];
vector<int> ans;
int st[nmax];
int n;
int koren;
void dfs(int node){
   if(g[node].size()==0){
      ans.push_back(node);
      return;
   }
   for(int i=0;i<g[node].size();i++){
      dfs(g[node][i]);
   }
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   for(int i=1;i<=n;i++){
      int x,y;
      cin>>x>>y;
      st[y]++;
      g[x].push_back(y);
   }
   for(int i=1;i<=n;i++){
      if(st[i]==0)koren=i;
   }
   cout<<koren<<"\n";
   //dfs(koren);
   //sort(ans.begin(),ans.end());
   //cout<<ans.size()<<"\n";
   //for(int i=0;i<ans.size();i++){
   //   cout<<ans[i]<<"\n";
   //}
}
