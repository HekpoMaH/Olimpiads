#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    long a,b,c,d,i;
    cin>>a>>b>>c>>d;
    if (a==0 && b!=0 && c!=0 && d!=0) {a=(d/b)/b;cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;}
    if (b==0 && a!=0 && c!=0 && d!=0) {b=(c/a)/a;cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;}
    if (c==0 && a!=0 && b!=0 && c!=0) {c=a*a*b;cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;}
    if (d==0 && a!=0 && b!=0 && c!=0) {d=a*b*b;cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;}
    if (a==0 && c==0 && b!=0 && d!=0) {a=(d/b)/b;c=a*a*b;cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;}
    if (b==0 && d==0 && c!=0 && a!=0) {b=(c/a)/a;d=a*b*b;cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;}
    if (b==0 && c==0 && a!=0 && d!=0) {b=sqrt(d/a);c=a*a*b;cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;}
    if (a==0 && d==0 && b!=0 && c!=0) {a=sqrt(c/b);d=a*b*b;cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;}
    if (c==0 && d==0 && b!=0 && a!=0) {c=a*a*b;d=a*b*b;cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;}
    if (a==0 && b==0 && c!=0 && d!=0) 
    {
             for(i=-1000;i<=1000;i++)
             {
                                     if (i!=0) {a=i;}
                                     b=sqrt(d/a);
                                     if (c==a*a*b && ceil(b)==floor(b) && b!=0 && c!=0) {break;}
             }
             cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    }
    if (a==0 && b==0 && c==0 && d!=0)
    {
             if (d>0)
             {
                     for(i=1;i<=1000;i++)
                     {
                                     a=i;
                                     b=sqrt(d/a);
                                     c=a*a*b;
                                     if (b*b*a==d && ceil(b)==floor(b) && b!=0 && c!=0) {b=b-b*2;c=a*a*b;break;}
                     }
             }
             cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    }
    if (a!=0 && b==0 && c==0 && d==0)
    {
             b=-1000;
             c=a*a*b;
             d=b*b*a;
             cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    }
    if (b!=0 && a==0 && c==0 && d==0)
    {
             a=-1000;
             c=a*a*b;
             d=b*b*a;
             cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    }
//    system("pause");
    return 0;
}
    
