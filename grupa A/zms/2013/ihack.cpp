#include<bits/stdc++.h>
using namespace std;
const int nmax=2009;
const int mod=1e4*3+11;
int n,k;
int a[nmax];
void read(){
   cin>>n;
   for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
         char x;
         cin>>x;
         a[j]+=x-'0';
      }
   }
   cin>>k;
   //for(int i=1;i<=n;i++)cout<<a[i]<<" ";
   //cout<<"\n";
}
int cnt(int start){
   int dir=start;
   int f[nmax];
   int sum=0;;
   for(int i=1;i<=n;i++){
      f[i]=a[i];
   }
   for(int i=1;i<=k;i++){
      sum=0;
      int j;
      if(dir==1){
         j=1;
      }
      else j=n;
      int nf;
      while(j>=1&&j<=n){
         nf=sum*a[j]%mod;
         sum=(sum+f[j])%mod;
         f[j]=nf;
         j+=dir;
      }
      dir=-dir;
   }
   return sum;
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   read();
   int ans=cnt(-1)+cnt(1);
   if(k==1)ans/=2;
   cout<<ans%mod<<"\n";
}
