#include<bits/stdc++.h>
using namespace std;
long long x;
long long m;
int main(){
   cin>>m;
   unsigned long long t=4500;
   for(int i=1;i<=99;i++)t=t*10LL,t%=m;
   t=m-t;
   cout<<t<<" ";
   t--;

   int cifri=0;
   long long t1=t;
   while(t1!=0){
      t1/=10;
      cifri++;
   }
   if(t==0)cifri++;
   cout<<1;
   for(int i=1;i<=100-cifri;i++)cout<<0;
   cout<<t;
   cout<<endl;
}
