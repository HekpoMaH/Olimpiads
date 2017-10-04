#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int n;
string s1,s2,s3,s4;
map<string,int> renum;

map<int,string> oprenum;
vector<int> g[2009];
int used[2009];
vector<string> ans;
void dfs(int node){
   used[node]=1;
   ans.pb(oprenum[node]);
   for(int i=0;i<(int)g[node].size();i++){
      int nxt=g[node][i];
      if(used[nxt]==0){
         dfs(nxt);
      }
   }
}
void print(){
   sort(ans.begin(),ans.end());
   for(int i=0;i<(int)ans.size();i++){
      cout<<ans[i]<<"\n";
   }
}
int br=0;
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   for(int i=1;i<=n;i++){
      cin>>s1;
      if(s1=="add"){
         cin>>s2>>s3>>s4;
         if(renum.find(s2)==renum.end()){
            renum[s2]=++br;
            oprenum[br]=s2;
         }
         if(renum.find(s4)==renum.end()){
            renum[s4]=++br;
            oprenum[br]=s4;
         }
         g[renum[s2]].pb(renum[s4]);
      }
      else{
         cin>>s2;
         memset(used,0,sizeof(used));
         ans.clear();
         if(renum.find(s2)==renum.end()){
            cout<<"ERROR: No such resource\n";
         }
         else{
            dfs(renum[s2]);
            else print();
         }
      }
   }
}
