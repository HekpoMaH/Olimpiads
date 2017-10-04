/*
ID: dobrikg1
PROG: skidesign
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
const int nmax=1009;
int a[nmax];
int n;
int main(){
   freopen("skidesign.in", "r", stdin);
   freopen("skidesign.out", "w", stdout);
   cin>>n;
   for(int i=1;i<=n;i++){
      cin>>a[i];
   }
   int mn=999999;
   for(int i=0;i<=100;i++){
      int curans=0;
      for(int j=1;j<=n;j++){
         if(a[j]<i){
            curans+=(i-a[j])*(i-a[j]);
         }
         if(i+17<a[j]){
            curans+=(a[j]-i-17)*(a[j]-i-17);
         }
      }
      mn=min(mn,curans);
      //cout<<i<<" "<<mn<<"\n";
   }
   cout<<mn<<"\n";
}
