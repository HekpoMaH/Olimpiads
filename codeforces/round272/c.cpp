#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
typedef long long lli;
const lli mod =1e9+7;
lli a,b;
int main(){
   cin>>a>>b;
   lli rem=(b*(b-1)/2)%mod;
   lli o=0;
   for(lli k=1;k<=a;k++){
      o=(o+((k*b+1)%mod*rem))%mod;
   }
   cout<<o<<"\n";
}

