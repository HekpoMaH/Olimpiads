#include<bits/stdc++.h>
using namespace std;
const int maxn=109;
vector<int> g[maxn];
int fbid;
vector<int> ans;
int used[maxn];
void dfs(int node)
{
    used[node]=1;
    if(node==fbid)return;
    for(int i=0;i<g[node].size();i++)
    {
        if(used[g[node][i]]==0)
        {
            dfs(g[node][i]);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int cnt=0;
    int x;
    cin>>x;
    while(x!=-1)
    {
        if(x==-2)cnt++;
        if(x!=-2)
        {
            g[cnt].push_back(x);
        }
        cin>>x;
    }
    for(int i=1;i<cnt;i++)
    {
        fbid=i;
        memset(used,0,sizeof(used));
        dfs(0);
        if(used[cnt]==0)ans.push_back(i);
    }
    cout<<ans.size();
    for(int i=0;i<ans.size();i++)cout<<" "<<ans[i];cout<<"\n";
}

