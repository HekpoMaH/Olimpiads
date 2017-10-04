
#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5*2+9;
int a[nmax],n,t,block,cnt[(int)1e6+9];
long long ans[nmax],curr;
struct qry{
   int l,r,id;
   bool operator <(const qry &b)const{
      if(l/block==b.l/block)return r<b.r;
      return l<b.l;
   }
};
qry q[nmax];
void add(int x){
   curr+=(2*cnt[x]+1)*x;
   cnt[x]++;
}
void del(int x){
   curr+=(-2*cnt[x]+1)*x;
   cnt[x]--;
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n>>t;
   for(int i=1;i<=n;i++)cin>>a[i];
   block=sqrt(n);
   for(int i=0;i<t;i++){
      cin>>q[i].l>>q[i].r;
      q[i].id=i;
   }
   sort(q,q+t);
   int currL=1,currR=0;
   for(int i=0;i<t;i++){
      while(q[i].l<currL)add(a[--currL]);
      while(q[i].l>currL)del(a[currL++]);
      while(q[i].r>currR)add(a[++currR]);
      while(q[i].r<currR)del(a[currR--]);
      ans[q[i].id]=curr;
   }
   for(int i=0;i<t;i++){
      cout<<ans[i]<<"\n";
   }
}
