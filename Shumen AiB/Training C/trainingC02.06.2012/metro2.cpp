#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cmath>
using namespace std;
int t[25003],n,m,k;
struct ll
{
    int x,y;
};
ll a[20000];
void update(int val,int idx)
{
    idx++;
    while(idx<=m)
    {
        //cout<<"idx="<<idx<<" "<<"t[idx]="<<t[idx]<<" "<<"val="<<val<<endl;
        t[idx]=max(t[idx],val);
        idx+=idx&(-idx);
    }
}
int res(int idx)
{
    int s=0;
    while(idx>0)
    {
        s=max(s,t[idx]);
        idx-=idx&(-idx);
    }
    return s;
}
bool cmp(ll f,ll s)
{
    if(f.x<s.x)return true;
    if(f.x>s.x)return false;
    if(f.y>s.y)return true;
    return false;
}
int main()
{
    cin>>n>>m>>k;
    for(int i=1;i<=k;i++)
    {
        cin>>a[i].x>>a[i].y;
    }
    sort(a+1,a+n+1,cmp);
    int r=0,ans2=0;
    for(int i=1;i<=k;i++)
    {
        r=res(a[i].y);
        ans2=max(ans2,r+1);
        update(r+1,a[i].y);
        //for(int j=1;j<=m;j++)cout<<t[j]<<" ";
        //cout<<endl<<"r="<<r<<endl;
        //cout<<endl;
    }
    //r=res(m+1);
    double ans=(double)((ans2*(sqrt((double)20000)))+((m-ans2+n-ans2)*100));
    cout<<setiosflags(ios::fixed)<<setprecision(0)<<ans<<endl;
    return 0;
}