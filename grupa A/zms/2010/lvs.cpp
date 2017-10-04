#include<bits/stdc++.h>
using namespace std;
const int nmax=5*1e5+9;
int ans[nmax],maxl[nmax],maxr[nmax];
bool lazy[nmax],lsym[nmax],rsym[nmax];
int n,q;
void composeid(int xid,int l,int r){
   //cout<<"composing "<<xid<<" "<<l<<" <-> "<<r<<"\n";
   int mx=max(ans[xid*2],ans[xid*2+1]);
   lsym[xid]=lsym[xid*2];
   rsym[xid]=rsym[xid*2+1];
   //cout<<rsym[xid*2]<<" "<<lsym[xid*2+1]<<"\n";
   if((rsym[xid*2]^lsym[xid*2+1])==1){
      //cout<<"case1\n";
      int mid=(l+r)/2;
      if(mid-l+1==maxl[xid*2])maxl[xid]=maxl[xid*2]+maxl[xid*2+1];
      else maxl[xid]=maxl[xid*2];
      if(r-(mid+1)+1==maxr[xid*2+1])maxr[xid]=maxr[xid*2+1]+maxr[xid*2];
      else maxr[xid]=maxr[xid*2+1];
      mx=max(mx,maxr[xid*2]+maxl[xid*2+1]);
   }
   else{
      //cout<<"case2\n";
      maxl[xid]=maxl[xid*2];
      maxr[xid]=maxr[xid*2+1];
   }
   ans[xid]=mx;
   //cout<<ans[xid]<<" "<<maxl[xid]<<" "<<maxr[xid]<<" "<<lsym[xid]<<" "<<rsym[xid]<<"\n";
}
struct node{
   int ll,rr,id;
   node(int L,int R,int X){
      ll=L,rr=R,id=X;
      lazy_update();
   }
   node left(){
      return node(ll,(ll+rr)/2,id*2);
   }
   node right(){
      return node((ll+rr)/2+1,rr,id*2+1);
   }
   void lazy_update(){
      if(lazy[id]==0){
         return;
      }
      lazy[id]^=1;
      if(ll!=rr){
         lazy[id*2]^=1;
         lazy[id*2+1]^=1;
      }
      lsym[id]^=1;
      rsym[id]^=1;
      //cout<<id<<" "<<ll<<" "<<rr<<" "<<lsym[id]<<" and "<<rsym[id]<<"\n";
      //cout<<id<<" "<<ll<<" "<<rr<<" "<<lsym[id]<<","<<rsym[id]<<"\n";
      //int id2=id/2;
      //id2/=2;
      //while(id2!=0){
      //   composeid(id2,ll,rr);
      //   id2/=2;
      //}
   }
   void assign_range(int l,int r){
      //cout<<ll<<" "<<rr<<" "<<l<<" "<<r<<"\n";
      if(l<=ll&&rr<=r){
         //cout<<"UEIZI\n";
         lazy[id]^=1;
         lazy_update();
         return;
      }
      if(l>rr||r<ll)return;
      left().assign_range(l,r);
      right().assign_range(l,r);
      composeid(id,ll,rr);
   }
   int max_range(){
      return ans[1];
   }
};
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n>>q;
   node root(1,n,1);
   for(int i=1;i<nmax-4;i++){
      ans[i]=maxl[i]=maxr[i]=1;
   }
   memset(lsym,0,sizeof(lsym));
   memset(rsym,0,sizeof(rsym));
   memset(lazy,0,sizeof(lazy));
   while(q--){
      char tp;
      cin>>tp;
      if(tp=='q'){
         cout<<root.max_range()<<"\n";
      }
      else{
         int x,y;
         cin>>x>>y;
         root.assign_range(x+1,y+1);
      }
      //cout<<"node 1 -> "<<ans[1]<<" "<<maxl[1]<<" "<<maxr[1]<<" "<<lsym[1]<<
   }
}
