#include<bits/stdc++.h>
using namespace std;
int a[100][100],flow[100][100];
int n,m;
int x,y,z,used[100];
bool fl=true;
vector<int> v;
void dfs(int node)
{
    v.push_back(node);
    used[node]=1;
    if(node==n)
    {
        cout<<"found path:"<<" ";
        fl=true;
        int mxf=999999;
        cout<<v[0]<<" ";
        for(int i=1;i<v.size();i++)
        {
            mxf=min(mxf,a[v[i-1]][v[i]]);
            cout<<v[i]<<" ";
        }
        cout<<endl;
        for(int i=1;i<v.size();i++)
        {
            a[v[i-1]][v[i]]-=mxf;
            a[v[i]][v[i-1]]+=mxf;
            flow[v[i-1]][v[i]]+=mxf;
            flow[v[i]][v[i-1]]-=mxf;
        }
    }
    if(fl==true)return;

    for(int i=1;i<=n;i++)
    {
        if(a[node][i]>0&&used[i]==0)
        {
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
        cin>>x>>y>>z;
        a[x][y]=z;
    }
    while(fl)
    {
        memset(used,0,sizeof(used));
        v.clear();
        fl=false;
        dfs(1);
    }
    int potok=0;
    for(int i=1;i<=n;i++)potok+=flow[i][n];
    cout<<potok<<endl;
}
/*
6 10
1 2 16
1 3 13
2 3 10
3 2 4
2 4 12
3 5 14
4 3 9
5 4 7
4 6 20
5 6 4
*/
