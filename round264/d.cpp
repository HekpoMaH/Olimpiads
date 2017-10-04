#include<bits/stdc++.h>
using namespace std;
int k,n;

int from[1009][1009];
vector<int> v[6];
vector<vector<int> > alcs;
void go(int ii,int jj,int cx,int cy,vector<int> cur){
   if(cx==0||cy==0){
      reverse(cur.begin(),cur.end());
      alcs.push_back(cur);
      return;
   }
   if(from[cx][cy]==3){
      cur.push_back(v[ii][cx-1]);
      go(ii,jj,cx-1,cy-1,cur);
      cur.pop_back();
   }
   else if(from[cx][cy]==1){
      go(ii,jj,cx,cy-1,cur);
   }
   else if(from[cx][cy]==2){
      go(ii,jj,cx-1,cy,cur);
   }
   else if(from[cx][cy]==12){
      go(ii,jj,cx,cy-1,cur);
      go(ii,jj,cx-1,cy,cur);
   }
}
void lcs(int ii,int jj){
   int dp[1009][1009];
   memset(from,0,sizeof(from));
   //1-left, 2-up, 3-diag
   for(int i=0;i<=n;i++){
      dp[0][i]=dp[i][0]=0;
   }
   for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
         if(v[ii][i-1]==v[jj][j-1]){
            if(dp[i-1][j-1]+1>dp[i-1][j]&&dp[i-1][j-1]+1>dp[i][j-1]){
               dp[i][j]=dp[i-1][j-1]+1;
               from[i][j]=3;
            }
         }
         else{
            if(dp[i-1][j]>dp[i][j-1]){
               dp[i][j]=dp[i-1][j];
               from[i][j]=2;
            }
            else if(dp[i-1][j]<dp[i][j-1]){
               dp[i][j]=dp[i][j-1];
               from[i][j]=1;
            }
            else{
               dp[i][j]=dp[i][j-1];
               from[i][j]=12;
            }
         }
      }
   }
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
         lcs(i,j);
         vector<int> ww;
         ww.clear();
         alcs.clear();
         go(i,j,n,n,ww);
         if(alcs.size()==0)continue;
         if(alcs[0].size()<=ans)continue;
         //cout<<i<<" "<<j<<":\n";
         //for(int l=0;l<alcs.size();l++){
         //   for(int ll=0;ll<alcs[l].size();ll++)
         //      cout<<alcs[l][ll]<<" ";
         //   cout<<"\n";
         //}
         for(int ll=0;ll<alcs.size();ll++){
            bool fl=1;
            for(int l=1;l<=k;l++){
               if(l==i||l==j)continue;
               fl=min(fl,chek(l,alcs[ll]));
            }
            if(fl==1){
               ans=max(ans,(int)alcs[ll].size());
            }
         }
      }

   }
   cout<<ans<<"\n";
}
