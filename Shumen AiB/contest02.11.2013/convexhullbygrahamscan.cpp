#include<cmath>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int n;
struct point{double x,y;};
point a[100],p0,p1;
vector<point> ob;
bool cmp(point f,point s)
{
    double x1,y1;
    double ang1,ang2;
    x1=f.x-p0.x;
    y1=f.y-p0.y;
    ang1=atan2(y1,x1);
    x1=s.x-p0.x;
    y1=s.y-p0.y;
    ang2=atan2(y1,x1);
    if(ang1<ang2)return true;
    return false;
}
double ori(point a1,point a2,point a3)
{
    double x1,y1,x2,y2;
    x1=a2.x-a1.x;
    x2=a3.x-a1.x;
    y1=a2.y-a1.y;
    y2=a3.y-a1.y;
    return x1*y2-x2*y1;
}
int main()
{
    cin>>n;
    p0.x=999;p0.y=999;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].x>>a[i].y;
        if(a[i].y<p0.y)p0=a[i];
        if(a[i].y==p0.y)if(a[i].x<p0.x)p0=a[i];
    }
    sort(a+1,a+n+1,cmp);
    ob.push_back(p0);ob.push_back(a[2]);
    for(int i=3;i<=n;i++)
    {
        if(ori(ob[ob.size()-2],ob[ob.size()-1],a[i])>=0)ob.push_back(a[i]);
        else{while(ori(ob[ob.size()-2],ob[ob.size()-1],a[i])<0)ob.pop_back();ob.push_back(a[i]);}
        /*cout<<"-------------"<<endl;
        for(int j=0;j<ob.size();j++)
        {
            cout<<ob[j].x<<" "<<ob[j].y<<endl;
        }*/
    }
    for(int i=0;i<ob.size();i++)cout<<ob[i].x<<" "<<ob[i].y<<endl;
    //cout<<endl;
    return 0;
}
