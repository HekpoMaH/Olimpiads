#include<bits/stdc++.h>
using namespace std;
struct point
{
    int x,y;
};
int direction(point a,point b,point c)
{
    int a1=b.x-a.x,a2=b.y-a.y,b1=c.x-a.x,b2=c.y-a.y;
    int p=a1*b2,q=a2*b1;
    if(p>q)return 1;
    if(p<q)return -1;
    return 0;
}
bool onsegment(point a,point b,point c)
{
    return min(a.x,b.x)<=c.x&&c.x<max(a.x,b.x)&&min(a.y,b.y)<=c.y&&c.y<max(a.y,b.y);
}
bool intersectsegments(point a,point b,point c,point d)
{
    int d1,d2,d3,d4;
    d1=direction(a,b,c);
    d2=direction(a,b,d);
    d3=direction(c,d,a);
    d4=direction(c,d,b);
    if(d1*d2<0&&d3*d4<0)return true;
    if(d1==0&&onsegment(a,b,c))return true;
    if(d2==0&&onsegment(a,b,d))return true;
    if(d3==0&&onsegment(c,d,a))return true;
    if(d4==0&&onsegment(c,d,b))return true;
    return false;
}
bool ontriangle(point a,point b,point c,point m)
{
    int d1=direction(a,b,m);
    int d2=direction(b,c,m);
    int d3=direction(c,a,m);
    if(d1>=0&&d2>=0&&d3>=0)return true;
    if(d1<=0&&d2<=0&&d3<=0)return true;
    return false;
}
bool intersecttriangles(point a,point b,point c,point p,point q,point r)
{
    if(ontriangle(a,b,c,p)||ontriangle(a,b,c,q)||ontriangle(a,b,c,r))return true;
    if(ontriangle(p,q,r,a)||ontriangle(p,q,r,b)||ontriangle(p,q,r,c))return true;
    if(intersectsegments(a,b,p,q)||intersectsegments(a,b,p,r)||intersectsegments(a,b,q,r))return true;
    if(intersectsegments(b,c,p,q)||intersectsegments(b,c,p,r)||intersectsegments(b,c,q,r))return true;
    if(intersectsegments(c,a,p,q)||intersectsegments(c,a,p,r)||intersectsegments(c,a,q,r))return true;
    return false;
}
int main()
{
    point a,b,c,p[5],q[5],r[5];
    cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y;
    for(int i=0;i<4;i++)
    {
        cin>>p[i].x>>p[i].y>>q[i].x>>q[i].y>>r[i].x>>r[i].y;
        cout<<intersecttriangles(a,b,c,p[i],q[i],r[i]);
    }
    cout<<endl;
}
/*
4 1 13 4 7 7
9 6 14 7 11 9
10 3
16 5
15 1
4 3 5 7
7 4
10 5
8 4
10 4
*/
