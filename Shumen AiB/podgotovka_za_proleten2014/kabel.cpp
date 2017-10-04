#include<bits/stdc++.h>
using namespace std;
const int maxl=2009;
int dp[maxl];
int n,l;
int p,r,q,f;
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n>>l;
   memset(dp,31,sizeof(dp));
   const int inf=dp[2];
   dp[0]=0;
   for(int i=1;i<=n;i++){
      cin>>p>>r>>q>>f;
      /*„Ние с радост ще ви продадем 1 метър кабел за Pi пари, но ако купите не по-малко от Ri метра, ще получите прекрасна отстъпка – всеки закупен метър ще ви струва само Qi пари“*/ 
      for(int j=200;j>=1;j--){
         for(int k=1;k<=j&&k<=f;k++){
            if(k<r){
               dp[j]=min(dp[j],dp[j-k]+k*p);
            }
            else dp[j]=min(dp[j],dp[j-k]+k*q);
         }
      }
   }
   int ans=inf;
   for(int i=l;i<=200;i++)if(dp[i]<ans)ans=dp[i];
   if(ans==inf)cout<<-1<<"\n";
   else cout<<ans<<"\n";
}
