#include<bits/stdc++.h>
using namespace std;
const int nmax=809;
long long f[nmax][nmax];
int n,k;
int main(){
   cin>>n>>k;
   f[1][1]=1;
   for(int i=2;i<=n;i++){
      int mn=min(i,k);
      for(int j=1;j<=mn;j++){
         if(i==j||i==1){
            f[j][i]=1;
         }
         else{
            f[j][i]=f[j-1][i-1]+f[j][i-j];
         }
      }
   }
   cout<<f[k][n]<<"\n";
}
