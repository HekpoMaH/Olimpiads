#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100][100];
int flow[100][100];
bool fl=true;
int pred[100],used[100];
queue<int> q;
void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    int x,y,z;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y>>z;
        a[x][y]=z;
    }
    //cout<<"end"<<endl;
}
void bfs()
{
    while(!q.empty())q.pop();
    //memset(used,0,sizeof(used));
    q.push(1);
    used[1]=1;
    int fr;
    pred[1]=-1;
    while(!q.empty())
    {
        fr=q.front();
        q.pop();
        for(int i=1;i<=n;i++)
        {
            if(used[i]==0&&a[fr][i]>0)
            {
                //cout<<a[fr][i]<<endl;
                used[i]=1;
                q.push(i);
                pred[i]=fr;
            }
        }
    }
    //cout<<"used="<<used[n]<<endl;
    if(used[n]==1)fl=true;
}
void maxflow()
{
    int i;
    int mxflow=0;
    while(fl)
    {
        fl=false;
        memset(used,0,sizeof(used));
        bfs();
        if(fl==false)break;
        int mnf=999999;
        for(i=n;i!=-1;i=pred[i])
        {
            mnf=min(mnf,a[pred[i]][i]);
        }
        for(i=n;i!=-1;i=pred[i])
        {
            flow[pred[i]][i]+=mnf;
            flow[i][pred[i]]-=mnf;
            a[pred[i]][i]-=mnf;
            a[i][pred[i]]+=mnf;
        }
        mxflow+=mnf;
    }
    cout<<mxflow<<endl;
}
int main()
{
    input();
    maxflow();
}
