#include<bits/stdc++.h>
using namespace std;
const int nmax=3*1e5+9;
typedef pair<int,int> pii;
#define mp make_pair
int a[nmax],gcdd[nmax];
int nod(int a,int b){
   return a ? nod(b%a,a) : b;
}
vector<pii> nums;
struct node{
   int ll,rr,id;
   node(int L,int R,int X){
      ll=L,rr=R,id=X;
   }
   node left(){
      return node(ll,(ll+rr)/2,id*2);
   }
   node right(){
      return node((ll+rr)/2+1,rr,id*2+1);
   }
   void assign_range(int l,int r,int x){
      if(ll>r||l>rr)return;
      if(l<=ll&&rr<=r){
         gcdd[id]=x;
         return;
      }
      left().assign_range(l,r,x);
      right().assign_range(l,r,x);
      gcdd[id]=nod(gcdd[id*2],gcdd[id*2+1]);
   }
   int nod_range(int l,int r){
      if(ll>r||l>rr)return 0;
      if(l<=ll&&rr<=r)return gcdd[id];
      int mx1=left().nod_range(l,r);
      int mx2=right().nod_range(l,r);
      return nod(mx1,mx2);
   }
};
int n;
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   node root(1,n,1);
   for(int i=1;i<=n;i++){
      cin>>a[i];
      root.assign_range(i,i,a[i]);
      nums.push_back(mp(a[i],i));
   }
   sort(nums.begin(),nums.end());
   int m;
   cin>>m;
   for(int i=1;i<=m;i++){
      int l,r;
      cin>>l>>r;
      int noda=root.nod_range(l,r);
      cout<<r-l+1-(upper_bound(nums.begin(),nums.end(),mp(noda,r))-lower_bound(nums.begin(),nums.end(),mp(noda,l)))<<"\n";
   }
}
