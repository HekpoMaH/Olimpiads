#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long lli;
int k;
lli n;

lli ans=0;
lli gcd(lli a,lli b){
   return b==0LL ? a : gcd(b,a%b);
}
lli a[99];
void cnt(int mask){
   lli br=0,pr=1,nod=0,nok;
   for(int i=1;i<=k;i++){
      if((mask&(1<<(i-1)))){
         br++;
           if(nod==0)nod=nok=a[i];
         else if(br>=2){
            lli aa=a[i],bb=nok;
            nod=gcd(aa,bb);
            if(!(nod<=aa&&nod<=bb)){
               cout<<nod<<" "<<aa<<" "<<bb<<"\n";
            }
            assert(nod<=aa&&nod<=bb);
            nok=(aa/nod)*bb;
         }
      }
   }
   if(br==0)return;
   if(br%2==1)ans+=n/(nok)*(1<<(br-1));
   else ans-=n/nok*(1<<(br-1));
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n>>k;
   for(int i=1;i<=k;i++)
    cin>>a[i];
   sort(a+1,a+k+1);
   for(int mask=1;mask<(1<<k);mask++){
      cnt(mask);
   }
   cout<<ans<<"\n";
}
