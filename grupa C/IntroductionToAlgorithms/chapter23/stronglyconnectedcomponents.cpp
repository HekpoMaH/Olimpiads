#include<iostream>
using namespace std;
int postnum[100],used[100],n,m,tab[100][100],x,y,count;
void dfs(int v)
{
    used[v]=1;
    postnum[v]=count;
    count++;
    for(int i=1;i<=n;i++)if(tab[v][i]==1&&used[i]==0)dfs(i);
}
void backdfs(int v)
{
    used[v]=1;
    cout<<v<<" ";
    count++;
    for(int i=1;i<=n;i++)if(tab[i][v]==1&&used[i]==0)backdfs(i);
}
void solve()
{
    count=0;
    for(int i=1;i<=n;i++)used[i]=0;
    for(int i=1;i<=n;i++)if(used[i]==0)dfs(i);
    for(int i=1;i<=n;i++)used[i]=0;
    count=0;
    int mn=n+1,mnv=-1;
    while(count<n)
    {
        mn=n+1;mnv=-1;
        for(int i=1;i<=n;i++)if(used[i]==0&&postnum[i]<mn){mn=postnum[i];mnv=i;}
        //cout<<mn<<endl;
        cout<<"{";backdfs(mnv);cout<<"}"<<endl;
    }
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        tab[x][y]=1;
    }
    solve();
    return 0;
}
//10 12 1 2 2 3 2 4 3 1 4 5 4 7 5 6 6 3 7 8 8 9 9 10 10 7
