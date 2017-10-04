#include<bits/stdc++.h>
using namespace std;
int n,k;
int m[100009];
int used[100009],x,y,sum;
vector<int> v[100009];
void dfs(int node,int dep)
{
    sum+=m[node];
    used[node]=1;
    if(dep==k)return;
    for(int i=0;i<v[node].size();i++)
    {
        if(used[v[node][i]]==0)dfs(v[node][i],dep+1);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<n;i++)
    {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
    {
        cin>>m[i];
    }
    for(int i=1;i<=n;i++)
    {
        memset(used,0,sizeof(used));
        sum=0;
        dfs(i,0);
        cout<<sum<<endl;
    }
}
