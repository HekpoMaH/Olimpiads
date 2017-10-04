#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+9;
int low[nmax],hi[nmax],sum[nmax];
int n,q;
int ans=nmax-5;
bool lazy[nmax];
string s;
void combine(int idx,int idx1,int idx2){
   low[idx]=min(low[idx1],sum[idx1]+low[idx2]);
   hi[idx]=max(hi[idx1],sum[idx1]+hi[idx2]);
   sum[idx]=sum[idx1]+sum[idx2];
  
}
void inv(int idx){
   sum[idx]=-sum[idx];
   int b=low[idx];
   low[idx]=-hi[idx];
   hi[idx]=-b;
}
struct node{
   int ll,rr,id;
   node(){};
   node(int _ll,int _rr,int _id){
      ll=_ll;
      rr=_rr;
      id=_id;
      lazy_update();
   }
   node left(){
      return node(ll,(ll+rr)/2,2*id);
   }
   node right(){
      return node((ll+rr)/2+1,rr,2*id+1);
   }
   void lazy_update(){
      if(lazy[id]==0)return;
      inv(id);
      lazy[id]^=1;
      if(ll==rr)return;
      lazy[id*2]^=1;
      lazy[id*2+1]^=1;
   }
   void assign_range(int L,int R){
      if(L<=ll&&rr<=R){
         lazy[id]=1;
         lazy_update();
         return;
      }
      if(R<ll||rr<L)return;
      left().assign_range(L,R);
      right().assign_range(L,R);
      combine(id,left().id,right().id);
   }
   void prep(){
      if(ll==rr){
         int x= s[ll-1]=='(' ? 1 : -1;
         //cout<<x<<" "<<ll<<"\n";
         sum[id]=x;
         hi[id]=max(x,0);
         low[id]=min(x,0);
         //cout<<sum[id]<<" "<<hi[id]<<" "<<low[id]<<"\n";
         return;
      }
      left().prep();
      right().prep();
      combine(id,left().id,right().id);
   }
   void minpref(int L,int R){
      if(R<ll||rr<L)return;
      if(L<=ll&&rr<=R){
         combine(ans,ans,id);
         return;
      }
      left().minpref(L,R);
      right().minpref(L,R);
   }
};
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   cin>>s;
   cin>>q;
   node root(1,n,1);
   root.prep();
   for(int i=1;i<=q;i++){
      char ch;
      int x,y;
      cin>>ch>>x>>y;
      if(ch=='u'){
         root.assign_range(x,y);
      }
      else{
         sum[ans]=0;
         low[ans]=1e9;
         hi[ans]=0;
         root.minpref(x,y);
         //cout<<sum[ans]<<" "<<low[ans]<<"\n";
         if(sum[ans]==0&&low[ans]>=0)cout<<"1\n";
         else cout<<"0\n";
      }
   }
}
