#include<bits/stdc++.h>
using namespace std;
int phi(int x){
   int result=x;
   for(int i=2;i*i<=x;i++){
      if(x%i==0){
         while(x%i==0)x/=i;
         result-=result/i;
      }
   }
   if(x>1)result-=result/x;
   return result;
}
int gcd(int a,int b){
   return b==0 ? a : gcd(b,a%b);
}
int main(){
   long long k,br=1;
   cin>>k;
   k--;
   if(k==0){
      cout<<"0/1\n";
      return 0;
   }
   while(k>phi(br)){
      k-=phi(br);
      br++;
   }
   int br2=0;
   for(int i=1;i<=br;i++){
      if(gcd(i,br)==1)br2++;
      if(br2==k){
         cout<<i<<"/"<<br<<"\n";
         return 0;
      }
   }
}
