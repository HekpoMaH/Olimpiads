#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
lli n,p;
lli pw[20];
int main(){
   cin>>n>>p;
   pw[0]=1;
   for(int i=1;i<=19;i++)pw[i]=pw[i-1]*10;
   int br=0;
   if(n==1){
      for(int i=0;i<=9;i++){
         if(i%p==0)br++;
      }
      cout<<br<<"\n";
      exit(0);
   }
   lli koef=pw[(n+1)/2];
   lli stop=pw[n/2];
   lli incr=stop/10;
   for(int i=1,front=incr;i<stop;i++){
      if(i%10==0){
         for(int gh=incr;gh>0;gh/=10){
            if(front/gh!=9){
               front+=gh;
               break;
            }
            front-=9*gh;
         }
         continue;
      }
      lli tek=front*koef+i;
      if(tek%p==0)br++;
      if(n%2==1){
         for(int j=1;j<=9;j++){
            if((tek+j*stop)%p==0)br++;
         }
      }
      for(int gh=incr;gh>0;gh/=10){
         if(front/gh!=9){
            front+=gh;
            break;
         }
         front-=9*gh;
      }
      cerr<<front<<"\n";
   }
   cout<<br<<"\n";
}
