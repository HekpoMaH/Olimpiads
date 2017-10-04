#include<bits/stdc++.h>
using namespace std;
const int nmax=10009;
int dp[nmax];
int find(int a){
   int mn;
   dp[1]=0;
   for(int i=2;i<=a;i++){
      mn=999999;
      for(int p=ceil(sqrt(i));p>1;p--){
         if(i%p==0){
            mn=min(mn,1+max(dp[p],dp[i/p]));
         }
      }
      for(int p=i/2;p>=1;p--){
         mn=min(mn,1+max(dp[p],dp[i-p]));
      }
      dp[i]=mn;
   }
   return dp[a];
}
int main(){
   int n;
   cin>>n;
   cout<<find(n)<<"\n";
}
