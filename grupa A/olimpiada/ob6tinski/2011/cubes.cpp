#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
lli n;
void solve(){
   cin>>n;
   lli p;
   lli q;
   for(lli i=1;i*i<=n;i++){
      if(n%i==0){
         p=i;
         q=n/i;
         if(q<p)swap(q,p);
         if(q-p*p<=0)continue;
         lli d=12*q-3*p*p;
         lli kd=(lli)sqrt(d);
         if(kd*kd==d){
            lli b=(-3*p+kd)/6;
            lli a=p+b;
            if(a>0&&b>0&&a*a*a-b*b*b==n){
               cout<<a<<" "<<b<<"\n";
               return;
            }
         }
      }
   }
   cout<<"NO\n";
}
int main(){
   for(int i=1;i<=2;i++)solve();
}
