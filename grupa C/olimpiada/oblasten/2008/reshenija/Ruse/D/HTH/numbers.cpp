#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    long long a,b,p1,p2;
    cin>>a>>b>>p1>>p2;
    if(a==0 && p1==0 && p2==0 && b!=0){a=-1000;p1=a*a*b;p2=a*b*b;} 
    if(b==0 && p1==0 && p2==0 && a!=0){b=-1000;p1=a*a*b;p2=a*b*b;}
    if(a==0 && p1==0 && p2==0 && b==0){a=-1000;b=-1000;p1=a*a*b;p2=a*b*b;}
    if(a!=0 && p1==0 && p2==0 && b!=0){p1=a*a*b;p2=a*b*b;}
    if(a==0 && p1!=0 && p2!=0 && b!=0){a=p2/b/b;}
    if(a!=0 && p1!=0 && p2!=0 && b==0){b=p1/a/a;}
    if(a!=0 && p1==0 && p2!=0 && b!=0){p1=a*a*b;}
    if(a!=0 && p1!=0 && p2==0 && b!=0){p2=b*b*a;}
    if(a!=0 && b==0 && p1!=0 && p2==0){b=p1/a/a;p2=b*b*a;}
    if(a==0 && b!=0 && p1==0 && p2!=0){a=p2/b/b;p1=a*a*b;}
    if(a==0 && b!=0 && p1!=0 && p2==0){a=sqrt(p1/b);a=a-2*a;p2=b*b*a;}
    if(a!=0 && b==0 && p1==0 && p2!=0){b=sqrt(p2/a);b=b-2*b;p1=a*a*b;}
    if(a==0 && b==0 && p1!=0 && p2==0){for(a=-1000;a<=p1;a++)
                                       if(p1%(a*a)==0) {b=p1/a/a; break;}
                                       p2=b*b*a;
                                       }
    if(a==0 && b==0 && p1==0 && p2!=0){ for(b=p2;b>=-1000;b--)
                                        if(p2%(b*b)==0){a=p2/b/b;b=b-2*b; break;}
                                        p1=a*a*b;
                                        }
    if(a==0 && b==0 && p1!=0 && p2!=0){for(a=-1000;a<=p1;a++)
                                       if(p1%(a*a)==0) {b=p1/a/a;break;}
                                       }
    cout<<a<<' '<<b<<' '<<p1<<' '<<p2<<endl;
    return 0;
} 
