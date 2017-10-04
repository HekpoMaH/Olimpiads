#include<bits/stdc++.h>
using namespace std;
const int nmax=20;
int n,a[nmax],dp[1<<nmax];
int read(){
   cin>>n;
   for(int i=0;i<n;i++)cin>>a[i];
   sort(a,a+n);
   int mask=0,prev=a[0];
   for(int i=1;i<n;i++){
      if(a[i]!=prev)mask^=(1<<i);
      prev=a[i];
   }
   return mask;
}
int go(int mask){
   if(dp[mask]!=-1)return dp[mask];
   dp[mask]=0;
   int curr;// s dvoino r zaradi bylgarskata publika
   for(int i=1;i<n;i++){
      if(i==n-1||(mask&(1<<(i+1)))){
         for(int j=i-1;j>=0;j--){
            if(mask&(1<<(j+1))){
               curr=mask>>(i+1);
               curr<<=(i-j-1);
               curr|=(mask&((1<<i)-1))>>(j+1);
               curr<<=1;
               curr<<=(j+1);
               curr|=(mask&((1<<(j+1))-1));
               dp[mask]=max(dp[mask],go(curr)^1);
               if(dp[mask]==1)return 1;
            }
         }
      }
   }
   return dp[mask];
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   memset(dp,-1,sizeof(dp));
   cout<<go(read())<<"\n";
}
