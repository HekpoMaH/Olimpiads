#include<bits/stdc++.h>
using namespace std;
const int nmax=109;
char a[nmax][nmax];
int psum[nmax][nmax];
int n,m,r,c;
int main(){
   cin>>n>>m>>r>>c;
   for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
         cin>>a[i][j];
      }
   }
   for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
         psum[i][j]=psum[i-1][j]+psum[i][j-1]-psum[i-1][j-1]+ (a[i][j]=='#');
      }
   }
   int br=0;
   for(int i=r;i<=n;i++){
      for(int j=c;j<=m;j++){
         if(psum[i][j]-psum[i-r][j]-psum[i][j-c]+psum[i-r][j-c]==0)br++;
      }
   }
   cout<<br<<"\n";
}
