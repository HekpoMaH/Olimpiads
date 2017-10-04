#include<iostream>
#include<cmath>
using namespace std;

int main ()
{
long int a,b,k,p,s;
int g,l;
cin>>a>>b;
while(a<=0 || b<=0|| b<=a )
{cin>>a>>b;}
cin>>k>>p;
while(k<=0 || p<=0 || p>=50)
{cin>>k>>p;}
double c,d,e,h,i,j,f;
c=a;
d=b;
e=c/d;
g=k+p;
l=pow(10,g);
f=e*l;
cout<<f;
return 0 ; }
