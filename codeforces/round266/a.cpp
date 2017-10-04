#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+9;
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   int a,b,n,m;
   cin>>n>>m>>a>>b;
   b=min(b,a*m);
   int ans=0;
   while(n>=m){
      ans+=b;
      n-=m;
   }
   if(n*a<b)ans+=n*a;
   else ans+=b;
   cout<<ans<<"\n";
}

