#include<bits/stdc++.h>
using namespace std;
const int nmax=2009;
int a[2009];
string s,p;
int dp[2009][2009];
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>s>>p;
   for(int i=0;i<s.size();i++){
      int si=i,pi;
      for(pi=0;pi<p.size();pi++){
         while(si<s.size()&&s[si]!=p[pi])si++;
         if(si==s.size())break;
         else si++;
      }
      if(pi==p.size()){
         a[i]=si-i;
      }
      else{
         a[i]=-1;
      }
   }
   //dp[i][j]->masiv s otgovorite za s[0..i]
   for(int i=0;i<s.size();i++){
      for(int j=0;j<=i;j++){
         dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
         dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]);
         if(a[i]!=-1)
            dp[i+a[i]][j+a[i]-p.size()]=max(dp[i+a[i]][j+a[i]-p.size()],dp[i][j]+1);
      }
   }
   for(int i=0;i<=s.size();i++){
     cout<<dp[s.size()][i]<<" "; 
   }
   cout<<"\n";
}
