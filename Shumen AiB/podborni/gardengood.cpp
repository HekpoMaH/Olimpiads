#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int nmax=200009;
typedef long long lli;
lli n,w,h;
struct centar{
   lli xc,yc,inidx;
};
vector<centar> v;
double x,y;
lli xx,yy,igreci[nmax];
lli it[nmax*4];
lli lazy[nmax*4];
lli ans[nmax];
struct node{
   lli ll,rr,id;
   node(){}
   node(lli L,lli R,lli X){
      ll=L;
      rr=R;
      id=X;
   }
   node left(){
      return node(ll,(ll+rr)/2,id*2);
   }
   node right(){
      return node((ll+rr)/2+1,rr,id*2+1);
   }
   void assign_range(lli L,lli R,lli X){
      if(L>rr||R<ll)return;
      if(L<=ll&&rr<=R){
         it[id]=X;
         return;
      }
      left().assign_range(L,R,X);
      right().assign_range(L,R,X);
   }
   lli qry(lli pos){
      if(rr<pos)return 0;
      if(ll>pos)return 0;
      if(ll==rr&&ll==pos)return it[id];
      lli mx=max(left().qry(pos),it[id]);
      mx=max(right().qry(pos),mx);
      return mx;
   }
};
bool cmp(centar x4,centar y4){
   if(x4.xc<y4.xc)return true;
   if(x4.xc>y4.xc)return false;
   if(x4.yc>y4.yc)return true;
   return false;
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>w>>h>>n;
   node root(1,n,1);
   centar wtf;
   lli np=n;
   for(lli i=1;i<=n;i++){
      cin>>x>>y;
      xx=round(x*2.0);
      yy=round(y*2.0);
      igreci[i]=yy;
      wtf.xc=xx;
      wtf.yc=yy;
      wtf.inidx=i;
      v.pb(wtf);
   }
   igreci[n+1]=0;igreci[n+2]=h*2;
   sort(igreci+1,igreci+n+3);
   unique(igreci+1,igreci+n+3);
   n=unique(igreci+1,igreci+n+3)-&igreci[0]-1;
   igreci[0]=-10000;
   sort(v.begin(),v.end(),cmp);
   lli r,qr,lidx,ridx;
   for(lli i=0;i<v.size();i++){
      qr=root.qry(lower_bound(igreci+1,igreci+n+1,v[i].yc)-&igreci[0]);
      r=v[i].xc-qr;
      ans[v[i].inidx]=r;
      lidx=lower_bound(igreci+1,igreci+n+1,v[i].yc-r)-&igreci[0];
      ridx=upper_bound(igreci+1,igreci+n+1,v[i].yc+r)-&igreci[0]-1;
      if(ridx==0)ridx=1;
      root.assign_range(lidx,ridx,v[i].xc+r);
   }
   for(lli i=1;i<=np;i++){
      cout<<ans[i]<<"\n";
   }
}
