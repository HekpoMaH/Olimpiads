#include<bits/stdc++.h>
#define inf 999999999
using namespace std;
int tab[59][59];
string s;
int rows,cols,n,m,num;
int idxc[59][59],idxp[59][59];
int to[2*(209*209+209)];
int cap[2*(209*209+209)];
int last[209],flowd[209];
int nxt[2*(209*209+209)],source,sink;
int icap[2*(209*209+209)];
int mid,ans=inf;
vector<pair<int,int> >ioc;
void read()
{
    int br=0;
    while(cin>>s)
    {
        br++;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='C')tab[br][i+1]=3,idxc[br][i+1]=++n,ioc.push_back(make_pair(br,i+1));
            if(s[i]=='X')tab[br][i+1]=-1;
            if(s[i]=='P')tab[br][i+1]=2,idxp[br][i+1]=++m;
            if(s[i]=='.')tab[br][i+1]=1;
        }
        cols=s.size();
    }
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
void bfsit(int x,int y)
{
    //cout<<"started"<<endl;
    pair<int,int> cr;
    queue<pair<int,int> >q;
    int used[59][59];
    memset(used,-1,sizeof(used));
    used[x][y]=0;
    q.push(make_pair(x,y));
    while(!q.empty())
    {
        cr=q.front();
        q.pop();
        //cout<<"A "<<cr.first<<" "<<cr.second<<" "<<tab[cr.first][cr.second]<<"\n";
        if(tab[cr.first][cr.second]==2)
        {

            addedge(idxc[x][y],n+idxp[cr.first][cr.second],used[cr.first][cr.second]);
        }
        if(used[cr.first-1][cr.second]==-1&&tab[cr.first-1][cr.second]>0)
        {
            used[cr.first-1][cr.second]=used[cr.first][cr.second]+1;
            q.push(make_pair(cr.first-1,cr.second));
        }
        if(used[cr.first][cr.second-1]==-1&&tab[cr.first][cr.second-1]>0)
        {
            used[cr.first][cr.second-1]=used[cr.first][cr.second]+1;
            q.push(make_pair(cr.first,cr.second-1));
        }
        if(used[cr.first+1][cr.second]==-1&&tab[cr.first+1][cr.second]>0)
        {
            used[cr.first+1][cr.second]=used[cr.first][cr.second]+1;
            q.push(make_pair(cr.first+1,cr.second));
        }
        if(used[cr.first][cr.second+1]==-1&&tab[cr.first][cr.second+1]>0)
        {
            used[cr.first][cr.second+1]=used[cr.first][cr.second]+1;
            q.push(make_pair(cr.first,cr.second+1));
        }
    }
}
void makegraph()
{
    num=2;
    memset(last,0,sizeof(last));
    for(int i=0;i<ioc.size();i++)
    {
        //cout<<"Aaaa"<<endl;
        bfsit(ioc[i].first,ioc[i].second);
    }source=n+m+1;sink=n+m+2;
    for(int i=1;i<=n;i++)addedge(n+m+1,i,1);
    for(int i=1;i<=m;i++)addedge(n+i,n+m+2,1);

}
int bfs()
{
    int i,j,sz;
    int q[300];
    memset(flowd,-1,sizeof(flowd));
    q[sz=0]=sink;
    flowd[sink]=0;
    for(i=0;i<=sz;i++)
    {
        for(j=last[q[i]];j>0;j=nxt[j])
        {
            if(flowd[to[j]]==-1&&cap[j^1]&&cap[j^1]<=mid)
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
        //cout<<"cap["<<i<<"]="<<cap[i]<<" "<<to[i]<<endl;
        if(cap[i]&&flowd[to[i]]+1==flowd[x]&&cap[i]<=mid)
        {
            int y=dfs(to[i],min(flow,cap[i]));
            //cout<<"y="<<y<<endl;
            if(y!=-1)
            {
                cap[i]-=y;
                cap[i^1]+=y;
                return y;
            }
        }
    }
    flowd[x]=-11;
    return -1;
}
int dinitz()
{
    int mxfl=0,fl;
    while(bfs())
    {
        while(fl=dfs(source,inf)!=-1)mxfl+=fl;
    }
    return mxfl;
}
int answerthatbastard()
{
    int lef=1,righ=inf,cans;
    while(lef<=righ)
    {
        mid=lef+righ;mid>>=1;
        //cout<<"DINITZ"<<endl;
        for(int i=2;i<=num;i++)
        {
            cap[i]=icap[i];
        }
        cans=dinitz();
        //cout<<lef<<" "<<righ<<" "<<mid<<" "<<cans<<endl;
        if(cans>=n)
        {
            ans=min(mid,ans);
            righ=mid-1;
        }
        else lef=mid+1;
    }
    //cout<<"ans="<<ans<<endl;
    if(ans==inf)return -1;
    return ans;
}
int main()
{
    read();
    makegraph();
    for(int i=2;i<=num;i++)
    {
        icap[i]=cap[i];
    }
    cout<<answerthatbastard()<<endl;
}
