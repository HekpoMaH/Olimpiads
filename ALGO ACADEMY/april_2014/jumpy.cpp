#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+9;
long long dp[nmax][3];
long long a[nmax],b[nmax];
int n;
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   for(int i=1;i<=n;i++){
      cin>>a[i]>>b[i];
   }
   long long mx=0;
   for(int i=1;i<=n;i++){
      mx=max(mx,b[i]);
      dp[i][1]=dp[i][2]=b[i];
      for(int j=1;j<i;j++){
         if(a[i]>a[j]){
            dp[i][2]=max(dp[i][2],dp[j][1]+b[i]);
         }
         if(a[i]<a[j]){
            dp[i][1]=max(dp[i][1],dp[j][2]+b[i]);
         }
      }
      //dp[i][1]=max(dp[i][1],dp[i-1][1]);
      //dp[i][2]=max(dp[i][2],dp[i-1][2]);
   }
   cout<<max((long long)(mx),max(dp[n][1],dp[n][2]))<<"\n";
}

