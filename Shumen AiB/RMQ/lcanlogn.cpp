#include<bits/stdc++.h>
using namespace std;
int n,mm;
int v[209],brv;
int lev[109],used[109],c[109],m[209][209];
vector<int> g[109];
void read()
{
    int x,y;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        cin>>x>>y;
        g[x].push_back(y);
        //g[y].push_back(x);
    }
    cin>>mm;
}
void dfs(int node,int level)
{
    used[node]=1;
    brv++;
    v[brv]=node;
    lev[brv]=level;
    for(int i=0;i<g[node].size();i++)
    {
        if(used[g[node][i]]==0)
        {
            used[g[node][i]]=1;
            dfs(g[node][i],level+1);
            v[++brv]=node;
            lev[brv]=level;
        }
    }
}
void makec()
{
    for(int i=1;i<=brv;i++)if(c[v[i]]==0)c[v[i]]=i;
}
void makermq()
{
    for(int i=1;i<=brv;i++)m[i][0]=i;
    for(int j=1;1<<j <=brv;j++)
    {
        for(int i=1;i+(1<<j)-1<=brv;i++)
        {
            if(lev[m[i][j-1]]<lev[m[i+(1<<(j-1))][j-1]])m[i][j]=m[i][j-1];
            else m[i][j]=m[i+(1<<(j-1))][j-1];
        }
    }
}
int ans(int a,int b)
{
    int sz=b-a+1;
    int br=0;
    do
    {
        br++;
    }while((1<<br)<=sz);
    if(1<<br >sz)br--;
    if(lev[m[a][br]]<lev[m[b-(1<<br)+1][br]])return v[m[a][br]];
    return v[m[b-(1<<br)+1][br]];
}
void qryit()
{
    int x,y;
    for(int i=1;i<=mm;i++)
    {
        cin>>x>>y;
        cout<<ans(min(c[x],c[y]),max(c[x],c[y]))<<endl;
    }
}
int main()
{
    read();
    dfs(1,0);
    makec();
    makermq();
    qryit();
}
