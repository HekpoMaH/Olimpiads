#include<iostream>
#include<cmath>
using namespace std;
int nod(int a,int b)
{
    int r;
    while(b!=0)
    {
        r=a%b;
        a=b;b=r;
    }
    return a;
}
void evklid(int a,int b,int &x1,int &y1,int &d)
{
    int x2,y2,q,t,r;
    x1=1;y1=0;x2=0;y2=1;
    while(b!=0)
    {
        q=a/b;
        r=a%b;
        t=x2;
        x2=x1-q*x2;
        x1=t;
        t=y2;
        y2=y1-q*y2;
        y1=t;
        a=b;b=r;
    }
    d=a;
}
int main()
{
    int a,b,c,nd,x1,y1,xk,yk,a1,b1;
    cin>>a>>b>>c;a1=a;b1=b;
    nd=nod(a,b);
    if(c%nd!=0){cout<<"NR"<<endl;return 0;}
    a/=nd;b/=nd;c/=nd;
    evklid(a,b,x1,y1,nd);
    x1*=c;y1*=c;
    for(int i=-abs(c);i<=abs(c);i++)
    {
        xk=x1+b1*i;
        yk=y1-a1*i;
        cout<<b1<<"*"<<yk<<"+"<<a1<<"*"<<xk<<"="<<c<<endl;
    }
    
}