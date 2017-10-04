#include<bits/stdc++.h>
using namespace std;
const int nmax=30009;
int dp[nmax];
int a[nmax];
int n;
int mx=0;
void solve1(){
   dp[1]=0;
   dp[2]=0;
   for(int i=3;i<n;i++){
      dp[i]=max(dp[i-2]+a[i],dp[i-1]);
   }
   mx=max(mx,a[1]+dp[n-1]);
}
void solve2(){
   dp[0]=dp[1]=0;
   for(int i=2;i<=n;i++){
      dp[i]=max(dp[i-2]+a[i],dp[i-1]);
   }
   mx=max(mx,dp[n]);
}
int main(){
   cin>>n;
   for(int i=1;i<=n;i++){
      cin>>a[i];
   }
   solve1();
   solve2();
   cout<<mx<<"\n";
}
