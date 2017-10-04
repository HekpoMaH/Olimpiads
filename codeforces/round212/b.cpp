#include<bits/stdc++.h>
using namespace std;
int m;
int n;
int a[3009];
int main(){
   cin>>n>>m;
   for(int i=1;i<=m;i++){
      cin>>a[i];
   }
   sort(a+1,a+m+1);
   if(a[1]==1||a[m]==n){
      cout<<"NO\n";
      return 0;
   }
   for(int i=3;i<=m;i++){
      if(a[i]==a[i-1]+1&&a[i-1]==a[i-2]+1){
         cout<<"NO\n";
         exit(0);
      }
   }
   cout<<"YES\n";
}
