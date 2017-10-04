#include<bits/stdc++.h>
using namespace std;
const int maxn=30*31;
int cap[maxn];
int to[maxn];
int last[maxn];
int nxt[maxn];
int source,sink,n,m;
int num;
int flowd[maxn];
string cats[49];
void addedge(int x,int y,int c)
{
    to[num]=y;
    to[num+1]=x;
    cap[num]=c;
    cap[num+1]=0;
    nxt[num]=last[x];
    nxt[num+1]=last[y];
    last[x]=num;
    last[y]=num+1;
    num+=2;
}
void makegraph()
{
    int lowerlayer=n*m;
    source=2*n*m+1;
    sink=source+1;
    num=2;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int k1=i*m+j;
            int k2=lowerlayer+k1;
            addedge(k1,k2,1);
            if(i>0&&cats[i-1][j]=='0')addedge(k2,(i-1)*m+j,1);
            if(j>0&&cats[i][j-1]=='0')addedge(k2,i*m+j-1,1);
            if(i<n-1&&cats[i+1][j]=='0')addedge(k2,(i+1)*m+j,1);
            if(i<m-1&&cats[i][j+1]=='0')addedge(k2,i*m+j+1,1);
            if(cats[i][j]=='1')addedge(source,k1,1);
            if(i==0||j==0||i==n-1||j==m-1)addedge(k2,sink,1);
        }
    }
}
void read()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>cats[i];
        m=cats[i].size();
    }
}
int bfs()
{
    int sz;
    static int q[maxn];
    memset(flowd,-1,sizeof(flowd));
    q[sz=0]=sink;
    flowd[sink]=0;
    for(int i=0;i<=sz;i++)
    {
        for(int j=last[q[i]];j>0;j=nxt[j])
        {
            if(flowd[to[j]]==-1&&cap[j^1])
            {
                flowd[to[j]]=flowd[q[i]]+1;
                q[++sz]=to[j];
            }
        }
    }
}
int dfs(int x,int flow)
{
    if(x==sink)return flow;
    for(int i=last[x];i>0;i=nxt[i])
    {
        if(cap[i]&&flowd[to[i]]+1==flowd[x])
        {
            int y=dfs(to[i],min(flow,cap[i]));
            if(y!=-1)
            {
                cap[i]-=y;
                cap[i^1]+=y;
                return y;
            }
        }
    }
    flowd[x]=-5;
    return -1;
}
int dinitz()
{
    int mxflow=0,floww;
    while(bfs())
    {
        floww=dfs(source,(1<<30));
        while(floww!=-1)mxflow+=floww,floww=dfs(source,(1<<30));
    }
    return mxflow;
}
int main()
{
    read();
    makegraph();
    cout<<"num="<<num<<endl;
    cout<<dinitz()<<endl;
}
