#include <iostream>
using namespace std;
int main ()
{
int a,b,c,o,oo,ooo,e,f,oooo,g,oooooo,t,l,k,p;
bool n;
cin>>a;
b=0;
c=a-1;
for(g=2;g<=a;g++)
{
if(a%g==0)n=1;
else n=0;
if(n==1)b=a/g;
if(b>g&&n==1)e=b-g;
if(g>=b&&n==1)e=g-b;
if(e<c&&n==1||e==c&&n==1){f=g;t=b;c=e;}}
cout<<f<<" "<<t<<endl;
}
