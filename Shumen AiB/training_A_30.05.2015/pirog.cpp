#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long lli;
typedef pair<lli ,lli > pii;
struct gamepos{
   int r[19];
   int wl;
   int hsh;
   gamepos(){
      for(int i=0;i<9;i++)r[i]=0;
      wl=-1;
      hsh=-1;
   }
   void he6i(){
      hsh=0;
      for(int i=0;i<9;i++)hsh=hsh*10+r[i];
   }
};
int n,m;
int init[19];
vector<bool> used(1000000000,0);
vector<bool> ans(1000000000,0);
gamepos start;
vector<pii> ansm;
bool go(gamepos cur){
   if(cur.hsh==-1)cur.he6i();
   //cout<<cur.hsh<<" ";
   if(used[cur.hsh]){
      return ans[cur.hsh];
   }
   gamepos nxt;
   for(int i=0;i<9;i++){
      nxt.r[i]=cur.r[i];
   }
   for(int i=0;i<n;i++){
      for(int j=1;j<=cur.r[i];j++){
         for(int k=i;k<n;k++){
            nxt.r[k]=min(nxt.r[k],j-1);
         }
         if(!go(nxt)){
            used[cur.hsh]=1;
            ans[cur.hsh]=1;
            //cout<<" 1 ";
            return true;
         }
         for(int k=i;k<n;k++){
            nxt.r[k]=cur.r[k];
         }
      }
   }
   used[cur.hsh]=1;
   ans[cur.hsh]=0;
   //cout<<" -1 ";
   return false;
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   gamepos nxt;
   cin>>n>>m;
   for(int i=0;i<n;i++){
      cin>>init[i];
      start.r[i]=init[i];
   }
   for(int i=0;i<9;i++){
      nxt.r[i]=start.r[i];
   }
   used[0]=1;
   ans[0]=1;
   used[(int)1e9]=1;
   ans[(int)1e9]=0;

   int wl=go(start);
   //cout<<wl<<"\n";
   //cout<<"\n";
   if(wl){
      for(int i=0;i<n;i++){
         for(int j=1;j<=start.r[i];j++){
            for(int k=i;k<n;k++){
               nxt.r[k]=min(nxt.r[k],j-1);
            }
            nxt.he6i();
            if(!used[nxt.hsh]){
               wl=go(nxt);
            }
            if(!ans[nxt.hsh]){
               //cout<<nxt.hsh<<"\n";
               ansm.pb(mp(i+1,j));
            }
            for(int k=i;k<n;k++){
               nxt.r[k]=start.r[k];
            }
         }
      }
   }
   cout<<ansm.size()<<"\n";
   for(int i=0;i<(int)ansm.size();i++){
      cout<<ansm[i].fi<<" "<<ansm[i].se<<"\n";
   }
}
