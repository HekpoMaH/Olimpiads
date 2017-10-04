#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+33;
const int nmax=1e5+9;
typedef long long lli;
lli n;
lli m;
lli ans;
lli fact[nmax];
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   fact[1]=1;
   for(int i=2;i<=nmax-2;i++){
      fact[i]=i*fact[i-1]%mod;
   }
   cin>>n>>m;
   ans=1;
   for(int i=1;i<=m;i++){
      int x;
      cin>>x;
      n++;
      ans*=fact[x];
      ans%=mod;
   }
   ans*=fact[n];
   ans%=mod;
   cout<<ans<<"\n";
}
