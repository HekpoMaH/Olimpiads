#include<bits/stdc++.h>
using namespace std;
int n,m,a[309][309],parent[309];

struct edge
{
    int a,b,t,in;
};vector<edge> g,t;
bool cmp(edge first,edge second)
{
    if(first.t<second.t)return true;
    if(first.t>second.t)return false;
    if(first.a<second.a)return true;
    if(first.a>second.a)return false;
    if(first.b<second.b)return true;
    return false;
}
bool find(int p,int q)
{
    while(p!=parent[p])p=parent[p];
    while(q!=parent[q])q=parent[q];
    if(p==q)return true;
    return false;
}
void uniset(int p,int q)
{

    int k=p;
    while(k!=parent[k])k=parent[k];
    p=q;
    while(p!=parent[p])
    {
        q=parent[p];
        parent[p]=k;//cout<<"?"<<endl;
        p=q;
    }
    parent[p]=k;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    int x,y,z;
    edge e;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y>>z;
        e.a=x;e.b=y;e.t=z;
        g.push_back(e);
    }
    for(int i=1;i<=n;i++)parent[i]=i;
    sort(g.begin(),g.end(),cmp);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)cin>>a[i][j];
    }
    bool fl;
    for(int i=0;i<m;i++)
    {
        fl=find(g[i].a,g[i].b);
        if(!fl)
        {
            t.push_back(g[i]);
            uniset(g[i].a,g[i].b);
        }
        if(t.size()==n-1)break;
    }
    for(int i=0;i<n-1;i++)cout<<t[i].in<<endl;
}
