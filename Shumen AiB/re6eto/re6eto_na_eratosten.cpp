#include<bits/stdc++.h>
using namespace std;
const int maxn=1009;
int lp[maxn];
vector<int> pr;
const int n=500;
int main(){
   for(int i=2;i<=n;i++){
      if(lp[i]==0){
         pr.push_back(i);
         lp[i]=i;
      }
      for(int j=0;j<pr.size()&&pr[j]*i<=n&&pr[j]<=lp[i];j++){
         lp[pr[j]*i]=pr[j];//lp[i]>=pr[j]
      }
   }
   //if lp[i]==i => i is prime
   for(int i=2;i<=n/10;i++){
      int i2=i;
      cout<<i<<"(";
      while(i2!=1){
         if(lp[i2]!=i2)cout<<lp[i2]<<",";
         else cout<<lp[i2];
         i2/=lp[i2];
      }
      cout<<")\n";
   }
   cout<<"\n";
}
