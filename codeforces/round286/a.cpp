#include<bits/stdc++.h>
using namespace std;
const int nmax=3009;
typedef long long lli;
int p[nmax];
int used[nmax];
int n;
int prev[nmax],d;
int dp[nmax][nmax];
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n>>d;
   for(int i=1;i<=n;i++){
      cin>>p[i];
      used[p[i]]++;
   }
   memset(dp,-1,sizeof(dp));
   dp[d][0]=used[d];
   int pl[3]={-1,0,1};
   for(int i=1;i<=nmax-1;i++){
      for(int j=0;j<=nmax-1;j++){
         if(dp[i][j]!=-1){
            for(int k=0;k<3;k++){
               if(i+(i-j)+pl[k]<=n)dp[i+(j-i)+pl[k]][i]=max(dp[i+(j-i)+pl[k]][i],dp[i][j]+used[i+j-i+pl[k]]);
            }
         }
      }
   }
   int mx=0;
   for(int i=0;i<=nmax-1;i++){
      mx=max(mx,dp[nmax-1][i]);
   }
   cout<<mx<<"\n";
}
