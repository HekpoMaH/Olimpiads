#include<bits/stdc++.h>
using namespace std;
int a[309][309];
int p[309];
int n;
int main(){
   cin>>n;
   for(int i=1;i<=n;i++){
      cin>>p[i];
   }
   string s;
   for(int i=1;i<=n;i++){
      cin>>s;
      for(int j=1;j<=n;j++){
         a[i][j]=s[j-1]-'0';
      }
   }
   int cikl=n;
   if(n<=40)cikl*=10;
   for(int k=1;k<=cikl;k++){
      for(int i=1;i<=n;i++){
      for(int j=i+1;j<=n;j++){
         if(p[i]>p[j]&&a[i][j]==1){
            swap(p[i],p[j]);
         }
      }
   }
   }
   for(int i=1;i<=n;i++){
      cout<<p[i]<<" ";
   }
   cout<<"\n";
}
