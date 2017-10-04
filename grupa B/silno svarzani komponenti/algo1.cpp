#include<iostream>
#include<cstring>
using namespace std;
int n,m;
int a[100][100];
int used[100];
int prenum[100],br,mx,mxv;
void dfs(int node)
{
    used[node]=1;
    for(int i=1;i<=n;i++)
    {
        if(a[node][i]==1&&used[i]==0)dfs(i);
    }
    prenum[node]=++br;
}
void bdfs(int node)
{
    cout<<node<<" ";
    used[node]=1;
    for(int i=1;i<=n;i++)
    {
        if(a[i][node]==1&&used[i]==0)bdfs(i);
    }
    ++br;
}
int main()
{
    cin>>n>>m;
    int x,y;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y;
        a[x][y]=1;
    }
    for(int i=1;i<=n;i++)
    {
        if(used[i]==0)dfs(i);
    }
    br=0;
    int br2=0;
    memset(used,0,sizeof(used));
    while(br<n)
    {
        br2++;
        mx=0;
        for(int i=1;i<=n;i++)if(used[i]==0&&prenum[i]>mx)mx=prenum[i],mxv=i;
        bdfs(mxv);
        cout<<endl;
    }
    cout<<br2<<endl;
}
/*
12 19
1 2
2 3
2 4
2 5
3 6
4 5
5 2
5 6
5 7
6 8
6 3
7 8
7 10
8 7
9 7
10 9
10 11
11 12
12 10
*/
