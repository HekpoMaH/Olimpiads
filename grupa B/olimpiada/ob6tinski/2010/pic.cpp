#include<bits/stdc++.h>
using namespace std;
int n,m;
int used[109][109];
int brostr;
int a[109][109];
void dfs(int x,int y)
{
    used[x][y]=1;
    if(x-1>=1&&a[x-1][y]==1&&used[x-1][y]==0)dfs(x-1,y);
    if(x+1<=n&&a[x+1][y]==1&&used[x+1][y]==0)dfs(x+1,y);
    if(y-1>=1&&a[x][y-1]==1&&used[x][y-1]==0)dfs(x,y-1);
    if(y+1<=m&&a[x][y+1]==1&&used[x][y+1]==0)dfs(x,y+1);
    if(x-1>=1&&y-1>=1&&a[x-1][y-1]==1&&used[x-1][y-1]==0)dfs(x-1,y-1);
    if(x+1<=n&&y+1<=m&&a[x+1][y+1]==1&&used[x+1][y+1]==0)dfs(x+1,y+1);
    if(x-1>=1&&y+1<=m&&a[x-1][y+1]==1&&used[x-1][y+1]==0)dfs(x-1,y+1);
    if(x+1<=n&&y-1>=1&&a[x+1][y-1]==1&&used[x+1][y-1]==0)dfs(x+1,y-1);
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>a[i][j];
    for(int i=1;i<=m;i++)
    {
        if(used[1][i]==0&&a[1][i]==1)dfs(1,i);
        if(used[n][i]==0&&a[n][i]==1)dfs(n,i);
    }
    for(int i=1;i<=n;i++)
    {
        if(used[i][1]==0&&a[i][1]==1)dfs(i,1);
        if(used[i][m]==0&&a[i][m]==1)dfs(i,m);
    }
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)if(used[i][j]==0&&a[i][j]==1)brostr++,dfs(i,j);
    cout<<brostr<<endl;
}
