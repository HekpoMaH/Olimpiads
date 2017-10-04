#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<cstdio>
#include<iomanip>
using namespace std;
long long n,m,x,y,a,b,l,r,mid,koef,cx,cy,bx,by,tx,ty,s1,s2,change;
long long nod(int x,int y)
{
    long long r;
    while(y!=0)
    {
        r=x%y;
        x=y;y=r;
    }
    return x;
}
int main()
{
    cin>>n>>m>>x>>y>>a>>b;

    long long nd=nod(a,b);
    a/=nd;b/=nd;koef=min(n/a,m/b);a=a*koef;b=b*koef;
    cx=(a+1)/2;
    cy=(b+1)/2;
    bx=x-cx;by=y-cy;
    tx=x+(a-cx);ty=y+(b-cy);
    if(bx<0)
    {
        change=0-bx;
        bx=0;
        tx+=change;
    }
    if(tx>n)
    {
        change=tx-n;
        tx=n;
        bx-=change;
    }
    if(by<0)
    {
        change=0-by;
        by=0;
        ty+=change;
    }
    if(ty>m)
    {
        change=ty-m;
        ty=m;
        by-=change;
    }
    cout<<bx<<" "<<by<<" "<<tx<<" "<<ty<<endl;
}

//497


