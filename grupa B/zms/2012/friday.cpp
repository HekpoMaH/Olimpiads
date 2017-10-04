#include<bits/stdc++.h>
#define max 52
#define Mask 4096
#define inf 999666333
using namespace std;
FILE* in; FILE* out;
struct edge
{
    int to,price;
    edge(int initto=0,int initprice=0){to=initto;price=initprice;}
    bool operator < (const edge &r)const
    {
        return price!=r.price ? price> r.price :to<r.to;
    }
};
int n,m;
vector <edge> v[max][13];
int dyn[max][13][Mask];
int recurse(int node,int rem,int mask)
{
    if(node==n)return 0;
    if(dyn[node][rem][mask]!=-1)return dyn[node][rem][mask];
    int ans=inf;
    for(int i=1;i<13;i++)if(!(mask&(1<<(i-1))))
    {
        int idx=(i-rem+13)%13;
        for(int c=0;c<v[node][idx].size();c++)
        {
            ans=min(ans,recurse(v[node][idx][c].to,i,mask|(1<<(i-1)))+v[node][idx][c].price);
        }
    }
    return dyn[node][rem][mask]=ans;
}
int dijkstra(int startnode,int endnode)
{
    static int dist[max];
    memset(dist,111,sizeof(dist));
    edge cur,nxt;
    priority_queue<edge> q;
    nxt.to=startnode;nxt.price=0;
    q.push(nxt);dist[nxt.to]=nxt.price;
    while(!q.empty())
    {
        cur=q.top();q.pop();
        if(dist[cur.to]==-1)continue;
        if(cur.to==endnode)return dist[cur.to];
        dist[cur.to]=-1;
        for(int i=0;i<13;i++)
        {
            for(int c=0;c<v[cur.to][i].size();c++)
            {
                nxt.to=v[cur.to][i][c].to;
                nxt.price=v[cur.to][i][c].price+cur.price;
                if(nxt.price<dist[nxt.to])
                {
                    dist[nxt.to]=nxt.price;
                    q.push(nxt);
                }
            }
        }
    }
    return inf;
}
int main()
{
    in=stdin;out=stdout;
    int ntests;
    fscanf(in,"%d",&ntests);
    for(int test=0;test<ntests;test++)
    {
        fscanf(in,"%d %d",&n,&m);
        for(int i=0;i<max;i++)
        {
            for(int c=0;c<13;c++)v[i][c].clear();
        }
        for(int i=0;i<m;i++)
        {
            int from,to,price;
            fscanf(in,"%d %d %d",&from,&to,&price);
            v[from][price%13].push_back(edge(to,price));
        }
        char type[16];
        fscanf(in, "%s",&type);
        int ans;
        if(type[0]=='T')
        {
            memset(dyn,-1,sizeof(dyn));
            ans=recurse(1,0,0);
        }
        else ans=dijkstra(1,n);
        fprintf(out,"%d\n",ans>=inf? -1:ans);
    }
}
