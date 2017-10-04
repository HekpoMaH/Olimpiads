//conquest-dp
//O(n*a_max*a_max)
//greedy works faster with complexity O(nlogn)
#include<bits/stdc++.h>
using namespace std;
const int nmax=1009;
int inf=1e9;
pair<int,int> c[nmax];
int n;
int sum[nmax];
//dp[i][j]-> min broi moneti za da zavzeme6 parvite i grada i za da vzeme6 j voinika ot gradovete s idx > i
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   int total=0;
   for(int i=1;i<=n;i++){
      cin>>c[i].first>>c[i].second;
      total+=c[i].first;
   }
   int dp[n+4][total+4];
   memset(dp,31,sizeof(dp));
   inf=dp[0][0];
   for(int j=0;j<=total;j++)
      dp[1][j]=0;
   sort(c+1,c+n+1);
   for(int i=1;i<=n;i++){
      sum[i]=sum[i-1]+c[i].first;
   }
   for(int i=1;i<=n;i++){
      for(int j=0;j<=total;j++){
         if(dp[i][j]!=inf){
            //cout<<c[i].first<<" "<<j<<"\n";
            for(int t=0;t<=c[i].first&&t<=j;t++){
               /*
                * v slednata situaciq sme:
                * zavseli sme vsi4ko do i-1 grad (t.e. voinicite sa sumata ot 1 do i-1 na a -> sum[i-1])
                * ot i-tiq grad 6te vzemem t na broi voinika
                * a ot ostanalite s idx > i sme ve4e vzeli j na broi
                * voiskata ni e sum[i-1]+j+t
                * ako imame nadmo6tie nad grada (t.e. voiskata>c[i].first <=> sum[i-1]+j>c[i].first-t)
                * => dp[i+1][j-t]=min(dp[i+1][j-t],dp[i][j]+cost)
                * NB! da ne se izpolzva min 4e dava TL na 2 testa
                */
               int cost=t*c[i].second;
               int zahvanati=sum[i-1]+j;
               //cout<<cost<<" "<<zahvanati<<" "<<c[i].first-t<<"\n";
               if(zahvanati>c[i].first-t&&dp[i][j]+cost<dp[i+1][j-t])
                  dp[i+1][j-t]=dp[i][j]+cost;
            }
         }
      }
   }
   cout<<dp[n+1][0]<<"\n";
}
