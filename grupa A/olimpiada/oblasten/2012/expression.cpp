#include<bits/stdc++.h>
using namespace std;
const int nmax=1009;
typedef long long lli;
lli b[nmax];
int n,k;
int main(){
   cin>>n>>k;
   for(int i=2;i<=k;i++)b[i]=1;
   for(int i=3;i<=n;i++){
      for(int j=2;j<=k;j++){
         if(i-j>=2)b[i]+=b[i-j];
         if(i%j==0&&i/j>=2)b[i]+=b[i/j];
      }
   }
   cout<<b[n]<<"\n";
}
