#include<bits/stdc++.h>
using namespace std;
const double inf=1e9;
const int nmax=509;
int n,p;
double dp[nmax][nmax];
double a[nmax];
double f[nmax][nmax];
void read(){
   cin>>n>>p;
   for(int i=1;i<=n;i++){
      cin>>a[i];
   }
}
void precompute(){
   double s1,s2;
   for(int i=1;i<=n;i++){
      s1=s2=0.0;
      for(int j=i;j<=n;j++){
         s1+=a[j];
         s2+=a[j]*a[j];
         //cout<<s2<<" "<<s1*s1/(j-i+1)<<"\n";
         cout.flush();
         f[i][j]=s2-s1*s1/(j-i+1);
      }
   }
}
void solve(){
   for(int i=0;i<=n;i++){
      for(int j=0;j<=p;j++){
         dp[i][j]=inf;
      }
   }
   dp[0][0]=0.0;
   for(int i=1;i<=n;i++){
      for(int j=1;j<=i;j++){
         for(int k=0;k<i;k++){
            dp[i][j]=min(dp[i][j],dp[k][j-1]+f[k+1][i]);
         }
      }
   }
   cout<<setiosflags(ios::fixed)<<setprecision(4)<<dp[n][p]<<"\n";
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   read();
   precompute();
   solve();
}
