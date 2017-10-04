//It's easy to get the answer by calculating ab(b-1)/2*(1+(a+1)*b/2).
//And /2 is equal to *500000004 while moded by 10^9+7.
//
#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
typedef long long lli;
const int mod=1e9+7;
int a,b;
int main(){
   cin>>a>>b;
   lli sum=0;
   for(int i=1;i<=1e7;i++){
      if(i%b!=0){
         int k=(i/b)/(i%b);
         if(k>=1&&k<=a)sum=(sum+i)%mod,sum%=mod;
      }
   }
   cout<<sum<<"\n";
}
