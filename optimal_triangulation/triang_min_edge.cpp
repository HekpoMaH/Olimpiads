#include<bits/stdc++.h>
using namespace std;
const int nmax=109;
#define fi first
#define se second
int f[nmax][nmax];
int d[nmax][nmax];
pair<int,int> p[nmax];
int n;
int dist(int x,int y){
   return ((p[x].fi-p[y].fi)*(p[x].fi-p[y].fi)+(p[x].se-p[y].se)*(p[x].se-p[y].se));
}
int main(){
   cin>>n;
   for(int i=1;i<=n;i++){
      cin>>p[i].fi>>p[i].se;
   }
   for(int i=1;i<=n;i++){
      for(int j=i+2;j<=n;j++){
         d[i][j]=dist(i,j);
      }
   }
   for(int k=3;k<n;k++){
      for(int i=1;i<=n;i++){
         int j=i+k;
         if(j>n)continue;
         f[i][j]=1e9;
         for(int ff=i+1;ff<j;ff++){
            f[i][j]=min(max(d[i][ff],max(d[ff][j],max(f[i][ff],f[ff][j]))),f[i][j]);
         }
      }
   }
   cout<<f[1][n]<<"\n";
}
