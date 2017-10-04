#include<iostream>
#include<algorithm>
using namespace std;
struct sth
{
    int f,s;
};
sth a[1000005],m[1000005]
int n,x,br;
set<int> s;
int bs(int rr,sth sr)
{
    int lef=0,righ=rr;
    int mid,ans;
    while(lef<=righ)
    {
        mid=(lef+righ)/2;
        if(m[mid].f<sr.f||(m[mid].f==sr.f&&m[mid].s<sr.s))lef=mid+1;
        if(m[mid].f>sr.f||(m[mid].f==sr.f&&m[mid].s>sr.s))lef=mid+1;
        if(a[c].f<=a)lef=mid+1;
    }
}
void solve()
{
    x=1;
    m[1]=a[1];
    for(int i=2;i<=n;i++)
    {
        if(a[i].f>=m[i].f&&a[i].s>=m[i].s)
        {
            x++;m[x]=a[i];
        }
        else
        {
            int d=bs(x,a[i]);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y;
        if(s.find(x)!=s.end()&&s1.find(y)!=s1.end())continue;
        s.insert(x);s1.insert(y);
        br++;a[br].f=x;a[br].s=y;
    }
    sort(a+1,a+br+1);
    solve();
}
