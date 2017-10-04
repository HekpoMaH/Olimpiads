#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
void solve(){
   lli n;
   cin>>n;
   lli a=0,b=0,c=0;
   lli res=0;
   for(lli i=0;4LL*(1LL<<i)<n;i++){
      res++;
      a+=1LL<<i;
      b+=1LL<<i;
      c+=1LL<<i;
      n-=(1LL<<i)*3;
   }
   a+=n;
   cout<<a<<" "<<b<<" "<<c<<"\n";
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   int t;
   cin>>t;
   while(t--){
      solve();
   }
}
