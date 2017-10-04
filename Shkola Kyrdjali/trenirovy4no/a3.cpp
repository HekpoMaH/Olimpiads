#include<bits/stdc++.h>
using namespace std;
const int maxn=100009;
int n;
int x,t,v;
struct pq{
   int p,q,x,y;
   pq(){};
   pq(int _p,int _q,int _x,int _y){
      p=_p;
      q=_q;
      x=_x;
      y=_y;
   }
};
bool cmp(pq fi,pq se){
   return fi.p<=se.p&&fi.q<=se.q;
}
bool cmps(pq fi,pq se){
   if(fi.p!=se.p){
      return fi.p<se.p;
   }
   return fi.q<se.q;
}
pq p[maxn];
int fl,bz=1;
void read(){
   cin>>n;
   int x[maxn],t[maxn];
   for(int i=1;i<=n;i++){
      cin>>x[i]>>t[i];
   }
   cin>>v;
   for(int i=1;i<=n;i++){
      p[i]=pq(-x[i]+t[i]*v,x[i]+t[i]*v,x[i],t[i]);
   }
}
int solve(){
   sort(p+1,p+n+1,cmps);
   pq lis[maxn];int cur=0;
   int ti=0;
   for(int i=1;i<=n;i++){
      if(p[i].x==0&&p[i].y==0){
         lis[++cur]=p[i];
         ti=i;
         break;
      }
   }
   if(fl==0)cur=0,ti=0;
   for(int i=ti+1;i<=n;i++){
      if(cur==0||cmp(lis[cur],p[i]))lis[++cur]=p[i];
      else{
         int idx=lower_bound(lis+2,lis+cur+1,p[i],cmp)-&lis[0];
         lis[idx]=p[i];

      }
   }
   return cur;
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   read();
   int ans1,ans2;
   ans2=solve();
   p[n+1].p=p[n+1].q=0;
   p[n+1].x=p[n+1].y=0;
   n++;
   fl=1;
   ans1=solve();
   cout<<ans1<<" "<<ans2<<"\n";
}
