#include<bits/stdc++.h>
using namespace std;
string eli;
const int nmax=1009;
int dp[nmax];
int n;
string words[nmax];
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   cin>>eli;
   for(int i=1;i<=n;i++){
      cin>>words[i];
   }
   dp[0]=0;
   int esz=eli.size();;
   for(int i=1;i<=esz;i++){
      for(int j=1;j<=n;j++){
         if(i-(int)words[j].size()<0)continue;
         string s1=eli.substr(i-1-words[j].size()+1,words[j].size());
         if(s1==words[j]){
            dp[i]=max(dp[i-words[j].size()]+1,dp[i]);
         }
      }
      dp[i]=max(dp[i],dp[i-1]);
   }
   cout<<dp[eli.size()]<<"\n";
}
