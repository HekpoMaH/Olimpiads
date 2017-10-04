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
int main(){
   int n;
   cin>>n;
   cout<<phi(n)<<"\n";
}
