#include<bits/stdc++.h>
using namespace std;
int lazy[1000],mx[1000],idx[1000];
//lazy->ima nqma za update (!=0 ima 0 nqma)
//mx-> max stoinost
//idx-> pos kydeto e tazi stoinost
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
      if(lazy[id]==0)return;
      mx[id]+=lazy[id];
      if(ll!=rr){
         lazy[id*2]+=lazy[id];
         lazy[id*2+1]+=lazy[id];
      }
      lazy[id]=0;
   }
   void assign_range(int l,int r,int x){
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
   node root(1,6,1);
   for(int i=1;i<=6;i++)root.assign_range(i,i,0);
   int m;
   cin>>m;
   for(int i=1;i<=m;i++){
      int a,b,c;
      cin>>a>>b>>c;
      root.assign_range(a,b,c);
      cout<<root.max_range(1,6)<<" "<<idx[1]<<"\n";
      //cout<<root.max_range(5,5)<<"\n";
   }
}
