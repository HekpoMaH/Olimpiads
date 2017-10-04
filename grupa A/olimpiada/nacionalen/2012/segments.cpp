#include<iostream>
#include<cmath>
using namespace std;
typedef long long lli;
lli n,a,b,c;
lli m;
/*
 |ax+by+cz=n
 |x+y+z=m
 |x>=0,y>=0,z>=0

 x=m-y-z;
 a*(m-y-z)+by+cz=n
 am-ay-az+by+cz=n
 y(b-a)+(c-a)Z=N-AM
             ^^^^^^
             Iluminati confirmed
 b1=b-a
 c1=c-a;
 n1=n-a*m
 yb1+zc1=n1
 diofant za gornoto
 neka yo,z0 random re6enie
 |x=m-y-z;
 |y=yo-c2*t
 |z=z0+c2*t
 |x>=0,y>=0,z>=0

 |ans>=(yo+z0-m)/(c2-b2)
 |ans<=yo/c2
 |ans>=-z0/b2
 */
lli c1,b1,n1,b2,c2;
lli yo,z0;
lli gcd(lli a,lli b,lli &x,lli &y){
   if(a==0){
      x=0;
      y=1;
      return b;
   }
   lli x1,y1;
   lli d=gcd(b%a,a,x1,y1);
   x=y1-(b/a)*x1;
   y=x1;
   return d;
}
int main(){
   cin>>a>>b>>c>>m>>n;
   b1=b-a;
   c1=c-a;
   n1=n-a*m;
   lli nod=gcd(b1,c1,yo,z0);
   if(n1%nod!=0){
      cout<<0<<"\n";
      return 0;
   }
   b1/=nod;
   c1/=nod;
   n1/=nod;
   //cout<<b1<<"*y+"<<c1<<"*z="<<n1<<"\n";
   nod=gcd(b1,c1,yo,z0);
   //cout<<"yo="<<yo<<" z0="<<z0<<"\n";
   yo*=n1,z0*=n1;
   //cout<<"yo="<<yo<<" z0="<<z0<<"\n";
   lli mx,mn;
   mx=floor((double)yo/c1);
   //cout<<yo/c1<<"\n";
   cout<<(double)(yo+z0-m)/(c1-b1)<<" "<<(double)(-1*z0/b1)<<"\n";
   mn=max((lli)(ceil((double)(yo+z0-m)/(c1-b1))),(lli)(ceil((-1*z0/b1))));
   //cout<<mn<<"\n";
   //cout<<mx<<"\n";
   cout<<max(0LL,mx-mn+1)<<"\n";
   return 0;
}
