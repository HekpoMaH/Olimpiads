#include<bits/stdc++.h>
using namespace std;
const int nmax=1009;
int n;

int dp[nmax];
int a[nmax];
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   for(int i=1;i<=n;i++){
      cin>>a[i];
   }
   for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
         if(i-j>=0)dp[i]=max(dp[i],dp[i-j]+a[j]);
         else break;
      }
   }
   cout<<dp[n]<<"\n";
}
