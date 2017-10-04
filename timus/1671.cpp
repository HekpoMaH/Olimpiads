//anansi's coweb
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
const int nmax=1e5+9;
int par[nmax];
int sz[nmax];
int n,m,q;
int torn[nmax];
pii edges[nmax];
int get(int x){
   int y=x;
   int re;
   while(x!=par[x]){
      x=par[x];
   }
   re=x;
   x=y;
   while(x!=par[x]){
      y=par[x];
      par[x]=re;
      x=y;
   }
   return re;
}
void uni(int x,int y){
   int px=get(x),py=get(y);
   if(sz[px]>sz[py]){
      par[py]=px;
      return;
   }
   if(sz[px]<sz[py]){
      par[px]=py;
      return;
   }
   par[px]=py;
   sz[px]++;
}
int x[nmax];
void read(){
   cin>>n>>m;
   for(int i=1;i<=m;i++){
      cin>>edges[i].fi>>edges[i].se;
   }
   cin>>q;
   for(int i=1;i<=q;i++){
      cin>>x[i];
      torn[x[i]]=1;
   }
}
vector<int> ans;

void solve(){
   int br=n;
   for(int i=1;i<=m;i++){
      if(torn[i]==0){
         if(get(edges[i].fi)!=get(edges[i].se)){
            br--;
            uni(edges[i].fi,edges[i].se);
         }
      }
   }
   ans.pb(br);
   //for(int i=1;i<=n;i++){
   //   cout<<get(i)<<" ";
   //}
   //cout<<"-------------\n";
   //cout<<br<<"\n";
   for(int i=q;i>=2;i--){
      //cout<<edges[x[i]].fi<<" "<<edges[x[i]].se<<"\n";
      //cout<<get(edges[x[i]].fi)<<" "<<get(edges[x[i]].se)<<"\n";
      if(get(edges[x[i]].fi)!=get(edges[x[i]].se)){
         br--;
         uni(edges[x[i]].fi,edges[x[i]].se);
      }
      //cout<<br<<" ihaa \n";
      ans.pb(br);
   }
   reverse(ans.begin(),ans.end());
   for(size_t i=0;i<ans.size();i++){
      cout<<ans[i]<<" ";
   }
   cout<<"\n";
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   read();
   for(int i=1;i<=n;i++){
      par[i]=i;
      sz[i]=1;
   }
   solve();
}
