#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
lli n,k;
lli a,b=1;
lli nod(lli x,lli y){
   return y ? nod(y,x%y) : x;
}
void sab(lli x,lli y){
   a=a*y+b*x;
   b*=y;
}
int main(){
   cin>>n>>k;
   for(lli i=n;i<=k;i++){
      for(lli j=i+1;j<=k;j++){
         if(nod(i,j)==1){
            sab(i,j);
            lli nd=nod(a,b);
            a/=nd;b/=nd;
         }
      }
   }
   cout<<a<<"/"<<b<<"\n";
}
