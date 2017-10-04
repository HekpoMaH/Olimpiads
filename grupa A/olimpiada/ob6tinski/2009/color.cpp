#include<bits/stdc++.h>
using namespace std;
const int nmax=5e5+9;
int xr[nmax];
int n,en,mx,len;
int main(){
   cin>>n;
   for(int i=1;i<=n;i++){
      int a,b;
      cin>>a>>b;
      en=max(en,b);
      xr[a]^=1;xr[b+1]^=1;
   }
   int cr=0;
   for(int i=1;i<=en;i++){
      cr^=xr[i];
      if(cr==0){
         mx=max(mx,len);len=0;
      }
      if(cr==1){
         len++;
      }
   }
   mx=max(mx,len);
   cout<<mx<<"\n";
}
