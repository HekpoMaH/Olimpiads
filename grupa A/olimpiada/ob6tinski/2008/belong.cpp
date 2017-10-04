#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
lli n;
lli f(lli e){
   lli d[99],br=0;
   do{
      d[br++]=e%2;
      e/=2;
   }while(e!=0);
   if(!(br&1))return 0;
   for(br--;br>=0;br-=2){
      if(d[br]==0){
         return 0;
      }
   }
   return 1;
}
int main(){
   for(lli i=1;i<=3;i++){
      cin>>n;
      cout<<f(n);
   }
   cout<<"\n";
}
