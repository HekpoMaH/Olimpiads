#include<iostream>
using namespace std;
int n,m;
int used[100],a[100][100],x,y,z;
void dfs(int node)
{
    int l=1;
    for(int i=1;i<=n;i++)
    {
        if(used[i]==0&&a[node][i]!=0)
        {
            l=0;
            dfs(i);
            used[node]=max(used[node],used[i]+a[node][i]);
        }
        if(used[i]==1)
            {
                l=0;
                used[node]=max(used[node],used[i]+a[node][i]);
            }
    }
    if(l)used[node]=1;
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
         cout<<used[i]-1<<" ";
    }
    cout<<endl;
    return 0;
}