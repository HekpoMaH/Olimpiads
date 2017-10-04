#include<bits/stdc++.h>
using namespace std;
const int nmax=4e5+9;
const int inf=1e9;
int n,q,a[nmax];
int dp[nmax];
int par[nmax];
void solve (int op)
{
   int i,l,r,mid,k,prev=-1;
   for(i=1;i<=n;i++){
      dp[i] = inf;
      par[i] = -1;
   }
   a[0]=-1;
   dp[0]=0;
   par[0]=-1;
   for(i=1;i<=n;i++){
      l=0;r=i;
      while(r-l>1){
          mid=(l+r)>>1;
          if(dp[mid]>n||a[dp[mid]]>=a[i])
             r=mid;
          else
             l=mid;
      }
      if(dp[l+1]>n||a[dp[l+1]]>a[i]){
          dp[l+1]=i;
          par[i]=dp[l];
      }
      for(int i=1;i<=n;i++){
         cout<<dp[i]<<" ";
      }
      cout<<"\n";
      for(int i=1;i<=n;i++){
         cout<<par[i]<<" ";
      }
      cout<<"\n";
   }
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   for(int i=1;i<=n;i++){
      cin>>a[i];
   }
   solve(1);
   for(int i=1;i<=n;i++){
      cout<<dp[i]<<" ";
   }
   cout<<"\n";
   for(int i=1;i<=n;i++){
      cout<<par[i]<<" ";
   }
   cout<<"\n";
}
