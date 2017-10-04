#include<bits/stdc++.h>
using namespace std;
struct pl
{
    double a,b;
} p[1009];
int n;
bool cmp(pl x,pl y)
{
    return x.a/x.b>y.a/y.b;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>p[i].a>>p[i].b;
    sort(p+1,p+1+n,cmp);
    double sa,sb,x,t;
    sa=0;sb=0;
    for(int i=1;i<=n;i++)sb+=p[i].b;
    int i=0;
    while(sa<=sb)
    {
        i++;
        sa+=p[i].a;
        sb-=p[i].b;
    }
    if(sa==sb)t=sa;

    else
    {
        sa-=p[i].a;
        x=(sb-sa+p[i].b)/(p[i].a+p[i].b);
        t=sa+p[i].a*x;
    }
    cout<<setiosflags(ios::fixed)<<setprecision(10)<<t<<endl;
}
