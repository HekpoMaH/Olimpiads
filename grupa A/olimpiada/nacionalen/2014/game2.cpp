#include<bits/stdc++.h>
using namespace std;
const int nmax=1009;
int dp[nmax][nmax];
int a[nmax];
int n;
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   for(int i=1;i<=n;i++){
      cin>>a[i];
   }
   for(int l=3;l<=n;l++){
      for(int i=1;i<=n-l+1;i++){
         int j=i+l-1;
         for(int k=i+1;k<=j-1;k++){
            dp[i][j]=max(dp[i][k]+dp[k][j]+a[k]*(a[i]+a[j]),dp[i][j]);
         }
      }
   }
   cout<<dp[1][n]<<"\n";
}
