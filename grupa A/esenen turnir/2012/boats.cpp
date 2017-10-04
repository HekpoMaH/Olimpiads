#include<bits/stdc++.h>
using namespace std;
int e[1009][1009],pairs[10009][3],d[1009],pi[1009],depth[1009];
bool marked[1009];
int n,m,k,w;
void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int u,v,w;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v>>w;
        e[u][v]=e[v][u]=w;
    }
    for(int i=1;i<=k;i++)cin>>pairs[i][1]>>pairs[i][2];
}
void createmst(int s)
{
    int u,v,w,cnt;
    for(int i=1;i<=n;i++)
    {
        d[i]=0;pi[i]=-1;
        marked[i]=false;depth[i]=false;
    }
    d[s]=INT_MAX;cnt=1;
    while(cnt<=n)
    {
        w=0;u=0;
        for(int i=1;i<=n;i++)if(d[i]>w&&!marked[i])w=d[i],u=i;
        marked[u]=true;
        for(int v=1;v<=n;v++)if(d[v]<e[u][v]&&!marked[v])d[v]=e[u][v],pi[v]=u,depth[v]=depth[u]+1;
        cnt++;
    }
}
int wp(int u,int v)
{
    int w;
    w=INT_MAX;
    while(depth[u]>depth[v])
    {
        if(d[u]<w)w=d[u];
        u=pi[u];
    }
    while(depth[v]>depth[u])
    {
        if(d[v]<w)w=d[v];
        v=pi[v];
    }
    while(v!=u)
    {
        if(d[v]<w)w=d[v];
        if(d[u]<w)w=d[u];
        u=pi[u];
        v=pi[v];
    }
    return w;
}
void solve()
{
    int w,u,v;
    for(int i=1;i<=k;i++)
    {
        u=pairs[i][1];
        v=pairs[i][2];
        cout<<wp(u,v)<<endl;
    }
}
int main()
{
    input();
    createmst(1);
    solve();
}
