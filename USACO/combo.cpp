/*
ID: dobrikg1
PROG: combo
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int n;
int m[4];
int f[4];
int c[4];
bool t1(){
   for(int i=1;i<=3;i++){
      int fl=0;
      for(int k1=0;k1<=2;k1++){
         for(int k2=0;k2<=2;k2++){
            int x1=m[i]+k1*n;
            int x2=c[i]+k2*n;
            if(abs(x1-x2)<=2)fl=1;
         }
      }
      if(fl==0)return false;
   }
   return true;
}
bool t2(){
   for(int i=1;i<=3;i++){
      int fl=0;
      for(int k1=0;k1<=2;k1++){
         for(int k2=0;k2<=2;k2++){
            int x1=f[i]+k1*n;
            int x2=c[i]+k2*n;
            if(abs(x1-x2)<=2)fl=1;
         }
      }
      if(fl==0)return false;
   }
   return true;
}
int main(){
   freopen("combo.in","r",stdin);
   freopen("combo.out","w",stdout);
   cin>>n;
   for(int i=1;i<=3;i++)cin>>m[i];
   for(int i=1;i<=3;i++)cin>>f[i];
   c[1]=50;c[2]=50;c[3]=1;
   //cout<<t1()<<"\n";
   //exit(0);
   int br=0;
   for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
         for(int k=1;k<=n;k++){
            c[1]=i;c[2]=j;c[3]=k;
            if(t1()||t2()){
               //cout<<i<<" "<<j<<" "<<k<<"\n";
               br++;
            }
         }
      }
   }
   cout<<br<<"\n";
}
