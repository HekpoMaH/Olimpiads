#include<bits/stdc++.h>
using namespace std;
vector<int>g[1009];
int mt[1009];
int used[1009],n1,n2,m;
int used1[100];
void read()
{
    cin>>n1>>n2>>m;
    int i,x,y;
    for(i=1;i<=m;i++)
    {
        cin>>x>>y;
        g[x].push_back(n1+y);
        g[n1+y].push_back(x);
    }
}
void greedy()
{
    int i,j;
    //memset(used1,0,sizeof(used1));
    for(i=1;i<=n1;i++)
    {
        for(j=0;j<g[i].size();j++)
        {
            if(mt[g[i][j]]==-1)
            {
                mt[g[i][j]]=i;
                used1[i]=1;
                //cout<<"ET"<<endl;
                break;
            }
        }
    }
}
bool kuhn(int v)
{
    if(used[v])return false;
    used[v]=true;
    int i,gto;
    for(i=0;i<g[v].size();i++)
    {
        gto=g[v][i];
        if(mt[gto]==-1||kuhn(mt[gto]))
        {
            mt[gto]=v;
            return true;
        }
    }
    return false;
}
void solve()
{
    int i=1;
    bool tc;
    for(i=1;i<=n1;i++)
    {
        if(used1[i]==1)continue;
        memset(used,0,sizeof(used));
        tc=kuhn(i);
    }
    int br=0;
    for(i=1;i<=n2;i++)
    {
        if(mt[i+n1]!=-1)
        cout<<mt[i+n1]<<" "<<i<<endl,br++;
    }
    cout<<"SIZE "<<br<<endl;
}
int main()
{
    memset(mt,-1,sizeof(mt));
    read();
    greedy();
    solve();
}
