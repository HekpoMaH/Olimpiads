#include<iostream>
#include<cmath>
using namespace std;

long long nod(long long aa,long long bb)
{
    long long r;
    while(bb!=0)
    {
        r=aa%bb;aa=bb;bb=r;
    }
    return aa;
}
void evkl(long long b,long long c,long long &y1,long long &z1)
{
    long long q,r;
    long long z2,y2,z11,y11;
    z2=0;y2=1;z1=1;y1=0;
    while(b!=0)
    {
        q=c/b;r=c%b;
        c=b;b=r;
        z11=z1;y11=y1;
        z1=z2;y1=y2;
        z2=z11-q*z2;
        y2=y11-q*y2;
    }
}
int main()
{
    long long n,m,x,y,z;
    long long a,b,c;
    long long b1,c1,n1,nd,y0,z0;
    cin>>a>>b>>c>>m>>n;
    b=b-a;c=c-a;n=n-a*m;
    //cout<<b<<" "<<c<<" "<<nod(b,c)<<endl;
    nd=nod(b,c);
    if(n%nd!=0){cout<<0<<endl;return 0;}
    b/=nd;c/=nd;n/=nd;
    evkl(b,c,y,z);
    y0=y*n;z0=z*n;
    //cout<<n<<" "<<y0<<" "<<z0<<endl;
    double p1,q,p2,p;
    p1=double(-z0)/b;
    q=double(y0)/c;
    p2=double(y0+z0-m)/(c-b);
    if(p1<p2)p=p2;
    else p=p1;
    p=ceil(p);q=floor(q);
    if(p<=q)cout<<(long long)(q-p+1)<<endl;
    else cout<<0<<endl;
}
