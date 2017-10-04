#include<bits/stdc++.h>
using namespace std;
const int nmax=1024;
string s1,s2;
int dp[nmax][nmax];
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   int da[nmax];
   while(1){
      cin>>s1>>s2;
      if(s1=="*"&&s2=="*")exit(0);
      memset(da,0,sizeof(da));
      for(int i=1;i<=s1.size();i++)dp[i+1][1]=i,dp[0][i+1]=999999;
      for(int i=1;i<=s2.size();i++)dp[1][i+1]=i,dp[i+1][0]=999999;
      for(int i=1;i<=s1.size();i++){
         int db=0;
         for(int j=1;j<=s2.size();j++){
            int i1=da[s2[j-1]-'a'];
            int j1=db;
            if(s1[i-1]==s2[j-1]){
               dp[i+1][j+1]=dp[i][j];
               db=j;
            }
            else{
               dp[i+1][j+1]=min(dp[i][j],min(dp[i+1][j],dp[i][j+1]))+1;
            }
            dp[i+1][j+1]=min(dp[i+1][j+1],dp[i1][j1]+(i-i1-1)+1+(j-j1-1));
            //cout<<dp[i-1][j]+1<<" "<<dp[i][j-1]+1<<" "<<
         }
         da[s1[i-1]-'a']=i;
      }
      cout<<dp[s1.size()+1][s2.size()+1]<<"\n";
   }
}
