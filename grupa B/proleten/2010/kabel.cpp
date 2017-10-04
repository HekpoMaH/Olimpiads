#include<bits/stdc++.h>
using namespace std;
const int maxl=109;
const int inf;
int dp[maxl];
int n,l;
int p,r,q,f;
int main(){
   ios_base::sync_with_stio(false);
   cin.tie(0);
   cin>>n>>l;
   memset(dp,31,sizeof(dp));
   inf=dp[2];
   dp[0]=0;
   for(int i=1;i<=n;i++){
      cin>>p>>r>>q>>f;
      /*„Ние с радост ще ви продадем 1 метър кабел за Pi пари, но ако купите не по-малко от Ri метра, ще получите прекрасна отстъпка – всеки закупен метър ще ви струва само Qi пари“*/ 
      for(int j=1;j<=l;j++){
         for(int k=1;k<=j&&k<=f;k++){
            if(k<r){
               dp[j]=min(dp[j],dp[j-k]+k*p);
            }
            else dp[j]=min(dp[j],dp[j-k]+k*q;
         }
      }
   }
   if(dp[l]==inf)cout<<-1<<"\n";
   else cout<<dp[l]<<"\n";
}
