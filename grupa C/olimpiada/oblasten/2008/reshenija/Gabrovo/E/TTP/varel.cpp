#include <iostream>
using namespace std;
int main ()
{
int a,b,c,e,f,g,t;
char d;
cin>>a>>b>>c;
e=0;
for(g=1;g<=1;g++)
{cin>>d;
if(d=='+')e=a+b;
if(d=='-')e=a-b;
c=c-1;}
while(c>=1)
{cin>>d;
if(d=='+')e=e+b;
if(d=='-')e=e-b;
c=c-1;}
cout<<e<<endl;
}
