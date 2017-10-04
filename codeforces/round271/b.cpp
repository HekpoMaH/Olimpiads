#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+9;
int a[nmax],q,psum[nmax];
int n,m;
int dw(int x){

   return lower_bound(psum+1,psum+n+1,x)-&psum[0];
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   for(int i=1;i<=n;i++){
      cin>>a[i];
      psum[i]=psum[i-1]+a[i];
   }
   cin>>m;
   for(int i=1;i<=m;i++){
      cin>>q;
      cout<<dw(q)<<"\n";
   }
}
