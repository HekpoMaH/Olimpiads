#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
lli inf=1e18;
lli l,r,n;
lli a[23];
lli x;
int main(){
   cin>>x>>n;
   for(int i=1;i<=n;i++)cin>>a[i];
   l=1;r=inf;
   lli mid;
   while(l+1<r){
      mid=(l+r)/2;
      lli sum=0;
      for(int i=1;i<=n;i++){
         sum+=mid/a[i];
      }
      if(sum>=x)r=mid;
      else l=mid;
   }
   cout<<r<<"\n";
}
