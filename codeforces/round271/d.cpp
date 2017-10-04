#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+9;
const int mod=1e9+7;
int dp[nmax][3];
int psum[nmax];
int t,k;
void calcdp(){
   //1=R 2=W
   dp[0][1]=1;
   dp[0][2]=0;
   for(int i=1;i<=nmax-4;i++){
      //eat R
      dp[i][1]=(dp[i-1][1]+dp[i-1][2])%mod;
      if(i>=k)dp[i][2]=(dp[i-k][1]+dp[i-k][2])%mod;
   }
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>t>>k;
   calcdp();
   for(int i=1;i<=nmax-4;i++){
      psum[i]=(psum[i-1]+(dp[i][1]+dp[i][2])%mod)%mod;
   }
   for(int i=1;i<=t;i++){
      int a,b;
      cin>>a>>b;
      cout<<(mod+psum[b]-psum[a-1])%mod<<"\n";
   }
}
