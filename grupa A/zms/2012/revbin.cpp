#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
const int mod=1e9+1;
lli s,m;
lli partsum(lli k){
   lli e=0;
   lli sum=0,f,g,r;
   if(k==0||k==-1)return 0;
   f=2;g=1;
   for(int i=1;i<=s;i++){
      e=((k+1)/(1<<i))<<(i-1);
      r=(k+1)%f;
      if(r>g)e+=r-g;
      if(e>0){
         e=(e<<(s-i))%mod;
         sum=(sum+e)%mod;
      }
      else break;
      f*=2;g*=2;
   }
   return sum;
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>s>>m;
   for(int i=1;i<=m;i++){
      lli a,b;
      cin>>a>>b;
      cout<<(mod+partsum(b)-partsum(a-1))%mod<<"\n";
   }
}
