#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool a[20009][20009];
int n,m,br;
vector<int> ans;
bool used[20009];
void dfs(int nd)
{
    br++;
    used[nd]=true;
    for(int i=1;i<=n;i++)if(a[nd][i]==true&&used[i]==false)dfs(i);
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        a[x][y]=a[y][x]=true;
    }
    for(int i=1;i<=n;i++)
    {
        if(used[i]==false)
        {
            br=0;
            dfs(i);
            ans.push_back(br);
        }
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(int i=1;i<=ans.size();i++)cout<<ans[i-1]<<" ";cout<<endl;
}
