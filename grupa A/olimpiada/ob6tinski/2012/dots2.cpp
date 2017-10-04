#include<bits/stdc++.h>
using namespace std;
struct vec
{
    int x, y;
};
int ax,ay,bx,by,cx,cy,dx,dy;
vec ab,ac,ad,bc,bd,cd;
double s[5];
int cp(vec a,vec b)
{
    return a.x*b.y-a.y*b.x;
}
int main()
{
    cin>>ax>>ay>>bx>>by>>cx>>cy>>dx>>dy;
    ab.x=ax-bx;
    ab.y=ay-by;
    ac.x=ax-cx;
    ac.y=ay-cy;
    ad.x=ax-dx;
    ad.y=ay-dy;
    bc.x=bx-cx;
    bc.y=by-cy;
    bd.x=bx-dx;
    bd.y=by-dy;
    cd.x=cx-dx;
    cd.y=cy-dy;
    s[1]=fabs(cp(ab,ac)/2.0);
    s[2]=fabs(cp(ab,ad)/2.0);
    s[3]=fabs(cp(ac,ad)/2.0);
    s[4]=fabs(cp(bc,bd)/2.0);
    sort(s+1,s+4+1);reverse(s+1,s+4+1);
    int br=0;
    for(int i=1;i<=4;i++)if(s[i]==0.0)br++;
    if(br==4){cout<<0<<endl;}
    if(br==2){cout<<1<<endl;}
    if(br==1){cout<<2<<endl;}
    if(br==0)
    {
        //cout<<s[1]<<" "<<s[2]<<" "<<s[]
        if(s[1]==s[2]+s[3]+s[4]){cout<<3<<endl;}
        else cout<<4<<endl;
    }
}
