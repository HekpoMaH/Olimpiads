#include <iostream>
using namespace std;
int main() {
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a!=0&&b!=0) {c=a*a*b; d=a*b*b;
                   cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
                   return 0;
                   }
    if(a!=0&&c!=0) {b=c/(a*a); d=a*b*b;
                   cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
                   return 0;
                   }
    if(b!=0&&d!=0) {a=d/(b*b); c=a*a*b;
                   cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
                   return 0;
                   }
    if(a!=0&&d!=0) {b=(d/a)^(1/2); c=a*a*b;
                   cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
                   return 0;
                   }
    if(b!=0&&c!=0) {a=(c/b)^(1/2); d=a*b*b;
                   cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
                   return 0;
                   }
    if(c!=0&&d!=0) {a=(c*(c/d))^(1/3); b=(d*(d/c))^(1/3);
                   cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
                   return 0;
                   }
    if(d!=0) {a=1; b=(d)^(1/2); c=a*a*b;
             cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
             }
    return 0;
}
    
