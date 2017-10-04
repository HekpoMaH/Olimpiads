#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+9;
vector<int> v[nmax];
vector<int> atlevel[nmax];
int h[nmax],in[nmax],out[nmax];
int n;
int ba6dqdo;
int cntr;
void dfs(int node,int level){
   cntr++;
   in[node]=cntr;
   h[node]=level;
   atlevel[level].push_back(in[node]);
   for(int i=0;i<v[node].size();i++){
      dfs(v[node][i],level+1);
   }
   cntr++;
   out[node]=cntr;
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   for(int i=1;i<=n;i++){
      int x;
      cin>>x;
      if(x!=-1){
         v[x].push_back(i);
      }
      else ba6dqdo=i;
   }
   dfs(ba6dqdo,1);
   int q;
   //for(int i=1;i<=n;i++){
   //   cout<<in[i]<<" "<<out[i]<<"\n";
   //}
   cin>>q;
   for(int i=1;i<=q;i++){
      int x,y;
      cin>>x>>y;
      int slevel=h[x]+y;
      if(slevel>=nmax||atlevel[slevel].size()==0)cout<<0<<"\n";
      else cout<<lower_bound(atlevel[slevel].begin(),atlevel[slevel].end(),out[x])-lower_bound(atlevel[slevel].begin(),atlevel[slevel].end(),in[x])<<"\n";
   }
}
