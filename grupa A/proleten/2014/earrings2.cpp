#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define pb push_back
const int nmax=2009;
struct vec{
   lli x,y;
   vec(){};
   vec(lli _x,lli _y){
      x=_x;y=_y;
   }
   vec operator-(vec b){
      return vec(x-b.x,y-b.y);
   }
   vec operator+(vec b){
      return vec(x+b.x,y+b.y);
   }
   lli len2(){
      return x*x+y*y;
   }
};
vec P[nmax];
int n;
void read(){
   cin>>n;
   for(int i=1;i<=n;i++){
      cin>>P[i].x>>P[i].y;
   }
}
vector<int> g[nmax];
int used[nmax];
bool fl;
int Len[nmax];
void check_cycle(int starting,int node,int len){
   used[node]=1;
   Len[node]=len;
   for(int i=0;i<g[node].size();i++){
      if(used[g[node][i]]){
         if((len-Len[g[node][i]]+1)%2==1){
            fl=false;
         }
      }
      else check_cycle(starting,g[node][i],len+1);
   }
}
bool eval(lli mid){
   for(int i=1;i<=n;i++)g[i].clear();
   for(int i=1;i<=n;i++){
      for(int j=i+1;j<=n;j++){
         vec AB=P[i]-P[j];
         if(AB.len2()>mid){
            g[i].pb(j);
            g[j].pb(i);
         }
      }
   }
   memset(used,0,sizeof(used));
   memset(Len,0,sizeof(Len));
   fl=1;
   for(int i=1;i<=n;i++){
      if(used[i]==0){
         check_cycle(i,i,0);
      }
   }
   return fl==1;
}
void solve(){
   lli l=-1,r=0,mid;
   for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
         vec AB=P[i]-P[j];
         r=max(r,AB.len2());
      }
   }
   while(l+1<r){
      mid=(l+r)/2;
      if(eval(mid))r=mid;
      else l=mid;
   }
   cout<<setiosflags(ios::fixed)<<setprecision(6)<<sqrt(r)<<"\n";
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   read();
   solve();
}
