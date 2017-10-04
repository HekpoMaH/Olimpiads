#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<int> v[50009];
int ans=0,bans=99999;
int used[50009];
int a[50009],ansa[50009];
int bfs(int node)
{
    queue<int> q;
    q.push(node);
    used[node]=1;
    while(!q.empty())
    {
        int fr=q.front();
        q.pop();
        for(int i=0;i<v[fr].size();i++)
        {
            if(used[v[fr][i]]==0)
            {
                used[v[fr][i]]=used[fr]+1;
                q.push(v[fr][i]);
            }
        }
    }
    int dis=0;
    for(int i=1;i<=k;i++)
    {
        if(used[a[i]]-1>dis)dis=used[a[i]]-1;
    }
    ans=max(ans,dis);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    for(int i=1;i<=n;i++)a[i]=i;
    do
    {
        ans=0;
    for(int i=1;i<=n;i++)
    {
        memset(used,0,sizeof(used));
        bfs(i);
    }
    if(ans<bans)
    {
        bans=ans;
        for(int i=1;i<=k;i++)ansa[i]=a[i];
    }
    }while(next_permutation(a+1,a+n+1));
    cout<<bans<<endl;
    for(int i=1;i<=k;i++)cout<<ansa[i]<<" ";
    cout<<endl;
    return 0;
}
