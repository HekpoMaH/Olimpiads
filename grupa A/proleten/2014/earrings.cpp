#include<bits/stdc++.h>
using namespace std;
const int nmax=2009;
typedef long long lli;
#define pb push_back
struct vec{
   lli x,y;
   vec(){}
   vec(lli _x,lli _y){
      x=_x;
      y=_y;
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
int lent[nmax];
int fl;
void chekcycle(int starting,int node,int len){
   //cout<<"parent-> "<<par<<" node-> "<<node<<" len-> "<<len<<"\n";
   used[node]=1;
   lent[node]=len;
   for(int i=0;i<g[node].size();i++){
      if(used[g[node][i]]){
         if((len-lent[g[node][i]]+1)%2==1){
            //cout<<lent[g[node][i]]<<" "<<len<<"\n";
            fl=0;
         }
      }
      if(used[g[node][i]]==0)chekcycle(starting,g[node][i],len+1);
   }
}
bool chek(lli mid){
   for(int i=1;i<=n;i++){
      g[i].clear();
   }
   //cout<<mid<<"\n";
   for(int i=1;i<=n;i++){
      for(int j=i;j<=n;j++){
         if(i==j)continue;
         vec AB=P[i]-P[j];
         if(AB.len2()>mid){
            g[i].pb(j);
            g[j].pb(i);
         }
      }
   }
   int mnj[nmax];
   memset(mnj,0,sizeof(mnj));
   memset(used,0,sizeof(used));
   memset(lent,0,sizeof(lent));
   //cout<<"____________\n";
   //for(int i=1;i<=n;i++){
   //   cout<<i<<"-> ";
   //   for(int j=0;j<g[i].size();j++)cout<<g[i][j]<<" ";
   //   cout<<"\n";
   //}
   //queue<int> q;
   //for(int kk=1;kk<=n;kk++){
   //   if(used[kk]!=0)continue;
   //   q.push(kk);
   //   mnj[kk]=1;
   //   used[kk]=1;
   //   while(!q.empty()){
   //      int cur=q.front();
   //      q.pop();
   //      for(int i=0;i<g[cur].size();i++){
   //         if(used[g[cur][i]]==0){
   //            used[g[cur][i]]=used[cur]+1;
   //            assert(mnj[g[cur][i]]==0);
   //            mnj[g[cur][i]]=3-mnj[cur];
   //            q.push(g[cur][i]);
   //         }
   //         else if(mnj[g[cur][i]]!=3-mnj[cur])return false;
   //      }
   //   }
   //}
   for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
         if(mnj[i]==mnj[j]){
            vec AB=P[i]-P[j];
            if(AB.len2()>mid){
               //cout<<i<<" "<<j<<"\n";
            }
         }
      }
   }
   //return true;
   fl=1;
   memset(used,0,sizeof(used));
   for(int i=1;i<=n;i++){
      if(used[i]==0){
         chekcycle(i,i,0);
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
   //cout<<r<<"\n";
   while(l+1<r){
      mid=(l+r)/2;
      if(chek(mid))r=mid;
      else l=mid;
   }
   //cout<<r<<"\n";
   //cout<<chek(r)<<"\n";
   cout<<setiosflags(ios::fixed)<<setprecision(6)<<sqrt(r)<<"\n";
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   read();
   solve();
}
