#include<bits/stdc++.h>
using namespace std;
const int nmax=559;
const int mod=1e9+21;
struct pole{
   int mnp;
   int br;
};
pole g[nmax][nmax];
int n,m;
void read(){
   cin>>n>>m;
   for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
         g[i][j].mnp=1e8;
         g[i][j].br=0;
      }
   }
   for(int i=1;i<=m;i++){
      int x,y,z;
      cin>>x>>y>>z;
      g[x][y].mnp=z;
      g[x][y].br=1;
      g[y][x].mnp=z;
      g[y][x].br=1;
   }
}
void precompute(){
   for(int k=1;k<=n;k++){
      for(int i=1;i<=n;i++){
         for(int j=1;j<=n;j++){
            if(i!=j&&i!=k&&j!=k){
               if(g[i][j].mnp>g[i][k].mnp+g[k][j].mnp){
                  g[i][j].mnp=g[i][k].mnp+g[k][j].mnp;
                  g[i][j].br=(long long)(g[i][k].br*g[k][j].br)%mod;
               }
               else if(g[i][j].mnp==g[i][k].mnp+g[k][j].mnp){
                  g[i][j].br=(long long)(g[i][j].br+g[i][k].br*g[k][j].br)%mod;
                  g[i][j].br%=mod;
               }
            }
         }
      }
   }
   //for(int i=1;i<=n;i++){
   //   for(int j=1;j<=n;j++){
   //      cout<<"("<<g[i][j].br<<","<<g[i][j].mnp<<") ";
   //   }
   //   cout<<"\n";
   //}
   //NEEEED TESTING!!!!!!!!!!!!
}
void solve(){
   int q;
   cin>>q;
   for(int i=1;i<=q;i++){
      int x,y;
      cin>>x>>y;
      if(x==y){
         if(i!=q)cout<<1<<" ";
         else cout<<1<<"\n";
         continue;
      }
      if(i!=q)cout<<g[x][y].br%mod<<" ";
      else cout<<g[x][y].br%mod<<"\n";
   }
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   read();
   precompute();
   solve();
}
