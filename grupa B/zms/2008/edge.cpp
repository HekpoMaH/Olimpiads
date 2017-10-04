#include<bits/stdc++.h>
using namespace std;
vector<int>v[10009];
vector<pair<int,int> >most;
int lowest[10009],prenum[10009],used[10009],br,pred[10009],br2;
int n,m;
void read()
{
    cin>>n>>m;
    int a,b;
    for(int i=1;i<=m;i++)
    {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
}
void dfs(int node)
{
    //cout<<"node="<<node<<endl;
    used[node]=1;
    prenum[node]=lowest[node]=++br;
    for(int j=0;j<v[node].size();j++)
    {
        if(!prenum[v[node][j]])
        {
            pred[v[node][j]]=node;
            dfs(v[node][j]);
            lowest[node]=min(lowest[node],lowest[v[node][j]]);
        }
        else if(pred[node]!=v[node][j])lowest[node]=min(lowest[node],prenum[v[node][j]]);
    }
    if(lowest[node]==prenum[node]&&pred[node]!=-1)br2++;
}
void solve()
{
    cout<<br2<<endl;
}
int main()
{
    read();
    br2=0;
    //pred[1]=-1;
    for(int i=1;i<=n;i++)if(used[i]==0){pred[i]=-1;dfs(i);}
    solve();
}
