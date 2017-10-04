#include<bits/stdc++.h>
using namespace std;
const int nmax=4*5e5;
typedef long long lli;
lli lazy[nmax],mx[nmax];
vector<lli> truck[14];
int n,k;
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
   lli max_range(int l,int r){
      if(ll>r||l>rr)return -1;
      if(l<=ll&&rr<=r)return mx[id];
      int mx1=left().max_range(l,r);
      int mx2=right().max_range(l,r);
      return max(mx1,mx2);
   }
};
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n>>k;
   lli expected=n*(n+1)/2;
   if(expected%k!=0){
      cout<<"NO\n";
      exit(0);
   }
   expected/=k;
   node root(1,n,1);
   for(int i=1;i<=n;i++){
      root.assign_range(i,i,i);//iii
   }
   for(int i=1;i<=k;i++){
      lli sum=0;
      while(sum<expected){
         lli need=min((lli)n,expected-sum);
         lli num=root.max_range(1,need);
         //cout<<need<<" "<<num<<"\n";
         truck[i].push_back(num);
         if(num==0){
            cout<<"NO\n";
            exit(0);
         }
         sum+=num;
         root.assign_range(num,num,0);
      }
   }
   for(int i=1;i<=k;i++){
      cout<<truck[i].size()<<"\n";
      for(int j=0;j<truck[i].size();j++){
         cout<<truck[i][j]<<" ";
      }
      cout<<"\n";
   }
}
