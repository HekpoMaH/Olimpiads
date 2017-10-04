#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int used[60][60];
int parent[60];
int n,x,y,z;
struct edge
{
    int a,b,t;
};
vector<edge> g,t;
edge e;
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
        parent[p]=k;
        p=q;
    }
    parent[p]=k;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>z;
            if(j>i)
            {
                e.a=i;e.b=j;e.t=z;
                g.push_back(e);
            }
        }
    }
    for(int i=1;i<=n;i++)parent[i]=i;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>x;
            if(x==1&&j>i)
            {
                for(int k=0;k<g.size();k++)
                if(g[k].a==i&&g[k].b==j)g[k].t=0;
            }
        }
    }
    sort(g.begin(),g.end(),cmp);
    bool fl;
    for(int i=0;i<g.size();i++)
    {
        fl=find(g[i].a,g[i].b);
        //cout<<"fl="<<fl<<endl;
        if(!fl)
        {
            t.push_back(g[i]);
            uniset(g[i].a,g[i].b);
        }
    }
    int sum=0;
    for(int i=0;i<t.size();i++)
    {
        sum+=t[i].t;
    }
    cout<<sum<<endl;
}