#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0;
struct line
{
    int xb,yb,xe,ye;
};
line a[50009],b[50009];
void cal(int f,int s)
{
    if(a[f].yb>b[s].ye)return;
    if(a[f].ye<b[s].yb)return;
    if(b[s].xb>a[f].xe)return;
    if(b[s].xe<a[f].xb)return;
    ans=max(min(min( abs(b[s].xb-a[f].xb),abs(b[s].xe-a[f].xb) ), min(abs(a[f].ye-b[s].yb),abs(a[f].yb-b[s].yb)) ),ans);
}
int main()
{
    cin>>n>>m;
    int x,y,l;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y>>l;
        a[i].xb=x;a[i].yb=y;
        a[i].xe=x;a[i].ye=y+l;
    }
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y>>l;
        b[i].xb=x;b[i].yb=y;
        b[i].xe=x+l;b[i].ye=y;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cal(i,j);
        }
    }
    cout<<ans<<endl;
}
