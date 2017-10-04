#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct edge
{
    int a,b,t;
};
vector<edge> g,t;
edge e;
int n,m,x,y,z;
int parent[100];
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
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y>>z;
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
    for(int i=0;i<t.size();i++)sum+=t[i].t;
    cout<<sum<<endl;
    return 0;
}