#include<bits/stdc++.h>
using namespace std;
int n,m,t[109];
int main(){
   cin>>n>>m;
   int mx=0;
   for(int i=0;i<m;i++){
      cin>>t[i];
      mx=max(mx,t[i]);
   }
   cout<<n*mx<<"\n";
   for(int i=0;i<n;i++){
      cout<<"\n";
      int a[10009];
      memset(a,0,sizeof(a));
      for(int j=0;j<m;j++){
         a[((i+j)%n)*mx]=j+1;
      }
      for(int j=0;j<=10000;j++){
         if(a[j]!=0){
            cout<<a[j]<<" "<<j<<"\n";
         }
      }
   }
}
