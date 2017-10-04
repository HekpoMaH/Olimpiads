#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+9;
const int mod=1e9+7;
int a[nmax];
int f[nmax][5];
int n,k;
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n>>k;
   for(int i=1;i<=k;i++){
      int x,y;
      cin>>x>>y;
      a[x-1]|=(1<<(y-1));
   }
   f[0][0]=1;
   for(int i=0;i<=n;i++){
      f[i][3]=(f[i][3]+f[i][0])%mod;
      for(int j=0;j<4;j++){
         if(j&a[i]){
            continue;
         }
         for(int k=0;k<4;k++){
            if(((3-j-a[i])&k)==k){
               f[i+1][k]=(f[i+1][k]+f[i][j])%mod;
            }
         }
      }
   }
   cout<<f[n][0]<<"\n";
}
