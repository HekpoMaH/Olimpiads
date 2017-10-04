#include<bits/stdc++.h>
using namespace std;
long long a,b,n;
long long ans=1e12,aans,bans;
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   int l=0;
   cin>>n>>a>>b;
   if(a>b)swap(a,b),l=1;
   long long sz=6LL*n;
   if(a*b>=sz){
      cout<<a*b<<"\n"<<a<<" "<<b<<"\n";
      return 0;
   }
   long long sqr=ceil(sqrt(sz));
   for(long long i=a;i<=sqr;i++){
      int nb=ceil((double)sz/(double)i);
      if(nb>=b){
         if(i*nb<ans){
            ans=i*nb;
            aans=i;
            bans=nb;
         }
      }
   }
   if(l)swap(aans,bans);
   cout<<ans<<"\n"<<aans<<" "<<bans<<"\n";
}
