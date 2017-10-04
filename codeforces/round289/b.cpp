#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[109];
int used[109][109];
vector<int> pile[109];
int main(){
   cin>>n>>k;
   int sum=0,ss=0;
   for(int i=1;i<=n;i++){
      cin>>a[i];
      ss+=a[i];
   }
   int ccol=1;
   while(sum<ss){
      sum=0;
      for(int i=1;i<=n;i++){
         if(pile[i].size()<a[i]){
            pile[i].push_back(ccol);
            used[i][ccol]++;
         }
         sum+=pile[i].size();
      }
      ccol++;
      if(ccol>k)ccol-=k;
   }
   for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
         for(int kk=1;kk<=k;kk++){
            if(abs(used[i][kk]-used[j][kk])>1){
               cout<<"NO\n";
               exit(0);
            }
         }
      }
   }
   cout<<"YES\n";
   for(int i=1;i<=n;i++){
      for(int j=0;j<pile[i].size();j++){
         cout<<pile[i][j]<<" ";
      }
      cout<<"\n";
   }
}
