//algo za namirane na artikulacionni to4ki i rebra
#include<iostream>
#include<vector>
using namespace std;
int v[1001][1001];
vector<int> tochki;
vector<pair<int,int> > most;
int lowest[1001],prenum[1001],used[1001],br,pred[1001];
int m,n;
void read()
{
    cin>>n>>m;
    int a,b;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        v[a][b]=v[b][a]=1;
    }
}
void dfs(int i)
{
    used[i]=1;
    prenum[i]=lowest[i]=++br;
    for(int j=1;j<=n;j++)
    {
        if(!used[j]&&v[i][j])
        {
            v[i][j]=2;
            pred[j]=i;
            dfs(j);
        }
        if(v[i][j]==2)lowest[i]=min(lowest[i],lowest[j]);
        else if(v[i][j]==1&&pred[i]!=j)lowest[i]=min(lowest[i],prenum[j]);
    }
}
void solve()
{
    pair<int,int> l;
    br=0;
    for(int j=1;j<=n;j++)
    {
        if(v[1][j]==2)br++;
    }
    if(br>1)tochki.push_back(1);
    br=0;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(v[i][j]==2&&lowest[j]>=prenum[i]){br++;break;}
        }
        if(br==1)tochki.push_back(i);
        br=0;
        if(prenum[i]==lowest[i])
        {
            l.first=i;
            l.second=pred[i];
            most.push_back(l);
        }
    }
}
void print()
{
    int k=most.size();
    for(int i=0;i<k;i++)cout<<most[i].first<<" "<<most[i].second<<endl;
    k=tochki.size();
    for(int i=0;i<k;i++)cout<<tochki[i]<<endl;
}
int main()
{
    read();
    pred[1]=-1;
    dfs(1);
    solve();
    print();
}
