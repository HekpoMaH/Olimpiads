#include<bits/stdc++.h>
using namespace std;
int n,m,root[100009],level[100009],h,dist[100009],used[100009],l,sq,pf[100009];
struct edge
{
    int e,dis;
};
vector<edge> v[100009];
void read()
{
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        edge p;
        p.e=b;
        p.dis=c;
        v[a].push_back(p);
        p.e=a;
        p.dis=c;
        v[b].push_back(p);
    }
    cin>>m;
}
void dfs_fill(int i)
{
    used[i]=1;
    level[i]=l;
    if(l>h)h=l;
    for(int j=0;j<v[i].size();j++)
    {
        if(!used[v[i][j].e])
        {
            l++,dist[v[i][j].e]=dist[i]+v[i][j].dis;
            root[v[i][j].e]=i;
            dfs_fill(v[i][j].e);
            l--;
        }
    }
}
void dfs_par(int i)
{
    used[i]=1;
    if(level[i]<sq)pf[i]=0;
    if(level[i]%sq==0)pf[i]=root[i];
    else pf[i]=pf[root[i]];
    for(int j=0;j<v[i].size();j++)
    {
        if(!used[v[i][j].e])
        {
            dfs_par(v[i][j].e);
        }
    }
}
int lca(int x,int y)
{
    while(pf[x]!=pf[y])
    {
        if(level[x]<level[y])y=pf[y];
        else x=pf[x];
    }
    //cout<<x<<" "<<y<<" "<<root[x]<<" "<<root[y]<<endl;
    while(x!=y)
    {
        if(level[x]<level[y])y=root[y];
        else x=root[x];
    }
    return x;
}
int qry(int a,int b)
{
    return dist[a]+dist[b]-2*dist[lca(a,b)];
}
int main()
{
    read();
    //root[1]=1;
    dfs_fill(1);

    memset(used,0,sizeof(used));
    sq=sqrt(h);
    if(sq==0)sq=1;
    dfs_par(1);//cout<<"WtF"<<endl;
    int i=0,x,y;
    for(i=0;i<m;i++)
    {
        cin>>x>>y;
        //cout<<lca(x,y)<<endl;
        cout<<qry(x,y)<<endl;
    }
}
