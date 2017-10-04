#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int g[1005][1005];
int ra[1005],rb[1005];
int n,a,m,b;
void bfs1(int st)
{
    memset(ra,0,sizeof(ra));
    queue<int> q;
    q.push(st);
    ra[st]=1;int cur;
    while(!q.empty())
    {
        cur=q.front();q.pop();
        for(int i=1;i<=g[cur][0];i++)
        {
            if(ra[g[cur][i]]==0)ra[g[cur][i]]=ra[cur]+1,q.push(g[cur][i]);
        }
    }
}
void bfs2(int st)
{
    memset(rb,0,sizeof(rb));
    queue<int> q;
    q.push(st);
    rb[st]=1;int cur;
    while(!q.empty())
    {
        cur=q.front();q.pop();
        for(int i=1;i<=g[cur][0];i++)
        {
            if(rb[g[cur][i]]==0)rb[g[cur][i]]=rb[cur]+1,q.push(g[cur][i]);
        }
    }
}
void solve()
{
    bfs1(a);bfs2(b);
    int br=0;
    for(int i=1;i<=n;i++)
    {
        //cout<<i<<" "<<ra[i]<<" "<<rb[i]<<" "<<ra[b]<<endl;
        if(ra[i]+rb[i]-2!=ra[b]-1)br++;
    }
    cout<<br<<" ";
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>a>>b;
        g[a][0]++;g[a][g[a][0]]=b;
        g[b][0]++;g[b][g[b][0]]=a;
    }
    cin>>a>>b;
    solve();
    cin>>a>>b;
    solve();cout<<endl;
    return 0;
}
