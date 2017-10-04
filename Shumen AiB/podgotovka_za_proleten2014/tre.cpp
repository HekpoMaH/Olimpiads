#include<bits/stdc++.h>
using namespace std;
const int maxl=1009,maxd=109,maxk=10009,maxn=1009;
int n,k,l,d;
long long tab[maxd][maxl];
long long dp[maxn][maxk];
long long price[maxn],cost[maxn],prev[maxn];
int sz;
void read(){
   cin>>n>>k>>l>>d;
   for(int i=1;i<=d;i++){
      for(int j=1;j<=l;j++){
         cin>>tab[i][j];
      }
   }
   for(int j=1;j<=l;j++){
      int last=sz;
      long long sum=0;
      for(int i=1;i<=d;i++){
         sum+=tab[i][j];
         if(tab[i][j]>0){
            price[++sz]=sum;
            cost[sz]=i;
            prev[sz]=last;
         }
      }
   }
}
void solve(){
   for(int i=1;i<=n;i++){
      for(int j=1;j<=k;j++){
         if(j<cost[i])continue;
            dp[i][j]=max(dp[i-1][j],dp[prev[i]][j-cost[i]]+price[i]);
      }
   }
   long long mx=0;
   for(int i=1;i<=k;i++)mx=max(mx,dp[n][i]);
   cout<<mx<<"\n";
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   read();
   solve();
}
