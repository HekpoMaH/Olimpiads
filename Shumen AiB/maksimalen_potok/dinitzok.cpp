#include<bits/stdc++.h>
using namespace std;
int cap[20009];
int to[20009];
int last[20009];
int nxt[20009];
int source,sink,n,m;
int num;
int flow_d[509];
void add_edge(int x,int y,int c)
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
int bfs()
{
    int i,j,sz;
    static int q[509];
    memset(flow_d,-1,sizeof(flow_d));
    q[sz=0]=sink;
    flow_d[sink]=0;
    for(i=0;i<=sz;i++)
    {
        for(j=last[q[i]];j>0;j=nxt[j])
        {
            if(flow_d[to[j]]==-1&&cap[j^1])
            {
                flow_d[to[j]]=flow_d[q[i]]+1;
                q[++sz]=to[j];
            }
        }
    }
    return flow_d[source]!=-1;
}
int dfs(int x,int flow)
{
    //cout<<x<<" flow= "<<flow<<" "<<last[x]<<" "<<nxt[last[x]]<<endl;
    //exit(0);
    if(x==sink){return flow;}
    int i;
    //cout<<"i="<<last[x]<<endl;
    for(i=last[x];i>0;i=nxt[i])
    {
        if(cap[i]&&flow_d[to[i]]+1==flow_d[x])
        {
            //cout<<"going to "<<to[i]<<" with capacity "<<cap[i]<<" and the flow is "<<min(flow,cap[i])<<endl;
            //exit(0);
            int y=dfs(to[i],min(flow,cap[i]));
            if(y!=-1)
            {
                //cout<<"Y here ="<<y<<endl;
                cap[i]-=y;
                cap[i^1]+=y;
                return y;
            }
        }
        
    }
    //cout<<"returned\n";
    flow_d[x]=-5;
    return -1;
}
long long dinitz()
{
    long long maxflow=0,floww;
    while(bfs())
    {
        floww=dfs(source,(1<<30));
        while( floww!=-1)maxflow+=floww,floww=dfs(source,(1<<30));
        //for(int i=1;i<=n;i++)if(flow_d[i]==-5){cout<<"EEE"<<endl;exit(0);}
    }
    return maxflow;
}
void input()
{
    cin>>n>>m;
    int xx,yy,zz;
    for(int i=1;i<=m;i++)
    {
        cin>>xx>>yy>>zz;
        add_edge(xx,yy,zz);
    }
    source=1;sink=n;
    //cin>>source>>sink;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0);
    memset(last,0,sizeof(last));
    num=2;
    input();
    cout<<dinitz()<<endl;
}
/*
7 8
1 2 2
1 3 1
2 4 3
3 4 5
3 5 4
4 7 2
5 6 2
6 7 3

4 5
1 2 4
1 3 3
2 3 3
2 4 4
3 4 5

6 8
1 2 5
1 3 15
2 4 5
2 5 5
3 4 5
3 5 5
4 6 15
5 6 5
*/
