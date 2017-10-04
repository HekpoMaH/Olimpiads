#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int nmax=5*1e5+9;
vector<int> ds[nmax];
vector<int> prazen;
int a[nmax];
int last[nmax];
int d[nmax];
int n,m;
struct node{
   int ll,rr,id;
   node(){}
   node(int L,int R,int X){
      ll=L,rr=R,id=X;
   }
   node left(){
      return node(ll,(ll+rr)/2,id*2);
   }
   node right(){
      return node((ll+rr)/2+1,rr,id*2+1);
   }
   void assign_range(int l,int r){
      //cout<<l<<" "<<r<<" "<<id<<"\n";
      //cout.flush();
      if(ll>r||l>rr)return;
      if(ll==rr){
         //cout<<"d["<<ll<<"]="<<d[ll]<<"\n";
         ds[id].pb(d[ll]);
         return;
      }
      left().assign_range(l,(l+r)/2);
      right().assign_range((l+r)/2+1,r);
      assert(ds[left().id].size()!=0);
      assert(ds[right().id].size()!=0);
      ds[id].resize(ds[left().id].size()+ds[right().id].size());
      merge(ds[left().id].begin(), ds[left().id].end(), ds[right().id].begin(), ds[right().id].end(), ds[id].begin());
      //cout<<"i="<<ds[id].size()<<"\n";
      cout.flush();
      if(ds[id][0]==-1&&ds[id][1]==-1)ds[id].erase(ds[id].begin());
   }
};
int calcscore(node danod,int ql){
   return max(danod.rr-max(danod.ll,ql)+1-(ds[danod.id].end()-lower_bound(ds[danod.id].begin(),ds[danod.id].end(),ql)),0);
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   int q,p=0;
   memset(last,-1,sizeof(last));
   cin>>n;
   cin>>m;
   for(int i=1;i<=n;i++){
      cin>>a[i];
      d[i]=last[a[i]];
      last[a[i]]=i;
   }
   node root(1,n,1);
   root.assign_range(1,n);
   //cout<<ds[root.id].size()<<"\n";
   //for(int i=0;i<ds[root.id].size();i++){
   //   cout<<ds[root.id][i]<<" ";
   //}
   //cout<<"\n";
   int x,y;
   cin>>q;
   for(int i=1;i<=q;i++){
      cin>>x>>y;
      int l=((x+p)%n)+1;
      int k=((y+p)%m)+1;
      int toad=0;
      if(n-l+1-(ds[root.id].end()-lower_bound(ds[root.id].begin(),ds[root.id].end(),l))<k){
         cout<<0<<"\n";
         p=0;
         continue;
      }
      node curn=root;
      while(curn.ll!=curn.rr){
         node lqv,desen;
         lqv=curn.left();
         desen=curn.right();
         if(toad+calcscore(lqv,l)>=k){
            curn=lqv;
            continue;
         }
         else{
            toad+=calcscore(lqv,l);
            curn=desen;
         }
      }
      cout<<curn.ll<<"\n";
      p=curn.ll;
   }
}
