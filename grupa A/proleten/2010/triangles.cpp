#include<bits/stdc++.h>
using namespace std;
const int nmax=59;
int n,tab[nmax][nmax],ans;
int ots(int a,int b){
   for(int i=1;i<=n;i++){
      if(tab[i][a]==1&&tab[i][b]==1)return i;
   }
   return -1;
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   int k=0;
   for(int i=1;i<=n;i++){
      int m,p;
      cin>>m;
      for(int j=1;j<=m;j++){
         cin>>p;
         k=max(k,p);
         tab[i][p]=1;
      }
   }
   for(int i=1;i<=k;i++){
      for(int j=i+1;j<=k;j++){
         for(int kk=j+1;kk<=k;kk++){
            int a1=ots(i,j);
            int c1=ots(i,kk);
            int b1=ots(j,kk);
            if(a1!=-1&&b1!=-1&&c1!=-1&&a1!=b1&&a1!=c1&&b1!=c1){
               ans++;
            }
         }
      }
   }
   cout<<ans<<"\n";
}
