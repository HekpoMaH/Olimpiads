//finding reverse elemed module m.
//using phi func.
#include<bits/stdc++.h>
using namespace std;
int a,m;
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
int fastpow(int x,int st){
   int p=x,res=1;
   while(st!=0){
      if(st&1)
         res*=p,res%=m;
      st>>=1;
      p*=p;
      p%=m;
   }
   return res;
}
int gcd(int a,int b){
   return a>0 ? gcd(b%a,a) : b;
}
int main(){
   cin>>a>>m;
   if(gcd(a,m)!=1){
      cout<<"NO ELEMENT\n";
      return 0;
   }
   int fi=phi(m);
   int rev=fastpow(a,fi-1);
   cout<<fastpow(a,fi-1)<<"\n";
}
