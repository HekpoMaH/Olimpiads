#include<iostream>
using namespace std;
long long ans=-1,yw,xb,yb,y1,y2,yo,r;long long l,ri,mid;
void check(int xw)
{
    yo=(xw*yw-xw*yb-xb*yw+xw*yw)/(xw-xb);
    if(yo>=y1&&yo<=y2)
    {
        ans=yo;
        r=yo;return;
    }
    if(yo>y2){l=yo;return;}
    if(yo<y1){ri=yo;return;}
}
int main()
{
    cin>>y1>>y2>>yw>>xb>>yb>>r;
    y1*=100000000;
    y2*=100000000;
    yw*=100000000;
    xb*=100000000;
    yb*=100000000;
    r*=100000000;
    y2-=r;y1+=r;
    ri=xb;
    while(l<=ri)
    {
        mid=(l+ri)/2;
        check(mid);
    }
    cout<<ans<<endl;
}
