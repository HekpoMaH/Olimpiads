#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};
string a[1024];
int n,m;
int in[1<<15],used[1<<15];
vector<int> f[1<<15];
vector<int> lev,res;
void read(){
   cin>>n>>m;
   for(int i=0;i<n;i++){
      cin>>a[i];
   }
}
bool dfs(int x){
   used[x]=1;
   for(int i=0;i<(int)f[x].size();i++){
      if(in[f[x][i]]==-1||(!used[in[f[x][i]]]&&dfs(in[f[x][i]]))){
         in[f[x][i]]=x;
         return 1;
      }
   }
   return 0;
}
void solve(){
   int x,y;
   int l=0,r=0;
   memset(in,-1,sizeof(in));
   for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
         if(a[i][j]=='#')continue;
         if((i&1)^(j&1)){
            lev.pb(i*m+j);
            l++;
         }
         else r++;
         for(int d=0;d<4;d++){
            x=i+dx[d];
            y=j+dy[d];
            if(x>=0&&y>=0&&x<=i&&y<m){
               if(a[x][y]=='#')continue;
               if((i&1)^(j&1)){
                  f[i*m+j].pb(x*m+y);
               }
               else{
                  f[x*m+y].pb(i*m+j);
               }
            }
         }
      }
      while((int)lev.size()){
         memset(used,0,sizeof(used));
         if(dfs(lev.back()))lev.pop_back();
         else break;
      }
      if(!lev.size()&&l==r)res.pb(i+1);
   }
   cout<<res.size()<<"\n";
   for(int i=0;i<(int)res.size();i++){
      if(i!=res.size()-1)cout<<res[i]<<" ";
      else cout<<res[i]<<"\n";
   }
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   read();
   solve();
}
