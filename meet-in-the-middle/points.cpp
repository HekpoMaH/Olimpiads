#include<bits/stdc++.h>
using namespace std;
const int nmax=40;
typedef long long lli;
lli a[nmax];
lli n;
lli hlf;
lli h1[nmax],h2[nmax];
lli br1,br2;
lli t;
#define pb push_back
vector<lli> sums;
int main(){
   cin>>n>>t;
   for(int i=1;i<=n;i++){
      cin>>a[i];
   }
   hlf=n/2;
   for(int i=1;i<=hlf;i++){
      h1[++br1]=a[i];
   }
   for(int i=hlf+1;i<=n;i++){
      h2[++br2]=a[i];
   }
   for(int mask=0;mask<(1<<br1);mask++){
      lli sum=0;
      for(int i=1;i<=br1;i++){
         if((1<<(i-1))&mask){
            sum+=h1[i];
         }
      }
      sums.pb(sum);
   }
   sort(sums.begin(),sums.end());
   lli ans=0;
   for(int mask=0;mask<(1<<br2);mask++){
      lli sum=0;
      for(int i=1;i<=br2;i++){
         if((1<<(i-1))&mask){
            sum+=h2[i];
         }
      }
      //cout<<sum<<" "<<*lower_bound(sums.begin(),sums.end(),t-sum)<<" "<<sums.end()-lower_bound(sums.begin(),sums.end(),t-sum)<<"\n";
      ans+=sums.end()-lower_bound(sums.begin(),sums.end(),t-sum);
   }
   cout<<ans<<"\n";
}
