#include<bits/stdc++.h>
using namespace std;
int n,m;
int t,s;
typedef long long lli;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
const int nmax=209;
vector<pii> a,b;
vector<int> f[nmax];
int used[nmax],in[nmax];
void read(){
   cin>>m>>n;
   cin>>t>>s;
   for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
         int x;
         cin>>x;
         while(x--)a.pb(mp(i,j));
      }
   }
   for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
         int x;
         cin>>x;
         while(x--){
            b.pb(mp(i,j));
         }
      }
   }
}
bool dfs(int x){
   used[x]=1;
   for(int i=0;i<(int)f[x].size();i++){
      if(in[f[x][i]]==-1||(!used[in[f[x][i]]]&&dfs(in[f[x][i]]))){
         in[f[x][i]]=x;
         return true;
      }
   }
   return false;
}
bool solve(){
   int dist;
   if((int)a.size()!=(int)b.size())
      return 0;
   for(int i=0;i<(int)a.size();i++){
      for(int j=0;j<(int)b.size();j++){
         dist=abs(a[i].fi-b[j].fi)+abs(a[i].se-b[j].se);
         if(dist<=t*s&&(dist&1)==((t*s)&1)){
            f[i].pb(j);
         }
      }
   }
   memset(in,-1,sizeof(in));
   for(int i=0;i<(int)a.size();i++){
      memset(used,0,sizeof(used));
      if(!dfs(i))
         return false;
   }
   return true;
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   read();
   cout<<(solve() ? 'Y' : 'N') <<"\n";
}
