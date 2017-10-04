#include<bits/stdc++.h>
using namespace std;
const int nmax=1009;
int dp[nmax][nmax];
int a[nmax];
int n,k;
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   memset(dp,-1,sizeof(dp));
   cin>>n>>k;
   dp[0][0]=0;
   for(int i=1;i<=n;i++){
      cin>>a[i];
      for(int j=0;j<k;j++){
         //cout<<"dp["<<i<<"]["<<(a[i]+j)%k<<"]=max("<<dp[i-1][j]+1<<","<<dp[i][(a[i]+j)%k]<<")\n";
         if(dp[i-1][j]!=-1){
            dp[i][(a[i]+j)%k]=max(dp[i-1][j]+1,dp[i][(a[i]+j)%k]);
            //cout<<"dp["<<i<<"]["<<j<<"]=max("<<dp[i-1][j]<<","<<dp[i][j]<<")\n";
            dp[i][j]=max(dp[i][j],dp[i-1][j]);
         }
         //cout.flush();

      }
   }
   cout<<dp[n][0]<<"\n";
}
