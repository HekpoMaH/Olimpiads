#include<bits/stdc++.h>
using namespace std;
long long n,m,a[309][309],parent[309],distbtwij[309][309],br;
struct edge
{
    int a,b,t,in;
};
struct edge2
{
    int e;
    long long dis;
};
vector<edge2> rmqg[309];
vector<edge> g,t,ct;
clock_t tim;
long long mn=(long long)(100000000000000000);
int root[309],level[309],h,dist[309],used[309],l,sq,pf[309],usedtc[309];
bool cmp(edge first,edge second)
{
    if(first.t<second.t)return true;
    if(first.t>second.t)return false;
    //if(a[first.a][first.b]<a[second.a][second.b])return true;
    //if(a[first.a][first.b]<a[second.a][second.b])return false;
    if(first.a<second.a)return true;
    if(first.a>second.a)return false;
    if(first.b<second.b)return true;
    return false;
}
bool find(int p,int q)
{
    while(p!=parent[p])p=parent[p];
    while(q!=parent[q])q=parent[q];
    if(p==q)return true;
    return false;
}
void uniset(int p,int q)
{

    int k=p;
    while(k!=parent[k])k=parent[k];
    p=q;
    while(p!=parent[p])
    {
        q=parent[p];
        parent[p]=k;//cout<<"?"<<endl;
        p=q;
    }
    parent[p]=k;
}
void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ifstream fin("graph.in");
    ofstream fout("graph.out");
    fin>>n>>m;
    int x,y,z;
    edge e;
    for(int i=1;i<=m;i++)
    {
        fin>>x>>y>>z;
        e.a=x;e.b=y;e.t=z;e.in=i;
        g.push_back(e);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)fin>>a[i][j];
    }
}
void kruskal()
{
    for(int i=1;i<=n;i++)parent[i]=i;
    sort(g.begin(),g.end(),cmp);
    bool fl;
    for(int i=0;i<m;i++)
    {
        fl=find(g[i].a,g[i].b);
        if(!fl)
        {
            t.push_back(g[i]);
            uniset(g[i].a,g[i].b);
        }
        if(t.size()==n-1)break;
    }
}
void output()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //ifstream fin("graph.in");
    ofstream fout("graph.out");
    //cout<<n-1<<endl;
    for(int i=0;i<n-1;i++)fout<<t[i].in<<"\n";
    cout<<br<<endl;
}
//reread completely correct
void reread(vector<edge> fck)
{
    for(int i=1;i<=300;i++)rmqg[i].clear();
    for(int i=0;i<fck.size();i++)
    {
        //cout<<fck[i].a<<" "<<fck[i].b<<" "<<fck[i].t<<endl;
        edge2 p;
        p.e=fck[i].b;
        p.dis=fck[i].t;
        rmqg[fck[i].a].push_back(p);
        p.e=fck[i].a;
        rmqg[fck[i].b].push_back(p);
        //matricanasasedi[fck[i].a][fck[i].b]=matricanasasedi[fck[i].b][fck[i].a]=1;
        //cout<<"rmqg["<<fck[i].a<<"].push_back("<<fck[i].b<<")"<<endl;
    }
    //cout<<"reread done"<<endl;
}
void dfs_fill(int i)
{
    used[i]=1;
    level[i]=l;
    if(l>h)h=l;
    //cout<<i<<"->";
    for(int j=0;j<rmqg[i].size();j++)
    {
        //cout<<rmqg[i][j].e<<" ";
        if(!used[rmqg[i][j].e])
        {
            l++,dist[rmqg[i][j].e]=dist[i]+rmqg[i][j].dis;
            root[rmqg[i][j].e]=i;
            //cout<<"root["<<rmqg[i][j].e<<"]="<<i<<endl;
            dfs_fill(rmqg[i][j].e);
            l--;
        }
    }
    //cout<<"\n";
}
void dfs_par(int i)
{
    used[i]=1;
    if(level[i]<sq)pf[i]=0;
    if(level[i]%sq==0)pf[i]=root[i];
    else pf[i]=pf[root[i]];
    for(int j=0;j<rmqg[i].size();j++)
    {
        if(!used[rmqg[i][j].e])
        {
            dfs_par(rmqg[i][j].e);
        }
    }
}
int lca(int x,int y)
{
    while(pf[x]!=pf[y])
    {
        if(level[x]<level[y])y=pf[y];
        else x=pf[x];
    }
    //cout<<"first part lca done"<<endl;
    //cout<<x<<" "<<y<<" "<<level[x]<<" "<<level[y]<<" "<<root[x]<<" "<<root[y]<<endl;
    //cout<<x<<" "<<y<<" "<<root[x]<<" "<<root[y]<<endl;
    while(x!=y)
    {
        //cout<<x<<" "<<y<<endl;
        if(level[x]<level[y])y=root[y];
        else x=root[x];
    }
    //cout<<"second part lca done"<<endl;
    return x;
}
void dfstocomputedistsbtwij(int start,int node,int rast)
{
    usedtc[node]=1;
    distbtwij[start][node]=rast;
    for(int i=0;i<rmqg[node].size();i++)
    {
        if(usedtc[rmqg[node][i].e]==0)
        {
            dfstocomputedistsbtwij(start,rmqg[node][i].e,rast+rmqg[node][i].dis);
        }
    }
}
void getmin()
{
    memset(used,0,sizeof(used));
    memset(dist,0,sizeof(dist));

    //dfs_fill(1);
    //for(int i=0;i<n-1;i++)cout<<ct[i].in<<" ";
    //cout<<"\n";
    //cout<<"------------------------------"<<"\n";
    //cout<<"dfs_fill done"<<endl;
    //for(int i=1;i<=n;i++)if(used[i]==0){cout<<"NO"<<endl;return;}
    //memset(used,0,sizeof(used));
    //sq=sqrt(h);
    //if(sq==0)sq=1;
    //dfs_par(1);
    for(int i=1;i<=n;i++)dfstocomputedistsbtwij(i,i,0),memset(usedtc,0,sizeof(usedtc));
    //cout<<"dfs_par done"<<endl;
    long long segasesmqta=0;
    //cout<<n<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            segasesmqta+=(long long)(a[i][j]*distbtwij[i][j]);
            if((double)((double)(clock()-tim)/(double)CLOCKS_PER_SEC)>1.98)
            {
                output();
                exit(0);
            }
        }
        //cout<<i<<endl;
    }
    if(mn>segasesmqta)
    {
        t=ct;
        //cout<<"NEW"<<"\n";
        mn=segasesmqta;
    }
}
void ltschk()
{
    srand(time(NULL));
    random_shuffle(g.begin(),g.end());
    for(int i=1;i<=n;i++)parent[i]=i;
    ct.clear();
    for(int i=0;i<g.size();i++)
    {
        if(find(g[i].a,g[i].b)==false)
        {
            ct.push_back(g[i]);
            uniset(g[i].a,g[i].b);
        }
        if((double)((double)(clock()-tim)/(double)CLOCKS_PER_SEC)>1.98)
            {
                output();
                exit(0);
            }
        if(ct.size()==n-1)break;
    }
    //cout<<"T"<<endl;
    reread(ct);
    getmin();
    br++;
    //cout<<mn<<endl;
}
int main()
{
    tim=clock();
    input();
    kruskal();
    ct=t;
    reread(t);
    getmin();
    //5cout<<mn<<endl;
    //let the casino party begin
    while((double)((double)(clock()-tim)/(double)CLOCKS_PER_SEC)<1.98)
    {
        ltschk();
    }

    output();
}
