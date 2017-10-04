#include<iostream>
#include<set>
#include<vector>
using namespace std;
int x1,y1,x2,y2;
struct pr
{
    int xmin,xmax,ymin,ymax;
};
vector<pr> recs;
pr hpr;
set<int> xss,yss;
int n;
vector<int> xs,ys;
set<int>::iterator it;
long long ans;
bool check(pr sb,int x11,int y11)
{
    if(sb.xmin<=x11&&sb.xmax>x11&&sb.ymin<=y11&&sb.ymax>y11)return true;
    return false;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x1>>y1>>x2>>y2;
        xss.insert(x1);
        xss.insert(x2);
        yss.insert(y1);
        yss.insert(y2);
        hpr.xmin=min(x1,x2);
        hpr.xmax=max(x1,x2);
        hpr.ymin=min(y1,y2);
        hpr.ymax=max(y1,y2);
        recs.push_back(hpr);
    }
    for(it=xss.begin();it!=xss.end();it++)xs.push_back(*it);
    for(it=yss.begin();it!=yss.end();it++)ys.push_back(*it);
    for(int i=0;i<xs.size()-1;i++)
    {
        for(int j=0;j<ys.size()-1;j++)
        {
            for(int k=0;k<recs.size();k++)
            {
                if(check(recs[k],xs[i],ys[j])==true)
                {
                    //cout<<xs[i]<<" "<<xs[i+1]<<" "<<ys[j]<<" "<<ys[j+1]<<endl;
                    ans+=(long long)((xs[i+1]-xs[i])*(ys[j+1]-ys[j]));
                    break;
                }
            }
        }
    }
    cout<<ans<<endl;
}