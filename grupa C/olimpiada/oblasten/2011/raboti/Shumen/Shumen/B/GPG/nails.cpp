#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
const int MAXN=1024;
struct point
{
    int x1,y1,x2,y2;
};
int n;
point a[MAXN];
int br[MAXN];
void readInput()
{
    point p;
    int x,y,z,f;
    int i=0;
    while(cin>>x>>y>>z>>f) {
        p.x1=x;
        p.y1=y;
        p.x2=z;
        p.y2=f;
        a[++i]=p;
    }
    n=i;
}
void solve()
{
    int i,j,ans=0;
    for(i=1;i<n;i++)
    for(j=i+1;j<n;j++) {
        if((a[j].x1>=min(a[i].x1,a[i].x2)&&a[j].x1<=max(a[i].x1,a[i].x2))||(a[j].x2>=min(a[i].x1,a[i].x2)&&a[j].x2<=max(a[i].x1,a[i].x2))) {
            if(a[i].y1==a[i].y2||a[j].y1==a[j].y2) br[i]++;
            else
            if((a[j].y1>=min(a[i].y1,a[i].y2)&&a[j].y1<=max(a[i].y1,a[i].y2))||(a[j].y2>=min(a[i].y1,a[i].y2)&&a[j].y2<=max(a[i].y1,a[i].y2)))
            br[i]++;
        }
    }
    for(i=1;i<n;i++) {
        if((a[n].x1>=min(a[i].x1,a[i].x2)&&a[n].x1<=max(a[i].x1,a[i].x2))||(a[n].x2>=min(a[i].x1,a[i].x2)&&a[n].x2<=max(a[i].x1,a[i].x2))) {
            if(a[i].y1==a[i].y2||a[n].y1==a[n].y2) ans+=br[i];
            else
            if((a[n].y1>=min(a[i].y1,a[i].y2)&&a[n].y1<=max(a[i].y1,a[i].y2))||(a[n].y2>=min(a[i].y1,a[i].y2)&&a[n].y2<=max(a[i].y1,a[i].y2)))
            ans+=br[i];
        }
        else {
            if((a[n].y1>=min(a[i].y1,a[i].y2)&&a[n].y1<=max(a[i].y1,a[i].y2))||(a[n].y2>=min(a[i].y1,a[i].y2)&&a[n].y2<=max(a[i].y1,a[i].y2))) ans+=br[i];
        }
    }
    cout<<ans<<endl;
}
int main()
{
    readInput();
    solve();
    return 0;
}
