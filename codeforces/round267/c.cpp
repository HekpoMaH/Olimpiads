#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
const int nmax=5*(1e3)+9;
int p[nmax];
lli ps[nmax];
int n,m,k;
lli dp[nmax][nmax];
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n>>m>>k;
   for(int i=1;i<=n;i++){
      cin>>p[i];
      ps[i]=(lli)p[i]+ps[i-1];
   }
   for(int i=1;i<=k;i++){
      for(int j=1;j<=n;j++){
         if(j-m<0){
            dp[i][j]=-1;
            continue;
         }
         if(dp[i-1][j-m]==-1)continue;
         dp[i][j]=max(dp[i][j-1],dp[i-1][j-m]+ps[j]-ps[j-m]);
      }
   }
   cout<<dp[k][n]<<"\n";
}

