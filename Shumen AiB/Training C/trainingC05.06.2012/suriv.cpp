#include<iostream>
#include<cstring>
using namespace std;
int a[2000][2000];
int n;
int boss[2000][2000],boss2[2000][2000],x,used[2000];
void dfs1(int cb,int node)
{
    if(node!=cb)boss[cb][node]=1;
    for(int i=1;i<=n;i++)
    {
        if(a[node][i]==1&&used[i]==0)
        {
            used[i]=1;
            dfs1(cb,i);
        }
    }
}
void dfs2(int cb,int node)
{
    if(node!=cb)boss2[cb][node]=1;
    for(int i=1;i<=n;i++)
    {
        if(a[node][i]==1&&used[i]==0)
        {
            used[i]=1;
            dfs2(cb,i);
        }
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        a[x][i]=1;
    }
    for(int i=1;i<=n;i++)
    {
        memset(used,0,sizeof(used));
        dfs1(i,i);
    }
    memset(a,0,sizeof(a));
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        a[x][i]=1;
    }
    for(int i=1;i<=n;i++)
    {
        memset(used,0,sizeof(used));
        dfs2(i,i);
    }
    int br=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(boss[i][j]==1&&boss2[i][j]==1)br++;
        }
    }
    cout<<br<<endl;
    return 0;
}