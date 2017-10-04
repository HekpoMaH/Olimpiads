#include<bits/stdc++.h>
using namespace std;
const int nmax=100009;
int a;
int dp[nmax][12];
int n,b,c,d;
int inf=1e9;
void solve(){
   cin>>n>>b>>c>>d;
   for(int i=0;i<=n;i++){
      for(int j=b;j<=c;j++){
         dp[i][j]=-inf;
      }
   }
   for(int i=b;i<=c;i++){
      dp[0][i]=0;
   }
   for(int i=1;i<=n;i++){
      cin>>a;
      for(int j=b;j<=c;j++){
         //cout<<j-d<<" "<<j+d<<"\n";
         for(int k=max(b,j-d);k<=min(j+d,c);k++){
            //cout<<"dp["<<i<<"]["<<j<<"]="<<" "<<dp[i-1][k]<<"+"<<a<<"*"<<j<<"\n";
            dp[i][j]=max(dp[i-1][k]+a*j,dp[i][j]);
         }
      }
   }
   int mx=-inf;
   //for(int i=0;i<=n;i++){
   //   for(int j=b;j<=c;j++){
   //      cout<<dp[i][j]<<" ";
   //   }
   //   cout<<"\n";
   //}
   for(int j=b;j<=c;j++){
      mx=max(mx,dp[n][j]);
   }
   cout<<mx<<"\n";
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   solve();
}
