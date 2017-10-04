#include<bits/stdc++.h>
using namespace std;
const int maxn=109;
const int inf=1e6;
const int maxfl=200*200+200;
int n,m;
int s,t;
int tab[3][maxn][maxn];
int cap[maxfl];
int to[maxfl];
int last[maxfl];
int nxt[maxfl];
int source,sink;
int num;
int flowd[200*200];
int br;
struct chastica
{
    int x,y;
    int idx;
    chastica(){}
    chastica(int _x,int _y,int _idx)
    {
        x=_x;
        y=_y;
        idx=_idx;
    }
};
vector<chastica >part[3];
bool isok(chastica fir,chastica sec)
{
    //cout<<"cheking chastici "<<fir.idx<<" "<<sec.idx<<" their d is"<<" ";
    int d=s*t-abs(fir.x-sec.x)-abs(fir.y-sec.y);//cout<<d<<"\n";
    if(d>=0&&d%2==0)return true;
    //cout<<"no edge bettween\n";
    return false;
}
void addedge(int x,int y,int c)
{
    //cerr<<"edge added between "<<x<<" "<<y<<" "<<c<<"\n";
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
void read()
{
    cin>>m>>n;
    cin>>s>>t;

    int cntr[3];
    cntr[1]=cntr[2]=0;
    for(int wt=1;wt<=2;wt++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>tab[wt][i][j];
                cntr[wt]+=tab[wt][i][j];
                for(int k=1;k<=tab[wt][i][j];k++)
                {
                    br++;
                    part[wt].push_back(chastica(i,j,br));
                }
            }
        }
    }
    //cout<<cntr[1]<<" "<<cntr[2]<<endl;
    if(cntr[1]!=cntr[2]){cout<<"N\n";exit(0);}
}
void makeg()
{
    num=2;//mn vajno
    source=0;
    sink=br+2;
    for(int i=0;i<part[1].size();i++)
    {
        addedge(source,part[1][i].idx,1);
        for(int j=0;j<part[2].size();j++)
        {
            if(isok(part[1][i],part[2][j]))
            {
                addedge(part[1][i].idx,part[2][j].idx,1);
            }
        }
    }
    for(int j=0;j<part[2].size();j++)
    {
        addedge(part[2][j].idx,sink,1);
    }
}
int bfs()
{
    int sz;
    int q[2*200*200+200];
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
    flowd[x]=-33;//very important
    return -1;
}
void dinitz()
{
    int maxflow,floww;
    while(bfs())
    {
        floww=dfs(source,(1<<30));
        while(floww!=-1)maxflow+=floww,floww=dfs(source,(1<<30));
        //cout<<"maxflow="<<maxflow<<endl;
    }
    //cout<<"da flow is"<<maxflow<<" "<<br<<endl;
    if(maxflow==br/2||maxflow==br||br==0)
    {
        cout<<"Y\n";
        return;
    }
    cout<<"N\n";
    return;
}
int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    read();
    //cout<<"Done\n";
    makeg();//cout<<"Done\n";
    dinitz();
}
