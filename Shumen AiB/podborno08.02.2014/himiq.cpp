#include<bits/stdc++.h>
using namespace std;
int cap[25000];
int to[25000];
int last[2509];
int nxt[25000],flowd[2509];
string a[59];
int source,sink,n,m,num,sum;
void addedge(int x,int y,int c)
{
    //if(num>=25000||num+1>=25000){cout<<"ERR"<<endl;exit(0);}
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
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    source=n*m+1;sink=n*m+2;
    int br=0;
    map<char,int> val;
    val['H']=1;
    val['O']=2;
    val['N']=3;
    val['C']=4;
    val['.']=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(i%2==1)br=0;
        else br=1;
        for(int j=0;j<a[i].size();j++)
        {
            br++;
            sum+=val[a[i][j]];
            if(a[i][j]=='.')continue;
            if(br%2==1)
            {
                addedge(source,(i-1)*m+j+1,val[a[i][j]]);
                //cout<<"adding edge "<<source<<" "<<(i-1)*m+j+1<<" capacity="<<val[a[i][j]]<<endl;
            }
            if(br%2==0)
            {
                //cout<<"adding edge "<<(i-1)*m+j+1<<" "<<sink<<" capacity="<<val[a[i][j]]<<endl;
                addedge((i-1)*m+j+1,sink,val[a[i][j]]);
            }
            if(i>1)
            {

                if(a[i][j]!='.'&&a[i-1][j]!='.')addedge((i-1)*m+j+1,(i-2)*m+j+1,1);//,cout<<"adding edge "<<(i-1)*m+j+1<<" "<<(i-2)*m+j+1<<endl;
            }
            if(i<n)
            {

                if(a[i][j]!='.'&&a[i+1][j]!='.')addedge((i-1)*m+j+1,i*m+j+1,1);//,cout<<"adding edge "<<(i-1)*m+j+1<<" "<<i*m+j+1<<endl;
            }
            if(j>0)
            {

                if(a[i][j]!='.'&&a[i][j-1]!='.')addedge((i-1)*m+j+1,(i-1)*m+j,1);//,cout<<"adding edge "<<(i-1)*m+j+1<<" "<<(i-1)*m+j<<endl;
            }
            if(j<m-1)
            {

                if(a[i][j]!='.'&&a[i][j+1]!='.')addedge((i-1)*m+j+1,(i-1)*m+j+2,1);//,cout<<"adding edge "<<(i-1)*m+j+1<<" "<<(i-1)*m+j+2<<endl;
            }
        }
    }
}
int bfs()
{
    int sz;
    static int q[2509];
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
    flowd[x]=-5;
    return -1;
}
long long dinitz()
{
    long long mxflow=0,floww;
    while(bfs())
    {
        floww=dfs(source,(1<<30));//cout<<"flow="<<floww<<endl;
        while(floww!=-1)mxflow+=floww,floww=dfs(source,(1<<30));//,cout<<"flow="<<floww<<endl;
    }
    return mxflow;
}
void solve()
{
    //if(sum==0)cout<<"Invalid\n";
    long long flowa=dinitz();//cout<<"sum="<<sum<<" flowa="<<flowa<<endl;
    if(flowa*2==sum&&flowa!=0)cout<<"Valid\n";
    else cout<<"Invalid\n";
}
int main()
{
    num=2;
    read();
    //for(int i=2;i<=num;i++)cout<<to[i]<<" "<<cap[i]<<endl;
    solve();
}
