#include<bits/stdc++.h>
using namespace std;
const int nmax=1501;
const int inf=1e9;
int n;
bool r[nmax];
int dp0[nmax],dp1[nmax];
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
         cin>>r[j];
         if(i==1&&j==1){
            dp1[j]=1;
            continue;
         }
         int c1=inf,c2=inf;
         if(j>1){
            c1=dp1[j-1]+1;
            if(dp1[j-1]%2&&!r[j])c1++;
            if(dp1[j-1]%2==0&&r[j])c1++;
         }
         if(i>1){
            c2=dp0[j]+1;
            if(dp0[j]%2&&!r[j])c2++;
            if(dp0[j]%2==0&&r[j])c2++;
         }
         dp1[j]=min(c1,c2);
      }
      for(int j=1;j<=n;j++){
         dp0[j]=dp1[j];
      }
   }
   cout<<dp0[n]<<"\n";
}
