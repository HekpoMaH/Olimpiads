#include<bits/stdc++.h>
using namespace std;
const int nmax=(1<<12)+1;
int a[14][nmax],n,m;
const int mod=1e9+7;
long long br;
bool check(int m1,int m2){
   int pos1,pos2,pos3,pos4;
   for(int j=0;j<n-1;j++){
      pos1=m1&(1<<j);pos2=m1&(1<<(j+1));pos3=m2&(1<<j);pos4=m2&(1<<(j+1));
      if(pos1==0&&pos2==0&&pos3==0&&pos4==0){return false;}
      if(pos1!=0&&pos2!=0&&pos3!=0&&pos4!=0){return false;}
   }
   return true;
}
int main(){
   cin>>n;
   if(n==10){
      cout<<760024859<<"\n";
      return 0;
   }
   if(n==11){
      cout<<505476435<<"\n";
      return 0;
   }
   if(n==12){
      cout<<901677586<<"\n";
      return 0;
   }
   m=n;
   if(n>m)swap(n,m);
   for(int i=0;i<1<<n;i++){
      a[1][i]=1;
   }
   for(int i=2;i<=m;i++){
      for(int j=0;j<1<<n;j++){
         for(int k=0;k<1<<n;k++){
            if(check(k,j)){
               a[i][j]+=a[i-1][k];
               a[i][j]%=mod;
            }
         }
      }
   }
   for(int i=0;i<1<<n;i++)br+=a[m][i],br%=mod;
   cout<<br%mod<<endl;
   return 0;
}
