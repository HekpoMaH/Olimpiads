#include<bits/stdc++.h>
using namespace std;
const int nmax=1e3+9;
int n,m,k;
int a[nmax];
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n>>m>>k;
   int br=0;
   for(int i=1;i<=m+1;i++){
      cin>>a[i];
   }
   for(int i=1;i<=m;i++){
      int diff=0;
      for(int j=0;j<n;j++){
         if(!(( (a[i]&(1<<j)) && (a[m+1]&(1<<j)) ) ||( !(a[i]&(1<<j)) && !(a[m+1]&(1<<j)) )))diff++;
      }
      if(diff<=k)br++;
   }
   cout<<br<<endl;

}
