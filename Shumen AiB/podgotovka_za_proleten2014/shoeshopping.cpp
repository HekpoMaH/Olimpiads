#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
const int maxn=100009;
lli n,q;
lli a[maxn],psum[maxn];
lli m,k;
//m-pari razp., k-nai skapo
inline void read(){
   cin>>n>>q;
   for(int i=1;i<=n;i++)cin>>a[i];
   sort(a+1,a+n+1);
   for(int i=1;i<=n;i++)psum[i]=a[i]+psum[i-1];
   //for(int i=1;i<=n;i++)cout<<a[i]<<" ";cout<<"\n";
}
inline int find(lli x){
   int l=0,r=n+1;
   int mid;
   while(l+1<r){
      mid=(l+r)/2;
      if(a[mid]<=x)l=mid;
      else r=mid;
   }
   return l;
}
inline int find(lli x,int mr){
   int l=0,r=mr+1;
   int mid;
   while(l+1<r){
      mid=(l+r)/2;
      //cout<<"l="<<l<<" r="<<r<<" mid="<<mid<<" mr="<<mr<<"\n";
      //cout<<psum[mr]-psum[mid-1]<<" "<<x<<"\n";
      //cout.flush();
      if(psum[mr]-psum[mid-1]<=x)r=mid;
      else l=mid;
   } 
   return r;
}
inline void solve(){
   cin>>m>>k;
   int idx1=find(k);
   int idx2=find(m,idx1);
   cout<<max(0,idx1-idx2+1)<<"\n";
   //cout.flush();
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   read();
   for(int i=1;i<=q;i++)solve();
}
