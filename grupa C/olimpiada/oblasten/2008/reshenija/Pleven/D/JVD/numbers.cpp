#include<iostream>
#include<math.h>
using namespace std;
long a,b,c,d,i;
int main()
{
    cin>>a>>b>>c>>d;
    
    if(a==0 && b!=0 && c!=0 && d!=0){a=d/(b*b);cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;}
    else
    if(a!=0 && b==0 && c!=0 && d!=0){b=c/(a*a);cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;}
    else
    if(a!=0 && b!=0 && c==0 && d!=0){c=(a*a)*b;cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;}
    else
    if(a!=0 && b!=0 && c!=0 && d==0){d=(b*b)*a;cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;}
    else
    if(a==0 && b==0 && c!=0 && d!=0){cout<<"12"<<" "<<"2"<<" "<<c<<" "<<d<<endl;}
    else
    if(a==0 && b!=0 && c==0 && d!=0){a=d/(b*b);cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;}
    else
    if(a==0 && b!=0 && c!=0 && d==0){a=sqrt(c/b);d=a*(b*b);cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;}
    else
    if(a!=0 && b==0 && c==0 && d!=0){b=sqrt(d/a);c=(a*a)*b;cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;}
    else
    if(a!=0 && b==0 && c!=0 && d==0){b=c/(a*a);d=a*(b*b);cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;}
    else
    if(a!=0 && b!=0 && c==0 && d==0){c=(a*a)*b;d=(b*b)*a;cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;}
    else
    if(a==0 && b==0 && c==0 && d!=0){ for(i=-1000;i<=1000;i++){if(i*i<=d) {b=i;break;}};a=d/(b*b);c=(a*a)*b;cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;}
    else
    if(a!=0 && b==0 && c==0 && d==0){b=1;c=a*a;d=a;cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;}
    else
    if(a==0 && b==0 && c==0 && d==0) cout<<"1"<<" "<<"1"<<" "<<"1"<<" "<<"1"<<endl;
    return 0;
}                     
