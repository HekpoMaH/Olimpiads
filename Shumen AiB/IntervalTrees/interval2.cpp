#include<bits/stdc++.h>
using namespace std;
const int nmax=1e4+9;
int lazy[4*nmax],mx[4*nmax];
struct node{
   int ll,rr,id;
   node(int _ll,int _rr,int _id){
      ll=_ll;rr=_rr;id=_id;
      lazy_update();
   }
   node left(){
      return node(ll,(ll+rr)/2,id*2);
   }
   node right(){
      return node((ll+rr)/2+1,rr,id*2+1);
   }
   void lazy_update(){
      if(lazy[id]==-1)return;
      if(ll!=rr){
         lazy[id*2]=lazy[id*2+1]=lazy[id];
      }
      mx[id]=lazy[id];
      lazy[id]=-1;
   }
   void assign_range(int l,int r,int x){
      if(ll>r||l>rr)return;
      if(l<=ll&&rr<=r){
         lazy[id]=x;
         lazy_update();
         return;
      }
      left().assign_range(l,r,x);
      right().assign_range(l,r,x);
      mx[id]=max(mx[id*2],mx[id*2+1]);
   }
   int max_range(int l,int r){
      if(ll>r||l>rr)return -1;
      if(l<=ll and rr<=r){
         return mx[id];
      }
      int mx1=left().max_range(l,r);
      int mx2=right().max_range(l,r);
      return max(mx1,mx2);
   }
};
int main(){
   int n;
   cin>>n;
   node root(1,n,1);
   for(int i=1;i<=n;i++){
      int x;
      cin>>x;
      root.assign_range(i,i,x);
   }
   root.assign_range(3,n,19);
   cout<<root.max_range(1,2)<<" "<<root.max_range(3,n)<<"\n";
   root.assign_range(3,n,15);
   cout<<root.max_range(1,2)<<" "<<root.max_range(3,n)<<"\n";
}
