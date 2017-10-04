#include<cstdio>
#include<vector>
using namespace std;
int n;
int k;
vector<int> v[1000000],ans;
int used[1000000];
void dfs(int node,int ttontt)
{
    used[node]=1;
    if(ttontt==1)ans.push_back(node);
    for(int i=0;i<v[node].size();i++)
    {
        if(used[v[node][i]]==0)
        {
            dfs(v[node][i],ttontt^1);
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    scanf("%d",&k);
    for(int i=1;i<=n;i++)if(used[i]==0)dfs(i,1);
    if(ans.size()<k)printf("0\n");
    else for(int i=0;i<k;i++)printf("%d ",ans[i]);
    printf("\n");
}
