#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int a[2000][2000],b[2000][2000];
int n;
int used1[2000],used2[2000],x;
void bfs1(int beg)
{
    queue<int> q;
    int node;
    q.push(beg);
    used1[beg]=1;
    while(!q.empty())
    {
        node=q.front();
        q.pop();
        for(int i=1;i<=n;i++)
        {
            if(a[node][i]==1&&used1[i]==0)
            {
                used1[i]=1;
                q.push(i);
            }
        }
    }
}
void bfs2(int beg)
{
    queue<int> q;
    int node;
    q.push(beg);
    used2[beg]=1;
    while(!q.empty())
    {
        node=q.front();
        q.pop();
        for(int i=1;i<=n;i++)
        {
            if(b[node][i]==1&&used2[i]==0)
            {
                used2[i]=1;
                q.push(i);
            }
        }
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        a[x][i]=1;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        b[x][i]=1;
    }
    int br=0;
    for(int i=1;i<=n;i++)
    {
        memset(used1,0,sizeof(used1));
        memset(used2,0,sizeof(used2));
        bfs1(i);bfs2(i);
        for(int j=1;j<=n;j++)
        {
            if(used1[j]==1&&used2[j]==1&&j!=i)br++;
        }
    }
    cout<<br<<endl;
    return 0;
}