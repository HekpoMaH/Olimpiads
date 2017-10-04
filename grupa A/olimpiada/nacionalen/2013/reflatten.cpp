#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+9;
typedef long long lli;
lli ps[nmax];
lli data[nmax];
int n,k;
lli dp[nmax];
int pos[nmax],posize,cpos;
lli geti(int a,int b){
   return ps[b]-ps[(a+b)/2-1+((a+b)&1)]-(ps[(a+b)/2]-ps[a-1]);
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n>>k;
   for(int i=1;i<=n;i++){
      cin>>data[i];
      ps[i]=ps[i-1]+data[i];
   }
   dp[1]=0;
   posize=1;
   for(int i=2;i<=n;i++){
      dp[i]=geti(1,i);
      for(int j=1;j<i;j++){
         if(dp[i]>geti(j+1,i)+dp[j]+k)
            dp[i]=dp[j]+k+geti(j+1,i);
      }
   }
   cout<<dp[n]<<"\n";
}
