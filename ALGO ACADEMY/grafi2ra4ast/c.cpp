#include<bits/stdc++.h>
using namespace std;
const int nmax=1009;
int dp[nmax];
string name;//za kyv mi e :(
int a[nmax];
int dp2[nmax];
int n;
int main(){
   cin>>n;
   for(int i=1;i<=n;i++){
      cin>>a[i]>>name;
   }
   dp[0]=0;
   a[0]=0;
   a[n+1]=0;
   dp[n+1]=0;
   for(int i=1;i<=n;i++){
      for(int j=0;j<i;j++){
         if(a[i]>a[j]){
            dp[i]=max(dp[j]+1,dp[i]);
         }
      }
   }
   int mx=0;
   for(int i=n;i>=1;i--){
      for(int j=i+1;j<=n;j++){
         if(a[i]>a[j]){
            dp2[i]=max(dp2[j]+1,dp2[i]);
         }
      }
   }
   for(int i=1;i<=n;i++){
      mx=max(dp[i]+dp2[i],mx);
   }
   cout<<mx<<"\n";
}
