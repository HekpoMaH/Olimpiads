#include<bits/stdc++.h>
using namespace std;
long long a;
bool da(long long x){
   x=abs(x);
   while(x!=0){
      if(x%10==8)return true;
      x/=10;
   }
   return false;
}
int main(){
   cin>>a;
   for(long long i=1;i<=10000LL;i++){
      if(da(a+i)){
         cout<<i<<"\n";
         return 0;
      }
   }
}
