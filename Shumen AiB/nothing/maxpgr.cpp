#include<iostream>
using namespace std;
int n,m;
int x,y,z;
int a[100][100],used[100];
void dfs(int p)
{
    int l=0;
    for(int i=1;i<=n;i++)
    {
        if(used[i]==0&&a[p][i]!=0)
        {
            l=1;
            dfs(i);
            used[p]=max(used[p],used[i]+a[p][i]);
        }
        if(used[i]==1)
        {
            l=1;
            used[p]=max(used[p],used[i]+a[p][i]);
        }
    }
    if(!l)used[p]=1;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y>>z;
        a[x][y]=z;
    }
    used[1]=-1;
    dfs(1);
    for(int i=1;i<=n;i++)
    {
        cout<<used[i]-1<<endl;
    }
    return 0;
}