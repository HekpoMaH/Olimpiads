#include<iostream>
#include<cstring>
#include<stack>
#include<vector>
using namespace std;
vector<int> v;
int f[100][100];
int cap[100][100];
int n,m,l=1;
int used[100],mn=9999;
void dfs(int st)
{
    if(st==n)
    {
        l=1;
        mn=9999;
        cout<<"the path is ";
        for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
        cout<<endl;
        for(int i=0;i<v.size()-1;i++)mn=min(mn,cap[v[i]][v[i+1]]);
        cout<<"found "<<mn<<endl;
        for(int i=0;i<v.size()-1;i++){f[v[i]][v[i+1]]+=mn,f[v[i+1]][v[i]]-=mn,cap[v[i]][v[i+1]]-=mn;cap[v[i+1]][v[i]]+=mn;}
    }
    for(int i=1;i<=n;i++)
    {
        //cout<<cap[st][i]<<endl;
        if(cap[st][i]>0&&used[i]==0)
        {
            cout<<"going to "<<i<<" from "<<st<<" because of cap "<<cap[st][i]<<endl;
            v.push_back(i);used[i]=1;dfs(i);v.pop_back();used[i]=0;
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;cap[x][y]=z;//cap[y][x]=-z;
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
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        sum+=f[i][n];
    }
    cout<<"the flow is "<<sum<<endl;
}
/*
4 5
1 2 4
1 4 5
1 3 1
3 4 99
2 4 2
*/
