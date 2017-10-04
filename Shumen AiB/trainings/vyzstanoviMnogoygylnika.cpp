#include<bits/stdc++.h>
using namespace std;
const int nmax=1e3+9;
int a[nmax][nmax];
int n,m;
int h[nmax][nmax],v[nmax][nmax];
string ans[nmax];
void read(){
   cin>>n>>m;
   for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
         cin>>a[i][j];
      }
   }
}
void solve(){
   for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
         if(a[i][j]==1){
            h[i][j]=1;
            a[i+1][j]--;
         }
      }
      for(int j=1;j<=m;j++){
         if(h[i][j]+h[i][j-1]+v[i][j]==1){
            v[i+1][j]=1;
            a[i+1][j-1]--;a[i+1][j]--;
            // ._.
            //.| |
         }
      }
   }
   for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
         if(v[i][j]==1)ans[i]+='|';
         else ans[i]+='.';
         if(h[i][j]==1)ans[i]+='_';//I feel dumb -_-
         else ans[i]+='.';
      }
   }
   for(int i=1;i<=n;i++){
      for(size_t j=1;j<ans[i].size();j++){
         cout<<ans[i][j];
      }
      cout<<"\n";
   }
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   read();
   solve();
}
