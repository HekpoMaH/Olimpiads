//kod
#include <iostream>
using namespace std;
int main()
{
    long int n,e,d,s,h,dh,sth;
    cin>>n;
    e=n%10;
    d=n/10%10;
    s=n/100%10;
    h=n/1000%10;
    dh=n/10000%10;
    sth=n/100000;
    int br=0;
    if (e%2!=0)br++;
    if (d%2!=0)br++;
    if (s%2!=0)br++;
    if (h%2!=0)br++;    
    if (dh%2!=0)br++;
    if (sth%2!=0)br++;
    int a=0,b=0;
    a=sth*100+h*10+d;
    b=d*100+h*10+sth;
    int r=0;
    if (a>b)r=a-b;
    if (a<b)r=b-a;
    cout<<br<<r<<endl;
    system ("pause");
    return 0;
}
    
    
    
