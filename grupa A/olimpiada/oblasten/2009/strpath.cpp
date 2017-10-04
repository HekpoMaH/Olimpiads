#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int amax=26;
const int lmax=16;
const int nmax=128;
int n,m;
string name;
string word;
int dp[lmax][nmax];

vector<int> edge[nmax][amax];
void read(){
   cin>>n>>m;
   cin>>name;
   for(int i=0;i<m;i++){
      int u,v;
      cin>>u>>v;
      edge[u][name[v-1]-'A'].pb(v);
      //cout<<"edge b/w "<<u<<" "<<v<<" "<<"name["<<u<<"]="<<name[u-1]-'A'<<" name["<<v<<"]="<<name[v-1]-'A'<<"\n";
      if(u!=v){
         edge[v][name[u-1]-'A'].pb(u);
      }
   }
   cin>>word;
}
int solve(){
   int l=word.size();
   for(int i=1;i<=n;i++){
      if(word[0]==name[i-1])
         dp[1][i]=1;
   }
   for(int i=1;i<l;i++){
      for(int j=1;j<=n;j++){
         if(dp[i][j]>0){
            int ch=word[i]-'A';
            vector<int> &go=edge[j][ch];
            for(int kk=0;kk<go.size();kk++){
               dp[i+1][go[kk]]+=dp[i][j];

            }
         }
      }
   }
   //for(int i=1;i<=l;i++){
   //   for(int j=1;j<=n;j++){
   //      cout<<dp[i][j]<<" ";
   //   }
   //   cout<<"\n";
   //}
   int res=0;
   for(int i=1;i<=n;i++){
      res+=dp[l][i];
   }
   return res;
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   read();
   cout<<solve()<<"\n";
}

