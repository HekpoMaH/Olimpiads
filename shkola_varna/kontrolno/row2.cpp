#include<bits/stdc++.h>
using namespace std;
struct wtf
{
    int el,pd;
    bool operator <(const wtf &x)const
    {
        return el<x.el;
    }
};
set<wtf> s;
int a[1009];
int n,k;
wtf pe,maker;
set<wtf>::iterator it;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    int i,j;
    for(i=1;i<=k;i++)cin>>a[i],pe.el=a[i],pe.pd=1,s.insert(pe);
    for(i=1;i<=n;i++)
    {
        //cout<<i<<endl;
        it=s.begin();pe=*it;//cout<<*it<<endl;
        for(j=pe.pd;j<=k;j++)
        {
            maker.el=a[j]+pe.el;maker.pd=j;
            s.insert(maker);
        }
        s.erase(*it);
    }
    cout<<pe.el<<endl;
}
