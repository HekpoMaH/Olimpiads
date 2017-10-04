#include<bits/stdc++.h>
using namespace std;
int k,n;

vector<int> v[6];
vector<int> lcs(int ii,int jj){
   int dp[1009][1009];
   int from[1009][1009];
   vector<int> re;
   re.clear();
   //1-left, 2-up, 3-diag
   for(int i=0;i<=n;i++){
      dp[0][i]=dp[i][0]=0;
   }
   for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
         if(v[ii][i-1]==v[jj][j-1]){
            dp[i][j]=dp[i-1][j-1]+1;
            from[i][j]=3;
         }
         else{
            if(dp[i-1][j]>dp[i][j-1]){
               dp[i][j]=dp[i-1][j];
               from[i][j]=2;
            }
            else{
               dp[i][j]=dp[i][j-1];
               from[i][j]=1;
            }
         }
      }
   }
   int cx=n,cy=n;
   while(cx!=0&&cy!=0){
      if(from[cx][cy]==3){
         re.push_back(v[ii][cx-1]);
         cx--;cy--;
      }
      else if(from[cx][cy]==1){
         cy--;
      }
      else{
         cx--;
      }
   }
   reverse(re.begin(),re.end());
   return re;
}
bool chek(int ii,vector<int> seq){
   int cur=0;
   for(int i=0;i<n;i++){
      if(v[ii][i]==seq[cur]){
         cur++;
      }
      if(cur==seq.size())return true;
   }
   return false;
}
int main(){
   cin>>n>>k;
   for(int i=1;i<=k;i++){
      for(int j=1;j<=n;j++){
         int x;
         cin>>x;
         v[i].push_back(x);
      }
   }
   int ans=0;
   for(int i=1;i<=k;i++){
      for(int j=1;j<=k;j++){
         if(i==j)continue;
         vector<int> seq=lcs(i,j);
         bool fl=1;
         for(int l=1;l<=k;l++){
            if(l==i||l==j)continue;
            fl=min(fl,chek(l,seq));
         }
         if(fl==1){
            ans=max(ans,(int)seq.size());
         }
      }

   }
   cout<<ans<<"\n";
}
