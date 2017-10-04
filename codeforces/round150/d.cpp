#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
struct edge
{
    int a,b,t;
};
vector<edge> g,t;
edge e;
int n,m,x,y,z,hh,tt;
int parent[100005];
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
    cin>>n>>m>>hh>>tt;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y;z=1;
        e.a=x;e.b=y;e.t=z;
        g.push_back(e);
    }
    for(int i=1;i<=n;i++)parent[i]=i;
    sort(g.begin(),g.end(),cmp);
    bool fl;
    for(int i=0;i<m;i++)
    {
        fl=find(g[i].a,g[i].b);
        //cout<<fl<<endl;
        //cout<<"_____________"<<endl;
        //for(int j=1;j<=n;j++)cout<<j<<" "<<parent[j]<<endl;
        //cout<<"^^^^^^^^^^^^^"<<endl;
        if(!fl)
        {
            t.push_back(g[i]);
            uniset(g[i].a,g[i].b);
            //for(int j=1;j<=n;j++)cout<<j<<" "<<parent[j]<<endl;
        }
        if(t.size()==n-1)break;
    }
    int sum=0;
    int ebahti[100005];
    memset(ebahti,0,sizeof(ebahti));
    for(int i=0;i<t.size();i++)ebahti[t[i].a]=ebahti[t[i].b]=1;
    for(int i=0;i<=100000;i++)if(ebahti[i]==1)sum++;
    cout<<sum<<endl;
    return 0;
}
