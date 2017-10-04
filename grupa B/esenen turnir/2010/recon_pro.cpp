#include<bits/stdc++.h>
using namespace std;
const int nmax=2*(1e3)+9;
int a[nmax][nmax];
int used[nmax],pred[nmax];
int n;
vector<int> v[nmax];
void dfs(int v,int l){
   used[v]=1;
   for(int i=1;i<=n;i++){
      if(i!=v){
         if(a[1][i]==a[v][i]+l){
            if(a[i][pred[i]]>a[v][i])pred[i]=v;
            if(used[i]==0)dfs(i,l+a[i][v]);
         }
      }
   }
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   for(int i=1;i<=n;i++){
      pred[i]=1;
   }
   for(int i=1;i<n;i++){
      for(int j=i+1;j<=n;j++){
         cin>>a[i][j];
         a[j][i]=a[i][j];
      }
   }
   dfs(1,0);
   for(int i=1;i<=n;i++){
      if(i!=pred[i]){
         v[i].push_back(pred[i]);
         v[pred[i]].push_back(i);
      }
   }
   for(int i=1;i<=n;i++){
      sort(v[i].begin(),v[i].end());
      cout<<v[i].size();
      for(int j=0;j<v[i].size();j++){
         cout<<" "<<v[i][j];
      }
      cout<<"\n";
   }
}
