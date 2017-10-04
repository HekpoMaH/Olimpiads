#include<iostream>
using namespace std;
struct triang
{
    int xa,xb,xc,ya,yb,yc;
};
struct vec
{
    int x,y;
};
triang abc,pqr[6];
int cp(vec o,vec t)
{
    return o.x*t.y-t.x*o.y;
}
int cp2(int aax,int aay,int bbx,int bby,int ccx,int ccy)
{
    int x1=aax-bbx,y1=aay-bby;
    int x2=aax-ccx,y2=aay-ccy;
    return x1*y2-x2*y1;
}
int chk2(int aax,int aay,int bbx,int bby,int ccx,int ccy,int ddx,int ddy)
{
    int d1,d2,d3,d4;
    d1=cp2(aax,aay,bbx,bby,ccx,ccy);d2=cp2(aax,aay,bbx,bby,ddx,ddy);
    d3=cp2(ccx,ccy,ddx,ddy,aax,aay);d4=cp2(ccx,ccy,ddx,ddy,bbx,bby);
    if(d1*d2<0&&d3*d4<0)return 1;
    return 0;
}
int chk(triang a,triang b)
{
    int br=0,br2=0;
    vec at,bt,ct,ac,cb,ba;
    at.x=a.xa-b.xa;at.y=a.ya-b.ya;
    bt.x=a.xb-b.xa;bt.y=a.yb-b.ya;
    ct.x=a.xc-b.xa;ct.y=a.yc-b.ya;
    ac.x=a.xa-a.xc;ac.y=a.ya-a.yc;
    cb.x=a.xc-a.xb;cb.y=a.yc-a.yb;
    ba.x=a.xb-a.xa;ba.y=a.yb-a.ya;
    //cout<<cp(ac,at)<<" "<<cp(cb,ct)<<" "<<cp(ba,bt)<<endl;
    if(cp(ac,at)<=0&&cp(cb,ct)<=0&&cp(ba,bt)<=0){cout<<1;return 1;}

    at.x=a.xa-b.xb;at.y=a.ya-b.yb;
    bt.x=a.xb-b.xb;bt.y=a.yb-b.yb;
    ct.x=a.xc-b.xb;ct.y=a.yc-b.yb;//cout<<cp(ac,at)<<" "<<cp(cb,ct)<<" "<<cp(ba,bt)<<endl;
    if(cp(ac,at)<=0&&cp(cb,ct)<=0&&cp(ba,bt)<=0){cout<<1;return 1;}
    at.x=a.xa-b.xc;at.y=a.ya-b.yc;
    bt.x=a.xb-b.xc;bt.y=a.yb-b.yc;
    ct.x=a.xc-b.xc;ct.y=a.yc-b.yc;//cout<<cp(ac,at)<<" "<<cp(cb,ct)<<" "<<cp(ba,bt)<<endl;
    if(cp(ac,at)<=0&&cp(cb,ct)<=0&&cp(ba,bt)<=0){cout<<1;return 1;}
    vec ab,cd;
    ab.x=a.xa-a.xb;ab.y=a.ya-a.yb;
    cd.x=b.xa-b.xb;cd.y=b.ya-b.yb;
    br=0+chk2(a.xa,a.ya,a.xb,a.yb,b.xa,b.ya,b.xb,b.yb)+chk2(a.xa,a.ya,a.xb,a.yb,b.xa,b.ya,b.xc,b.yc)+chk2(a.xa,a.ya,a.xb,a.yb,b.xb,b.yb,b.xc,b.yc)+
            chk2(a.xa,a.ya,a.xc,a.yc,b.xa,b.ya,b.xb,b.yb)+chk2(a.xa,a.ya,a.xc,a.yc,b.xa,b.ya,b.xc,b.yc)+chk2(a.xa,a.ya,a.xc,a.yc,b.xb,b.yb,b.xc,b.yc)+
            chk2(a.xb,a.yb,a.xc,a.yc,b.xa,b.ya,b.xb,b.yb)+chk2(a.xb,a.yb,a.xc,a.yc,b.xa,b.ya,b.xc,b.yc)+chk2(a.xb,a.yb,a.xc,a.yc,b.xb,b.yb,b.xc,b.yc);
    if(br!=0){cout<<1;return 1;}
    return 0;
}
int main()
{
    cin>>abc.xa>>abc.ya>>abc.xb>>abc.yb>>abc.xc>>abc.yc;
    for(int i=1;i<=4;i++)
    {
        cin>>pqr[i].xa>>pqr[i].ya>>pqr[i].xb>>pqr[i].yb>>pqr[i].xc>>pqr[i].yc;
        //cout<<i<<endl;
        if(chk(abc,pqr[i])==0)
        {
            if(chk(pqr[i],abc)==0)cout<<0;
        }
    }
    cout<<endl;
}
