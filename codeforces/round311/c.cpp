#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
const int nmax=1e5+9;
int n;
struct leg{
   int l,d;
   bool operator<(const leg &x)const{
      if(d>x.d)return true;
      return false;
   }
};
bool cmp(leg on,leg tw){
   if(on.l<tw.l)return true;
   if(on.l>tw.l)return false;
   if(on.d<tw.d)return true;
   return false;
}
leg t[nmax];
int sum[nmax],ans=1e9;
priority_queue<leg> pq,pq2;

int lazy[nmax],mx[nmax];
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
   int max_range(int l,int r){
      if(ll>r||l>rr)return -1;
      if(l<=ll&&rr<=r)return mx[id];
      int mx1=left().max_range(l,r);
      int mx2=right().max_range(l,r);
      return max(mx1,mx2);
   }
};
int main(){
   cin>>n;
   for(int i=1;i<=n;i++){
      cin>>t[i].l;
   }
   for(int i=1;i<=n;i++){
      cin>>t[i].d;
   }
   sort(t+1,t+n+1,cmp);
   t[n+1].l=-1;
   for(int i=1;i<=n;i++){
      //cout<<t[i].l<<" "<<t[i].d<<"\n";
      sum[i]=sum[i-1]+t[i].d;
   }
   int last=1;
   for(int i=1;i<=n;i++){
      if(t[i].l!=t[i+1].l){
         int cur_sum=sum[n]-sum[i];
         int cur_number_of_legs=i;
         while(t[last].l<t[i].l){
            pq.push(t[last]);
            //cout<<last<<"++\n";
            //cout<<"pushed "<<t[last].l<<"2 "<<t[last].d<<"\n";
            last++;
         }
         int legs_of_mx=i-last+1;
         //cout<<i<<" "<<last<<" "<<legs_of_mx<<" "<<cur_sum<<"\n";
         pq2=pq;
         int zamahane=max(0,cur_number_of_legs-legs_of_mx*2+1);//curnl-x-mx*2<0 => x>curnl-mx*2
         //cout<<legs_of_mx*2<<" "<<cur_number_of_legs<<"\n";
         while(!pq2.empty()&&zamahane){
            //cout<<pq2.top().l<<" "<<pq.top().d<<"\n";
            cur_sum+=pq2.top().d;
            pq2.pop();
            cur_number_of_legs--;
            zamahane--;
         }
         //cout<<"nw sum "<<cur_sum<<"\n";
         if(legs_of_mx*2<=cur_number_of_legs)continue;
         ans=min(ans,cur_sum);
      }
   }
   cout<<ans<<"\n";
}
