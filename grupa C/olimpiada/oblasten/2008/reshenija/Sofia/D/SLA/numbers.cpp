#include<iostream>
using namespace std;
int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==0){a=(c/b)/2;c=a*a*b;d=a*b*b;cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";}
    else if(b==0){b=(c/a)/2;c=a*a*b;d=a*b*b;cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";}
    else if(c==0){c=a*a*b;d=a*b*b;cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";}
    else if(d==0){c=a*a*b;d=a*b*b;cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";}
    
    else if(a==0&&c==0){a=(d/b)/2;c=a*a*b;d=a*b*b;cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";}
    else if(a==0&&d==0){a=(c/b)/2;c=a*a*b;d=a*b*b;cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";}
    else if(b==0&&c==0){b=(d/a)/2;c=a*a*b;d=a*b*b;cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";}
    else if(b==0&&d==0){b=c/(a*a);c=a*a*b;d=a*b*b;cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";}
    else if(c==0&&d==0){c=a*a*b;d=a*b*b;cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";}
    else if(d==0&&c==0){c=a*a*b;d=a*b*b;cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";}
    
    
    c=a*a*b;
    d=a*b*b;
    cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
    
    
    return 0;
}
