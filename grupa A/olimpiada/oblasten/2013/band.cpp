#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
const lli offset=1e6;
lli a,b,c,l,r;
lli max1;
int main(){
   cin>>a>>b>>c;
   a*=offset;
   b*=offset;
   c*=offset;
   l=0,r=c;
   while(l+1<r){
      lli x=(l+r)/2;
      if(x==0&&b>=c){
         max1=max(max1,b);
         l=x;
         break;
      }
      else if(x==c&&a>=c){
         max1=max(max1,b);
         r=x;
         break;
      }
      lli y=(lli)sqrt(c*c-x*x);
      lli d=(a-x)*c/y;
      lli p=(a-x)*x/y;
      if(p+y<b)l=x;
      else if(p+y>b)r=x;
      else if(p+y==b)break;
      if(l<=r&&p+y<=b)max1=max(max1,d);
   }
   if(b>=c)max1=max(max1,a);
   if(a>=c)max1=max(max1,b);
   cout<<setiosflags(ios::fixed)<<setprecision(2)<<(double)((double)max1/(double)offset)<<"\n";
}
