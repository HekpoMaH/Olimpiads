#include<bits/stdc++.h>
using namespace std;
int p,q,p2,q2;
int main(){
   cin>>p>>q;
   if(p%2==1&&q%2==1){
      cout<<0<<"\n";
      return 0;
   }
   p2=p;
   q2=q;
   int br=0;
   do{
      if(p2%2==0){
         p2/=2;
         q2=p2+q2;
      }
      else{
         q2/=2;
         p2=p2+q2;
      }
      br++;
   }while(!(p2==p&&q2==q)&&br<p+q);
   if(br==p+q){
      cout<<0<<"\n";
   }
   else cout<<br<<"\n";
}
