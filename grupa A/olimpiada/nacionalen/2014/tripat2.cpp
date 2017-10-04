#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+9;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef int lli;
typedef pair<int,int> pii;
int n,t[nmax];
int p[22][nmax];
int lvl[nmax];
vector<pii> g[nmax];
bool used[nmax];
lli pat[nmax];
void read(){
   cin>>n;
   for(int i=2;i<=n;i++){
      int a,b;
      cin>>a>>b;
      t[i]=a;
      g[a].pb(mp(i,b));
   }
}
void precompute(){
   memset(p,-1,sizeof(p));
   for(int i=1;i<=n;i++){
      p[0][i]=t[i];
   }
   for(int j=1;(1<<j)<=n;j++){
      for(int i=1;i<=n;i++){
         if(p[j-1][i]!=-1){
            p[j][i]=p[j-1][p[j-1][i]];
         }
      }
   }
}
void makelvl(int node,int l,int ds){
   lvl[node]=l;
   pat[node]=ds;
   for(int i=0;i<(int)g[node].size();i++){
      makelvl(g[node][i].fi,l+1,ds+g[node][i].se);
   }
}
inline int query(int v1,int v2){
   int log;
   if(lvl[v1]<lvl[v2])swap(v1,v2);
   for(log=1;(1<<log)<=lvl[v1];log++);
   log--;
   for(int i=log;i>=0;i--){
      if(lvl[v1]-(1<<i)>=lvl[v2]){
         v1=p[i][v1];
      }
   }

   if(v1==v2){
      return v1;
   }
   for(int i=log;i>=0;i--){
      if(p[i][v1]!=p[i][v2]){
         v1=p[i][v1];
         v2=p[i][v2];
      }
   }
   return t[v1];
}
lli dist(int v1,int v2){
   if(v1==1){
      return pat[v2];
   }
   return pat[v1]+pat[v2]-2*pat[query(v1,v2)];
}
void solve(){
   int q,a,b;
   lli ans,ta;
   cin>>q;
   for(int i=1;i<=q;i++){
      cin>>a>>b>>ta;
      ans=1e9;
      //cout<<t<<" "<<dist(a,b)<<" "<<dist(1,a)<<"\n";
      lli ab=dist(a,b);
      lli a1=dist(1,a);
      lli b1=dist(1,b);
      ans=min(ans,a1+ab);
      ans=min(ans,ta+a1);//postavqme rebroto ot A do B
      ans=min(ans,ta+ab);//postavqme rebroto ot 1 do A
      ans=min(ans,2*ta+b1);
      cout<<ans<<"\n";
   }
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   read();
   precompute();
   makelvl(1,0,0);
   solve();
}
