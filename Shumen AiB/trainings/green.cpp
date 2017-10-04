//informatics.mccme.ru - 112770
//moskovska otrikta olimpiada 2015
#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define pb push_back
const lli inf=1e18;
lli n,k;
vector<lli> divs;
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n>>k;
   for(lli i=1;i*i<=n;i++){
      if(n%i==0){
         divs.pb(i);
         divs.pb(n/i);
      }
   }
   sort(divs.begin(),divs.end());
   divs.resize(unique(divs.begin(),divs.end())-divs.begin());
   vector<vector<lli> >dp(2,vector<lli>(divs.size()));
   vector<vector<lli> >divdivs(divs.size());
   for(size_t i=0;i<divs.size();i++){
      for(int j=0;j<=i;j++){
         if(divs[i]%divs[j]==0){
            divdivs[i].pb(j);
         }
      }
      dp[0][i]=(divs[i]+1)/2;
   }
   int cur=0;
   for(int it=1;it<=k-1;it++){
      int ncur=1^cur;
      vector<lli> &dp1=dp[ncur];
      vector<lli> &dp2=dp[cur];
      for(int i=0;i<divs.size();i++){
         dp1[i]=inf;
         for(int j=0;j<divdivs[i].size();j++){
            assert(divs[divdivs[i][j]]!=0);
            dp1[i]=min(dp1[i],
                  dp2[divdivs[i][j]]*((divs[i]/divs[divdivs[i][j]])+1LL)/2LL);
         }
      }
      cur=ncur;
   }
   cout<<dp[cur][divs.size()-1]<<"\n";
}
