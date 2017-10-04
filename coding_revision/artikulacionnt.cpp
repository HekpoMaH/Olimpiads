#include<iostream>
#include<vector>
#include<set>
using namespace std;
int v[1000][1000];
vector<pair<int,int> > most;
vector<int> to4ki;
int lowest[1001],prenum[1001],used[1001],pred[1001],brc,br;
int n,m;
void read()
{
    cin>>n>>m;
    int a,b;
    for(int i=1;i<=m;i++)
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
        if(v[i][j]==2)
        {
            lowest[i]=min(lowest[i],lowest[j]);
        }
        else if(v[i][j]==1&&pred[i]!=j)lowest[i]=min(lowest[i],prenum[j]);
    }
}
void crtm()
{
    pair<int,int> l;
    br=0;
    for(int j=1;j<=n;j++)
    {
        if(v[1][j]==2)br++;
    }
    if(br>1)to4ki.push_back(1);
    br=0;
    for(int i=2;i<=n;i++)
    {
        //cout<<i<<" ";
        for(int j=1;j<=n;j++)
        {
            if(v[i][j]==2&&lowest[j]>=prenum[i]){br++;break;}
        }
        if(br>=1)to4ki.push_back(i);
        cout<<br<<endl;
        br=0;
        if(lowest[i]==prenum[i])
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
    //cout<<k<<endl;
    for(int i=0;i<k;i++)cout<<most[i].first<<" "<<most[i].second<<endl;
    k=to4ki.size();
    for(int i=0;i<k;i++)cout<<to4ki[i]<<endl;
}
int main()
{
    read();
    pred[1]=-1;
    dfs(1);
    crtm();
    print();
}

