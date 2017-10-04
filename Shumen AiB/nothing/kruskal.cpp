#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m,x,y,z,parent[100];
struct edge
{
    int a,b,t;
};
vector<edge> t,g;
edge e;
bool cmp(edge f,edge s)
{
    if(f.t<s.t)return true;
    if(f.t>s.t)return false;
    if(f.a<s.a)return true;
    if(f.a>s.a)return false;
    if(f.b<s.b)return true;
    return false;
}
bool fathers(int p,int q)
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
        parent[p]=k;
        p=q;
    }
    parent[p]=k;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y>>z;
        e.a=x;
        e.b=y;
        e.t=z;
        g.push_back(e);
    }
    for(int i=1;i<100;i++)parent[i]=i;
    sort(g.begin(),g.end(),cmp);
    //cout<<"whats up"<<endl;
    for(int i=0;i<g.size();i++)
    {
        if(fathers(g[i].a,g[i].b))continue;
        t.push_back(g[i]);
        if(t.size()==n-1)break;
        uniset(g[i].a,g[i].b);   
    }
    int sum=0;
    for(int i=0;i<t.size();i++)
    {
        sum+=t[i].t;
        cout<<t[i].a<<" "<<t[i].b<<endl;
    }
    cout<<sum<<endl;
    return 0;
}