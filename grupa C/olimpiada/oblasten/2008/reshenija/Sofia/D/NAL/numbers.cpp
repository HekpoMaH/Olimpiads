#include<iostream>
using namespace std;
int main(){
    int a,b,a2b,ab2;
    cin>>a;
    cin>>b;
    cin>>a2b;
    cin>>ab2;
    if(a==0){a=a2b/(a*b);}
    if(b==0){b=a2b/(a*a);}
    if(a2b==0){a2b=a*a*b;}
    if(ab2==0){ab2=a*b*b;}
    a2b=a*a*b;    
    a2b=(ab2/b)*a;
    a=a2b/(a*b);
    b=a2b/(a*a);
    a=ab2/(b*b);
    b=ab2/(a*b);
    ab2=a*b*b;
    ab2=(a2b*b)/a;
    cout<<a<<" "<<b<<" "<<a2b<<" "<<ab2;
    return 0;
    
}
    
