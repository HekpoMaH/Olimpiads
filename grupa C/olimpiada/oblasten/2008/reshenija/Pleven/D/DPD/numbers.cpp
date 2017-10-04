#include<iostream>
#include<math.h>
using namespace std;
unsigned long long a,b,c,d,e1,e2,e3,e4,i,j;
int main()
{
    cin>>a>>b>>c>>d;
    if(a!=0) {e1=1;}
    if(b!=0) {e2=1;}
    if(c!=0) {e3=1;}
    if(d!=0) {e4=1;}
    if(e3==1) {b=c/(a*a); e2=1; a=sqrt(c/b); e1=1;}
    if(e4==1) {b=sqrt(d/a); e2=1; a=d/(b*b); e1=1;}
    if(e1==1&&e2==1) {c=a*a*b; e3=1; d=b*b*a; e4=1;}
    if(e1==0&&e2==0) {if(c==1) {a=-1; b=c/(a*a);} else if(d==1) {a=-1; b=d/(a*a);}}
    cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl; 
    return 0;
}
