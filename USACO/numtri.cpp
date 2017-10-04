/*
ID: dobrikg1
PROG: numtri
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
const int nmax=1009;
int a[nmax][nmax];
int dp[nmax][nmax];
int n;
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   freopen("numtri.in","r",stdin);
   freopen("numtri.out","w",stdout);
   cin>>n;
   for(int i=1;i<=n;i++){
      for(int j=1;j<=i;j++){
         cin>>a[i][j];
      }
   }
   for(int i=1;i<=n;i++)dp[n][i]=a[n][i];
   for(int i=n-1;i>=1;i--){
      for(int j=1;j<=i;j++){
         dp[i][j]=max(dp[i+1][j],dp[i+1][j+1]);
         dp[i][j]+=a[i][j];
      }
   }
   cout<<dp[1][1]<<"\n";
}
