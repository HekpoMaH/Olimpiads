#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
int k;
lli n;

lli ans=0;
lli gcd(lli a,lli b){
   return b==0 ? a : gcd(b,a%b);
}
lli a[99];
lli c[99][99];
void makecomb(){
   for(int i=1;i<=40;i++){
      for(int j=0;j<=i;j++){
         if(j==0||j==i){
            c[i][j]=1;
         }
         else c[i][j]=c[i-1][j-1]+c[i-1][j];
      }
   }
}
void cnt(int mask){
   lli br=0,pr=1,nod=-1;
   for(int i=1;i<=k;i++){
      if((mask&(1<<(i-1)))){
         br++;
         pr*=a[i];
         if(nod==-1)nod=a[i];
         else nod=gcd(a[i],nod);
      }
   }
   if(br%2==1){
      lli nok=pr/nod;
      if(br==1)nok=pr;
      ans+=c[k][br]*(n/(nok));
   }
   else ans-=c[k][br]*(n/(pr/nod));
}
int main(){
   cin>>n>>k;
   for(int i=1;i<=k;i++)cin>>a[i];
   makecomb();
   for(lli mask=1;mask<(1<<k);mask++){
      cnt(mask);
   }
   cout<<ans<<"\n";
}
