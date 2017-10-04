#include<bits/stdc++.h>
using namespace std;
const int nmax=5*1e5+9;
vector<int> g[nmax];
int n,m;
int profit,n1,n2;
struct bonuses{
   int first,second,prof;
   bonuses(){}
   bonuses(int _first,int _second,int _prof){
      first=_first;
      second=_second;
      prof=_prof;
   }
};
bonuses bon[nmax];
void read(){
   ifstream fin("profit.04.in");
   fin>>n;
   for(int i=1;i<n;i++){
      int a,b;
      fin>>a>>b;
      g[a].push_back(b);
      g[b].push_back(a);
   }
   fin>>m;
   for(int i=1;i<=m;i++){
      int a,b,c;
      fin>>a>>b>>c;
      bon[i]=bonuses(a,b,c);
   }
   cin>>profit>>n1>>n2;
   cin>>n1>>n2>>profit;
}
int used[nmax];
void dfs(int node){
   used[node]=1;
   if(node==n2){
      int sum=0;
      for(int i=1;i<=m;i++){
         if(used[bon[i].first]==1&&used[bon[i].second]==1){
            sum+=bon[i].prof;
         }
      }
      if(sum==profit){
         cout<<"CORRECT!!!\n";
      }
      else cout<<");\n"<<profit<<" "<<sum<<"\n";
      cout.flush();
   }
   for(int i=0;i<g[node].size();i++){
      if(used[g[node][i]]==0){
         dfs(g[node][i]);
         used[g[node][i]]=0;
      }
   }
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   read();
   dfs(n1);
}
