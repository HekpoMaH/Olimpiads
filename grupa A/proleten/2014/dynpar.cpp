#include<bits/stdc++.h>
using namespace std;
const int nmax=2*1e5;
const int inf=1e9;
int lazy[4*nmax];
int sum[4*nmax];
int prefsum[4*nmax];
int mprefsum[4*nmax];
string s;
void combine(int id,int id1,int id2,int prin){
   //if(prin==1)cout<<"combining  "<<"sum["<<id1<<"]="<<sum[id1]<<" prefsum["<<id1<<"]="<<prefsum[id1]<<
      //" sum["<<id2<<"]="<<sum[id2]<<" prefsum["<<id2<<"]="<<prefsum[id2]<<"\n";
   prefsum[id]=min(prefsum[id1],sum[id1]+prefsum[id2]);
   mprefsum[id]=max(mprefsum[id1],sum[id1]+mprefsum[id2]);
   sum[id]=sum[id1]+sum[id2];
   //if(prin==1)cout<<"nw sum and prefsum "<<sum[id]<<" "<<prefsum[id]<<"\n";
}
void invid(int id){
   sum[id]=-sum[id];
   int b=prefsum[id];
   prefsum[id]=-mprefsum[id];
   mprefsum[id]=-b;
}
int o=4*nmax-2;
struct node{
   int ll,rr,id;
   node(){}
   node(int _ll,int _rr,int _id){
      ll=_ll;
      rr=_rr;
      id=_id;
      lazy_update();
   }
   node left(){
      return node(ll,(ll+rr)/2,id*2);
   }
   node right(){
      return node((ll+rr)/2+1,rr,id*2+1);
   }
   inline void lazy_update(){
      //cout<<"LEISI NA "<<id<<" "<<lazy[id]<<"\n";
      if(lazy[id]==0){
         return;
      }
      if(ll==rr){
         invid(id);
         lazy[id]^=1;
         return;
      }
      //cout<<"INVERSING "<<id<<"\n";
      //cout.flush();
      invid(id);
      lazy[id]^=1;
      lazy[id*2]^=1;
      lazy[id*2+1]^=1;
      //cout<<lazy[id]<<" "<<lazy[id*2]<<" "<<lazy[id*2+1]<<"\n";
      //cout.flush();
      //cout<<"node "<<id<<" just got new sum and prefsum "<<sum[id]<<" "<<prefsum[id]<<"\n";
   }
   void assign_range(int l,int r){
      //cout<<ll<<" "<<rr<<" "<<l<<" "<<r<<"\n";
      if(l<=ll&&rr<=r){
         //cout<<"old ones "<<sum[id]<<" "<<prefsum[id]<<" "<<mprefsum[id]<<"\n";
         invid(id);
         //cout<<"neww ones "<<sum[id]<<" "<<prefsum[id]<<" "<<mprefsum[id]<<"\n";
         if(ll!=rr){
            lazy[id*2]^=1;
            lazy[id*2+1]^=1;
         }
         //cout<<"E "<<l<<" "<<ll<<" "<<rr<<" "<<r<<" "<<lazy[id]<<"\n";
         //cout<<"returned\n";
         return;
      }
      if(r<ll||rr<l)return;
      left().assign_range(l,r);
      right().assign_range(l,r);
      combine(id,left().id,right().id,0);
   }
   void sba4kaigi(){
      if(ll==rr){
         int x=s[ll-1]=='(' ? +1 : -1;
         sum[id]=x;
         prefsum[id]=min(x,0);
         mprefsum[id]=max(x,0);
         return;
      }
      left().sba4kaigi();
      right().sba4kaigi();
      combine(id,left().id,right().id,0);
   }
   int getsum(int l,int r){
      if(rr<l||r<ll)return 0;
      if(l<=ll&&rr<=r){
         return sum[id];
      }
      return left().getsum(l,r)+right().getsum(l,r);
   }
   void minpref(int l,int r){
      //cout<<l<<" "<<r<<" "<<ll<<" "<<rr<<"\n";
      if(rr<l||r<ll)return;
      if(l<=ll&&rr<=r){
         combine(o,o,id,1);
         return;
      }
      left().minpref(l,r);
      right().minpref(l,r);
      return;
   }
};
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   int n,q;
   cin>>n;
   cin>>s;
   cin>>q;
   node root(1,n,1);
   root.sba4kaigi();
   //root.assign_range(1,n);
   //exit(0);
   //cout<<root.minpref(1,4)<<"\n";
   for(int i=1;i<=q;i++){
      char ch;int x,y;
      cin>>ch>>x>>y;
      if(ch=='u')root.assign_range(x,y);
      else{
         sum[o]=0;
         prefsum[o]=inf;
         mprefsum[o]=0;
         root.minpref(x,y);
         //cout<<sum[o]<<" "<<prefsum[o]<<"\n";
         if(prefsum[o]>=0&&sum[o]==0)cout<<"1\n";
         else cout<<"0\n";
         exit(0);
      }
      //cout<<sum[1]<<","<<prefsum[1]<<","<<lazy[1]<<"\n";
   }
   //sum[o]=0;
   //prefsum[o]=inf;
   //mprefsum[o]=0;
   //root.minpref(2,3);
   //cout<<sum[o]<<" "<<prefsum[o]<<"\n";
}
