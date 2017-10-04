#include<bits/stdc++.h>
using namespace std;
const int nmax=109;
int p[nmax];
int dp[nmax][nmax];
int n;
int main(){
   cin>>n;
   memset(dp,31,sizeof(dp));
   for(int i=0;i<=n;i++){
      cin>>p[i];
      dp[i][i]=0;
   }
   for(int l=2;l<=n;l++){
      for(int i=1;i<=n-l+1;i++){
         int j=i+l-1;
         for(int k=i;k<j;k++){
            int st=dp[i][k]+dp[k+1][j]+p[i-1]*p[k]*p[j];
            dp[i][j]=min(st,dp[i][j]);
         }
      }
   }
   cout<<dp[1][n]<<"\n";
}
