#include<bits/stdc++.h>
using namespace std;
const int nmax=509;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef pair<int,int> pii;
vector<pii> g[nmax];
int n,m;
int a,b,c;
int used[nmax];
string ans;
int starter;
void dfs(int curr,int sum){
   used[curr]=1;
   //cout<<"curr="<<curr<<" sum="<<sum<<"\n";
   for(int i=0;i<g[curr].size();i++){
      int nxt=g[curr][i].fi;
      int nsum=sum+g[curr][i].se;
      //cout<<sum<<"+"<<g[curr][i].se<<"="<<nsum<<"\n";
      if(used[nxt]==1&&nxt==starter){
         //cout<<nxt<<" "<<nsum<<"\n";
         if(nsum>0)ans="n";
      }
      if(used[nxt]==0){
         dfs(nxt,nsum);
      }
   }
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   while(cin>>n>>m){
      ans="y";
      for(int i=0;i<n;i++){
         while(g[i].size()!=0)g[i].pop_back();
      }
      for(int i=1;i<=m;i++){
         cin>>a>>b>>c;
         g[a].pb(mp(b,c));
         //cout<<a<<"---("<<c<<")--->"<<b<<"\n";
      }
      for(int i=0;i<n;i++){
         memset(used,0,sizeof(used));
         //cout<<"started "<<i<<"\n";
         starter=i;
         dfs(i,0);
         if(ans=="n")break;
      }
      cout<<ans<<"\n";
   }
}
