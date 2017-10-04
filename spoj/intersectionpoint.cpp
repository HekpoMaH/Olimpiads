#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
double xr,yr,r,xo,x2,yo,y2,xx,yy,a,b,c,f,s;
void solve()
{
    cin>>xr>>yr>>r>>xo>>yo>>x2>>y2;
    if(xo==x2)
    {
        xx=xo;
        s=x2-xr;
        yy=sqrt(r*r-s*s);
        yy+=yr;
        //cout<<yy<<endl;
        if(yy>=yo&&yy<=y2)
        {
            cout<<setiosflags(ios::fixed)<<setprecision(2)<<xx<<" "<<yy<<endl;
            return;
        }
        yy=-sqrt(r*r-s*s);
        yy+=yr;//cout<<yy<<endl;
        if(yy>=yo&&yy<=y2)
        {
            cout<<setiosflags(ios::fixed)<<setprecision(2)<<xx<<" "<<yy<<endl;
            return;
        }
    }
    if(yo==y2)
    {
        yy=yo;
        s=y2-yr;
        xx=sqrt(r*r-s*s);
        xx+=xr;
        if(xx>=xo&&xx<=x2)
        {
            cout<<setiosflags(ios::fixed)<<setprecision(2)<<xx<<" "<<yy<<endl;
            return;
        }
        xx=-sqrt(r*r-s*s);
        xx+=xr;
        if(xx>=xo&&xx<=x2)
        {
            cout<<setiosflags(ios::fixed)<<setprecision(2)<<xx<<" "<<yy<<endl;
            return;
        }
    }
    double m,d,e,f,k;
    m=x2-xo;m/=(y2-yo);
    d=1/m;e=(yo*m-xo)/m;
    f=(xr*xr+e*e+yr*yr-2*e*yr-r*r);
    k=d*e-d*yr-xr;
    xx=(-k+sqrt(k*k-(1+d*d)*f))/(1+d*d);
    yy=d*xx+e;
    //cout<<xx<<" "<<yy<<endl;
    if(xo>x2)swap(xo,x2);
    if(yo>y2)swap(yo,y2);
    if(xx>=xo&&xx<=x2&&yy>=yo&&yy<=y2)cout<<setiosflags(ios::fixed)<<setprecision(2)<<xx<<" "<<yy<<endl;
    //if(xx>=x2&&xx<=xo&&yy>=y2&&yy<=yo)cout<<setiosflags(ios::fixed)<<setprecision(2)<<xx<<" "<<yy<<endl;
    xx=(-k-sqrt(k*k-(1+d*d)*f))/(1+d*d);
    yy=d*xx+e;
    if(xx>=xo&&xx<=x2&&yy>=yo&&yy<=y2)cout<<setiosflags(ios::fixed)<<setprecision(2)<<xx<<" "<<yy<<endl;
    //if(xx>=x2&&xx<=xo&&yy>=y2&&yy<=yo)cout<<setiosflags(ios::fixed)<<setprecision(2)<<xx<<" "<<yy<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}
