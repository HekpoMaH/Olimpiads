#include<iostream>
#include<cstring>
using namespace std;
int n,m;
int a[100][100];
int used[100];
int prenum[100],br,mx,mxv;
void dfs(int node)
{
    used[node]=1;
    for(int i=1;i<=n;i++)
    {
        if(a[node][i]&&used[i]==0)dfs(i);
    }
    prenum[node]=++br;
}
void bdfs(int node)
{
    used[node]=1;
    cout<<node<<" ";
    for(int i=1;i<=n;i++)
    {
        if(a[i][node]&&used[i]==0)bdfs(i);
    }
    ++br;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        a[x][y]=1;
    }
    br=0;
    while(br<n)
    {
        for(int i=1;i<=n;i++)
        {
            if(used[i]==0)dfs(i);
        }
    }
    br=0;
    memset(used,0,sizeof(used));
    while(br<n)
    {
        mx=0;
        for(int i=1;i<=n;i++)
        {
            if(prenum[i]>mx&&used[i]==0)mx=prenum[i],mxv=i;
        }
        bdfs(mxv);
        cout<<endl;
    }
}
