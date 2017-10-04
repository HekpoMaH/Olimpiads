#include<iostream>
#include<algorithm>
#include<cstdio>
#include<iomanip>
using namespace std;
struct diag
{
    int f,s;
};
diag d[20004];
int n,m,k,l,g;
bool cmp(diag o,diag t)
{
    if(o.f<t.f)return true;
    if(o.f>t.f)return false;
    if(o.s<t.s)return true;
    return false;
}
diag r[20004];
int bs(int l,diag mk)
{
    int left=0,right=l,c,x=0;
    while(left<=right)
    {
        c=(right+left)/2;
        if(r[c].f<mk.f&&r[c].s<mk.s)right=c-1;
        if(r[c].f>mk.f&&r[c].s>mk.s)left=c+1;
        if(r[c].f<mk.f&&r[c].s<mk.s&&mk.f<r[c+1].f&&mk.s<r[c+1].s)x=c;
    }
    if(x==0)return c;
    return x;
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=k;i++)
    {
        scanf("%d%d",&d[i].f,&d[i].s);
    }
    sort(d+1,d+k+1,cmp);
    //cout<<d[1].f<<" "<<d[1].s<<endl;
    r[1]=d[1];
    l=1;
    for(int i=2;i<=n;i++)
    {
        if(d[i].f>r[l].f&&d[i].s>r[l].s)
        {
            l++;
            r[l]=d[i];
        }
        else
        {
            g=bs(l,d[i]);
            if(r[g].f<d[i].f&&r[g].s<d[i].s&&d[i].f<r[g+1].f&&d[i].s<r[g+1].s)r[g+1]=d[i];
        }
    }
    double ans=(double)((l*(141.421356237309))+((m-l+n-l)*100));
    cout<<setiosflags(ios::fixed)<<setprecision(0)<<ans<<endl;
    return 0;
}
