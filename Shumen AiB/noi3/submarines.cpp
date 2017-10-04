#include<bits/stdc++.h>
using namespace std;
const int nmax=2009;
int n,m,k;
int ans=-1e9;
int a[nmax][nmax];
int mxup[nmax][nmax];
int mxdown[nmax][nmax];
int mxleft[nmax][nmax];
int mxright[nmax][nmax];
int mxrubka[nmax][nmax];
int alpha[44];
string c;
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>k;
   for(int i=1;i<=k;i++)cin>>alpha[i];
   cin>>n>>m;
   for(int i=1;i<=n;i++){
      cin>>c;
      for(int j=1;j<=m;j++){
         a[i][j]=alpha[c[j-1]-'a'+1];
      }
   }
   for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
         mxleft[i][j]=max(mxleft[i][j-1]+a[i][j-1],0);
      }
      for(int j=m;j>=1;j--){
         mxright[i][j]=max(mxright[i][j+1]+a[i][j+1],0);
      }
   }
   for(int i=1;i<=m;i++){
      for(int j=1;j<=n;j++){
         mxup[j][i]=max(mxup[j-1][i]+a[j-1][i],0);
      }
      for(int j=n;j>=1;j--){
         mxdown[j][i]=max(mxdown[j+1][i]+a[j+1][i],0);
      }
   }
   for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
         mxrubka[i][j]=max(mxrubka[i][j-1]+a[i][j-1],mxleft[i][j-1]+mxup[i][j-1]+a[i][j-1]);
      }
   }
   for(int i=1;i<=n;i++){
      for(int j=2;j<=m;j++){
         ans=max(ans,a[i][j]+mxup[i][j]+mxdown[i][j]+mxright[i][j]+mxrubka[i][j]);
      }
   }
   cout<<ans<<"\n";
}
