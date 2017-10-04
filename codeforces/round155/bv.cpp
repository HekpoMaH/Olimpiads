#include<cstdio>
#include<map>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
struct so
{
    int s;
    int e;
    int o;
    int p;
}a[101];
bool cmp(so b,so c)
{
    return b.s<c.s;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,i,d,p,t,m,ma=0,j;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>m>>d>>p>>t;
        if(m==1)a[i].e=d;
        if(m==2)a[i].e=31+d;
        if(m==3)a[i].e=59+d;
        if(m==4)a[i].e=90+d;
        if(m==5)a[i].e=120+d;
        if(m==6)a[i].e=151+d;
        if(m==7)a[i].e=181+d;
        if(m==8)a[i].e=212+d;
        if(m==9)a[i].e=243+d;
        if(m==10)a[i].e=273+d;
        if(m==11)a[i].e=304+d;
        if(m==12)a[i].e=334+d;
        a[i].s=a[i].e-t+1;
        a[i].p=p;
        a[i].o=p;
        ma=max(ma,p);
    }
    sort(a,a+n,cmp);
    for(i=1;i<n;i++)
    {
        for(j=i-1;j>=0;j--)
        if(a[j].e>=a[i].s)
        {
            a[i].o+=a[j].p;
            ma=max(a[i].o,ma);
        }
    }
    cout<<ma<<endl;
}
