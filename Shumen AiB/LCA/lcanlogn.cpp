#include<bits/stdc++.h>
using namespace std;
int p[1024][11],t[1024],used[1024],l[1024];
int n;
vector<int> v[1024];
void read()
{
    cin>>n;
    int x,y;
    for(int i=1;i<n;i++)
    {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
        t[y]=x;
    }
}
void dfstogetlvl(int node,int level)
{
    used[node]=1;l[node]=level;
    for(int i=0;i<v[node].size();i++)
    {
        if(used[v[node][i]]==0)dfstogetlvl(v[node][i],level+1);
    }
}
void prepr()
{
    memset(p,-1,sizeof(p));
    for(int i=1;i<=n;i++)
    {
        p[i][0]=t[i];
    }
    for(int j=1;1<<j <=n;j++)
    {
        for(int i=1;i<=n;i++)if(p[i][j-1]!=-1)p[i][j]=p[p[i][j-1]][j-1];
    }
}
int qry(int pp,int q)
{
    if(l[pp]<l[q])swap(pp,q);
    int log;
    for(log=1;1<<log <=l[pp];log++);
    log--;
    for(int i=log;i>=0;i--)
    {
        if(l[pp]-(1<<i)>=l[q])pp=p[pp][i];
    }
    if(pp==q)return pp;
    for(int i=log;i>=0;i--)
    {
        if(p[pp][i]!=-1&&p[pp][i]!=p[q][i])
        {
            pp=p[pp][i];
            q=p[q][i];
        }
    }
    return t[pp];
}
int main()
{
    read();
    prepr();
    int brq;
    cin>>brq;
    for(int i=1;i<=brq;i++)
    {
        int a,b;
        cin>>a>>b;
        cout<<qry(a,b)<<endl;
    }
}
