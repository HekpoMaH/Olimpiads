#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
vector<int> v[1009];
int used[1009];
int s[1009];
int n,m;
void read()
{
    cin>>n>>m;
    int p;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>p;
            if(p==1)
            {
                v[i].push_back(n+j);v[n+j].push_back(i);
            }
        }
    }
}
bool dfs(int node)
{
    if(s[node]==0)return true;
    used[node]=1;
    int p;
    if(s[node]!=0&&used[s[node]]==0)
    {
        p=dfs(s[node]);return p;
    }
    for(int i=0;i<v[node].size();i++)
    {
        if(used[v[node][i]]==0)
        {
            p=dfs(v[node][i]);
            if(p==true)
            {
                s[v[node][i]]=node;s[node]=v[node][i];
                return p;
            }
        }
    }
    return 0;
}

int main()
{
    read();
    int br=0;
    for(int i=1;i<=n;i++)
    {
        s[i]=i;
        if(dfs(i)==true)
        {
            br++;
        }
        else s[i]=0;
        memset(used,0,sizeof(used));
    }
    cout<<br<<endl;
}
