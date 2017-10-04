#include<bits/stdc++.h>
using namespace std;
int n,m;
int br[1009];
int a[1009],b[1009];
int kup[1009];
long long ovs;
void simul(){
   for(int i=1;i<=m;i++){
      int dapos=1;
      int sum=0;
      for(int j=1;j<=n;j++){
         if(kup[j]==b[i]){
            dapos=j;
            break;
         }
         sum+=kup[j];
      }
      int kup2[1009],br=2;
      kup2[1]=b[i];
      for(int j=1;j<=n;j++){
         if(j!=dapos)kup2[br]=kup[j],br++;
      }
      ovs+=sum;
      for(int j=1;j<=n;j++){
         kup[j]=kup2[j];
         assert(kup[j]!=kup[j-1]);
      }
   }
}
int main(){
   cin>>n>>m;
   for(int i=1;i<=n;i++){
      cin>>a[i];
   }
   int sz=0;
   for(int i=1;i<=m;i++){
      cin>>b[i];
      if(br[b[i]]==0){
         kup[++sz]=b[i];
      }
      br[b[i]]++;
   }
   simul();
   cout<<ovs<<"\n";
}
