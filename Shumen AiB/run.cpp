#include<bits/stdc++.h>
using namespace std;
const nmax=19;
int b[nmax][nmax];
int n,k;
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n>>k;
   for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
         cin>>b[i][j];
         if(i==j)b[i][j]=1e6+1;
      }
   }
   for(int kk=1;kk<=n;kk++){
      for(int i=1;i<=n;i++){
         for(int j=1;j<=n;j++){
            b[i][j]=min(b[i][kk]+b[kk][j],b[i][j]);
         }
      }
   }
   for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
         cout<<b[i][j]<<" ";
      }
      cout<<"\n";
   }
}
