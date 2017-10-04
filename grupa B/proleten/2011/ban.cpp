#include<bits/stdc++.h>
using namespace std;
const int nmax=609;
const int mmax=2009;
int g[nmax][nmax],used[nmax],rib[mmax][3];
int n,m,en;
void read()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        rib[i][1]=x;rib[i][2]=y;
        g[x][y]=g[y][x]=1;
    }
}
void dfs(int node)
{
    if(used[en]==1)return;
    used[node]=1;
    for(int i=1;i<=n;i++)
    {
        if(g[node][i]&&!used[i])dfs(i);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    read();
    int br=m;
    for(int i=1;i<=m;i++)
    {
        g[rib[i][1]][rib[i][2]]=g[rib[i][2]][rib[i][1]]=0;
        memset(used,0,sizeof(used));
        en=rib[i][2];dfs(rib[i][1]);

        if(used[rib[i][2]]==1)br--;
        g[rib[i][1]][rib[i][2]]=g[rib[i][2]][rib[i][1]]=1;
    }
    cout<<br<<endl;
}
