#include<iostream>
#include<vector>
using namespace std;
struct point
{
    int x,y;
};
struct circle
{
    int p1,p2,p3,p4,x,y,rad;
};
struct ls
{
    int x1,x2,y1,y2;
};
int t;
vector<point> p;
vector<circle> c;
vector<ls> l;
bool check1(int r)
{
    int n1=p.size(),n2=c.size(),n3=l.size();
    for(int i=0;i<n1;i++)
    {
        if(r>p[i].x)return false;
    }
    for(int i=0;i<n2;i++)
    {
        if(r>c[i].p1)return false;
    }
    for(int i=0;i<n3;i++)
    {
        if(r>l[i].x1||r>l[i].x2)return false;
    }
    return true;
}
bool check2(int r)
{
    int n1=p.size(),n2=c.size(),n3=l.size();
    for(int i=0;i<n1;i++)
    {
        if(r>p[i].y)return false;
    }
    for(int i=0;i<n2;i++)
    {
        if(r>c[i].p3)return false;
    }
    for(int i=0;i<n3;i++)
    {
        if(r>l[i].y1||r>l[i].y2)return false;
    }
    return true;
}
bool check3(int r)
{
    int n1=p.size(),n2=c.size(),n3=l.size();
    for(int i=0;i<n1;i++)
    {
        if(r<p[i].x)return false;
    }
    for(int i=0;i<n2;i++)
    {
        if(r<c[i].p2)return false;
    }
    for(int i=0;i<n3;i++)
    {
        if(r<l[i].x1||r<l[i].x2)return false;
    }
    return true;
}
bool check4(int r)
{
    int n1=p.size(),n2=c.size(),n3=l.size();
    for(int i=0;i<n1;i++)
    {
        if(r<p[i].y)return false;
    }
    for(int i=0;i<n2;i++)
    {
                if(r<c[i].p4)return false;
    }
    for(int i=0;i<n3;i++)
    {
        if(r<l[i].y1||r<l[i].y2)return false;
    }
    return true;
}
void solve()
{
    p.clear();c.clear();l.clear();
    int n;
    char tp;
    point pp;
    circle cc;
    ls ll;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>tp;
        if(tp=='p')
        {
            cin>>pp.x>>pp.y;
            p.push_back(pp);
        }
        if(tp=='c')
        {
            cin>>cc.x>>cc.y>>cc.rad;
            cc.p1=cc.x-cc.rad;
            cc.p2=cc.x+cc.rad;
            cc.p3=cc.y-cc.rad;
            cc.p4=cc.y+cc.rad;
            c.push_back(cc);
        }
        if(tp=='l')
        {
            cin>>ll.x1>>ll.y1>>ll.x2>>ll.y2;
            l.push_back(ll);
        }
    }
    int lx,ly,rx,ry,mid;
    int lef=-1000,righ=1000;
    bool verno;
    while(lef<=righ)
    {
        mid=(lef+righ)/2;
        verno=check1(mid);
        //cout<<mid<<" "<<verno<<endl;
        if(verno==true)lx=mid,lef=mid+1;
        else righ=mid-1;
    }
    cout<<lx<<" ";
    lef=-1000;righ=1000;
    while(lef<=righ)
    {
        mid=(lef+righ)/2;
        verno=check2(mid);
        if(verno==true)ly=mid,lef=mid+1;
        else righ=mid-1;
    }
    cout<<ly<<" ";
    lef=-1000;righ=1000;
    while(lef<=righ)
    {
        mid=(lef+righ)/2;
        verno=check3(mid);
        if(verno==true)rx=mid,righ=mid-1;
        else lef=mid+1;
    }
    cout<<rx<<" ";
    lef=-1000;righ=1000;
    while(lef<=righ)
    {
        mid=(lef+righ)/2;
        verno=check4(mid);
        //cout<<mid<<" "<<verno<<endl;
        if(verno==true)ry=mid,righ=mid-1;
        else lef=mid+1;
    }
    cout<<ry<<endl;
}
int main()
{
    cin>>t;
    while(t--)solve();
    return 0;
}