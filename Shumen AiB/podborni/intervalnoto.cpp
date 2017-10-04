#include<bits/stdc++.h>
using namespace std;
const int nmax=100000;
int lazy[nmax*5],mx[nmax*5],idx[nmax*5];
struct node{
   int ll,rr,id;
   node(int L,int R,int X){
      ll=L;
      rr=R;
      id=X;
      lazy_update();
   }
   node left(){
      return node(ll,(ll+rr)/2,id*2);
   }
   node right(){
      return node((ll+rr)/2+1,rr,id*2+1);
   }
   void lazy_update(){
      assert(id<=nmax*5);
      if(lazy[id]==0)return;
      mx[id]+=lazy[id];
      if(ll!=rr){
         lazy[id*2]+=lazy[id];
         lazy[id*2+1]+=lazy[id];
      }
      lazy[id]=0;
   }
   void assign_range(int l,int r,int x){
      assert(id<=nmax*5);
      lazy_update();
      if(ll>r||l>rr)return;
      if(ll==rr){
         idx[id]=ll;
      }
      if(l<=ll&&rr<=r){
         lazy[id]+=x;
         lazy_update();
         return;
      }
      left().assign_range(l,r,x);
      right().assign_range(l,r,x);
      if(mx[id*2]>mx[id*2+1]){
         mx[id]=mx[id*2];
         idx[id]=idx[id*2];
      }
      else{
         mx[id]=mx[id*2+1];
         idx[id]=idx[id*2+1];
      }
   }
   int max_range(int l,int r){
      assert(id<=nmax*5);
      if(ll>r||l>rr)return -1e9;
      lazy_update();
      if(l<=ll&&rr<=r){
         return mx[id];
      }
      int mx1=left().max_range(l,r);
      int mx2=right().max_range(l,r);
      return max(mx1,mx2);
      //think this is clear enough
   }
};
int main(){
   int n,m;
   cin>>n>>m;
   node rood(1,n,1);
   for(int i=1;i<=m;i++){
      int x,y,z;
      cin>>x;
      if(x==1){
         cin>>x>>y>>z;
         rood.assign_range(x,y,z);
      }
      if(x==2){
         cin>>x>>y;
         cout<<rood.max_range(x,y)<<"\n";
      }
   }
}
