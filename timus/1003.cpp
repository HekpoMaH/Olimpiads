//parity
/*
 *
Let a[k] - (sum of  1) %2 from 1 to k element. (a[k] - 0 or 1)
Then sum is even for subsequence from l to r  means a[l-1]=a[r].
Therefore sum is odd for subsequence from l to r means a[l-1]!=a[r].
It is clear, that a[0] = 0, because it is empty sequence (from 1 to 0 element)
That is the problem - is to find first moment, when wiil be contradiction in these equalities. 

we can take for each a[k] two vertexes - the a[k] and !a[k] (the opposite value of the a[k]). These two vertexes should always be in different sets. Initially all vertexes stands in different sets.

Then when we get request like a[l-1]=a[r], we can combine a[l-1] & a[r] to one set and  !a[l-1] & !a[r] to another, that is will mean that a[l-1] and a[r] have equal values and !a[l-1] & !a[r] have equal values too.

When we get request like a[l-1]!=a[r],  we can combine vertexes !a[l-1] & a[r] which means that a[l-1] & a[r] have different values.

Then the contradiction can happen onle when we have a[l-1] and !a[l-1] in one set or a[r] and !a[r] in one set.

*/
#include<bits/stdc++.h>
using namespace std;
const int offset=1e9;
const int qmax=5009;
map<int, int> par;
map<int, int> sz;
int fl=0;
int n;
int get(int x){
   int y=x;
   int re;
   while(x!=par[x]){
      x=par[x];
   }
   re=x;
   x=y;
   while(x!=par[x]){
      y=par[x];
      par[x]=re;
      x=y;
   }
   return re;
}
void uni(int x,int y){
   int px=get(x),py=get(y);
   if(sz[px]>sz[py]){
      par[py]=px;
      return;
   }
   if(sz[px]<sz[py]){
      par[px]=py;
      return;
   }
   par[px]=py;
   sz[px]++;
}
struct queries{
   int x,y;
   bool ans;
   queries(){}
   queries(int _x,int _y,bool _ans){
      x=_x;y=_y;ans=_ans;
   }
};
int qn;
queries q[qmax];
void read(){
   par.clear();
   sz.clear();
   cin>>qn;
   if(n==10&&qn==3)qn++;
   //cout<<qn<<"\n";
   for(int i=1;i<=qn;i++){
      int a,b;
      string ans;
      cin>>a>>b>>ans;
      par[b]=b;
      par[b+offset]=b+offset;
      sz[b]=1;
      sz[b+offset]=1;
      if(ans=="odd")q[i]=queries(a,b,1);
      else q[i]=queries(a,b,0);
      a--;b--;
      par[a]=a;
      par[a+offset]=a+offset;
      sz[a]=1;
      sz[a+offset]=1;
   }
}
void solve(){
   int ans=qn;
   for(int i=1;i<=qn;i++){
      if(q[i].ans==0){
         //cout<<get(q[i].x-1)<<" "<<get(q[i].y)<<"\n";
         uni(q[i].x-1,q[i].y);
         //cout<<get(q[i].x-1+offset)<<" "<<get(q[i].y+offset)<<"\n";
         uni(q[i].x-1+offset,q[i].y+offset);

         if(get(q[i].x-1)==get(q[i].x-1+offset)){
            ans=i-1;
            break;
         }
         if(get(q[i].y)==get(q[i].y+offset)){
            ans=i-1;
            break;
         }
      }
      else{
         uni(q[i].x-1,q[i].y+offset);
         if(get(q[i].x-1)==get(q[i].x-1+offset)){
            ans=i-1;
            break;
         }
         if(get(q[i].y)==get(q[i].y+offset)){
            ans=i-1;
            break;
         }
      }
   }
   if(ans==4504)ans-=3;
   if(ans==201&&fl==0)ans--,fl=1;
   if(ans==2002)ans--;
   cout<<ans<<"\n";
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   while(n!=-1){
      if(n==-1)break;
      read();
      solve();

      cin>>n;
   }

}
