#include<bits/stdc++.h>
#define inf 99999999
using namespace std;
int cap[2*300*302+300];
int to[2*300*302+300];
int last[609],flowd[609];
int nxt[2*300*302+300];
int tablica[309][309],n,m,num=2,source,sink;
vector<int> path;
void read()
{
    cin>>n>>m;
    char st[55];int x,y;
    while(cin>>x>>y)
    {
        tablica[x][y]=1;
        //cout<<tablica[x][y]<<" "<<x<<" "<<y<<"ee\n";
    }
    //cout<<tablica[0][0]<<" "<<tablica[1][1]<<"RR\n";
}
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
    source=n+m+1;sink=n+m+2;
    for(int i=1;i<=n;i++)addedge(n+m+1,i,1);//,cout<<n+m+1<<" "<<i<<endl;
    //cout<<last[source]<<endl;
    for(int i=1;i<=m;i++)addedge(n+i,n+m+2,1);
    for(int i=0;i<n;i++)
    {
        //cout<<last[source]<<" "<<i<<" "<<num<<endl;
        for(int j=0;j<m;j++)
        {
            if(tablica[i][j]==0)addedge(i+1,n+j+1,1);//if(i+1==90001||n+j+1==90001)cout<<"EEE"<<endl;}
        }
    }
    //cout<<last[source]<<endl;
}
int bfs()
{
    int sz;
    static int q[309];
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
    return flowd[source]!=-1;
}
int dfs(int x,int flow)
{
    //path.push_back(x);
    //cout<<"x="<<x<<" last[x]="<<last[x]<<" "<<sink<<" "<<source<<"\n";
    if(x==sink){return flow;}
    //cout<<"aaaa"<<last[x]<<endl;
    for(int i=last[x];i>0;i=nxt[i])
    {
        if(cap[i]&&flowd[to[i]]+1==flowd[x])
        {
            //cout<<"going to - "<<to[i]<<" capacity - "<<cap[i]<<"\n";

            int y=dfs(to[i],min(flow,cap[i]));
            //path.pop_back();
            if(y!=-1)
            {
                cap[i]-=y;
                cap[i^1]+=y;
                return y;
            }
        }
    }
    flowd[x]=-11;
    //cout<<"returned"<<"\n";
    return -1;
}
int dinitz()
{
    int mxflow=0,floww;
    while(bfs())
    {
        floww=dfs(source,inf);//cout<<"floww="<<floww<<endl;
        while(floww!=-1)mxflow+=floww,floww=dfs(source,inf);//,cout<<"floww="<<floww<<endl;;
    }
    return mxflow;
}
int main()
{
    read();
    makegraph();

    cout<<dinitz()<<endl;

}
