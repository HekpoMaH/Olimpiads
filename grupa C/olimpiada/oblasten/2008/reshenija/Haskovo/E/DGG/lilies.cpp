#include<iostream>
using namespace std;
int main()
{
    int n,max=0;
    cin>>n;
    int a,b,c,r1,r2,r3,min=90000,s,d,f;
    cin>>a>>b>>c;
    if(a>max){max=a;}
    if(b>max){max=b;}
    if(c>max){max=c;}
    r1=abs(max-a);
    r2=abs(max-b);
    r3=abs(max-c);
    if(r1<min){min=r1;}
    if(r2<min){min=r2;}
    if(r3<min){min=r3;}
    f=max-min;
    d=max+f;
    cout<<d<<endl;          
    return 0;
}                         
