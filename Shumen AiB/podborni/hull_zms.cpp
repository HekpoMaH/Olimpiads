#include<bits/stdc++.h>
using namespace std;
struct point
{
    double x,y;
    int inidx;
};
point p[100009],mp,p0;
int n;
double eps=1e-9;
double ori(point p1,point p2,point p3)
{
    return (p2.x-p1.x)*(p3.y-p1.y)-(p2.y-p1.y)*(p3.x-p1.x);
}
bool cmp(point p1,point p2)
{
    double x1,y1;
    double ang1,ang2;
    x1=p1.x-mp.x;
    y1=p1.y-mp.y;
    ang1=atan2(y1,x1);
    x1=p2.x-mp.x;
    y1=p2.y-mp.y;
    ang2=atan2(y1,x1);
    if(ang1<ang2)return true;
    return false;
}
int main()
{
    //cout<<p0.x<<" "<<p0.y<<endl;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    mp.y=99999.0;//p00.x=1;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i].x>>p[i].y;p[i].inidx=i;
        if(p[i].y<mp.y)mp=p[i];
        else if(p[i].y==mp.y&&p[i].x<mp.x)mp=p[i];
    }
    sort(p+1,p+n+1,cmp);
    int sidx;
    vector<point> hull;
    hull.push_back(p[1]);
    hull.push_back(p[2]);
    hull.push_back(p[3]);
    for(int i=4;i<=n;i++)
    {
        //cout<<"watchin "<<p[i].x<<" "<<p[i].y<<" "<<ori(hull[hull.size()-2],hull[hull.size()-1],p[i])<<endl;
        while(hull.size()>=3&&ori(hull[hull.size()-2],hull[hull.size()-1],p[i])<0.0)hull.pop_back();
        hull.push_back(p[i]);
        //sidx++;
    }
    cout<<hull.size()<<endl;
    mp.x=99999.0;
    for(int i=0;i<hull.size();i++)
    {
        //cout<<mp.x<<" "<<mp.y<<" vs"<<" "<<hull[i].x<<" "<<hull[i].y<<endl;
        if(mp.x>hull[i].x)mp=hull[i],sidx=i;
        if(hull[i].x==mp.x&&mp.y>hull[i].y)mp=hull[i],sidx=i;
    }
    //cout<<sidx<<endl;
    for(int i=0;i<hull.size();i++)
    {
        cout<<hull[sidx].inidx<<" ";
        sidx--;
        if(sidx<0)sidx=hull.size()-1;
    }cout<<endl;
}
/*
4
0.5 2
3 1
3 3
2.5 2
*/
