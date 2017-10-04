#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
vector<int> v;
int f[100][100];
int cap[100][100];
int n,m,l=1;
int used[100],sum;
int mn=99999;
void dfs(int st)
{
    if(st==n)
    {
        l=1;
        mn=99999;
        for(int i=0;i<v.size()-1;i++)mn=min(mn,cap[v[i]][v[i+1]]);
        for(int i=0;i<v.size()-1;i++)
        {
            f[v[i]][v[i+1]]+=mn;
            f[v[i+1]][v[i]]-=mn;
            cap[v[i]][v[i+1]]-=mn;
            cap[v[i+1]][v[i]]+=mn;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(cap[st][i]>0&&used[i]==0)
        {
            v.push_back(i);
            used[i]=1;
            dfs(i);
            used[i]=0;
            v.pop_back();
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        cap[x][y]=z;
    }
    while(l)
    {
        memset(used,0,sizeof(used));
        v.clear();
        used[1]=1;
        l=0;
        v.push_back(1);
        dfs(1);
    }
    for(int i=1;i<=n;i++)
    {
        sum+=f[i][n];
    }
    cout<<sum<<endl;
}
