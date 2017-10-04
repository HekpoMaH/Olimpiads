//by the idea of cheater_no1
#include<bits/stdc++.h>
using namespace std;
struct edge
{
    int a,b,c;
    edge (){};
    edge(int _a,int _b,int _c)
    {
        a=_a;b=_b;c=_c;
    }
};
vector<edge> e;
int n,m,bmin,bmax=40000;
deque<int> gr[1009];
bool cmp(edge f,edge s)
{
    return f.c<s.c;
}
void read()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    int x,y,z;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y>>z;
        e.push_back(edge(x,y,z));
    }
}
void add(edge x)
{
    gr[x.a].push_back(x.b);
    gr[x.b].push_back(x.a);
}
void remove(edge x)
{
    gr[x.a].pop_front();
    gr[x.b].pop_front();
}
void getmin(int cmin,int cmax)
{
    if(cmax-cmin<bmax-bmin)bmax=cmax,bmin=cmin;
}
int used[1009];
bool bfs()
{
    queue<int> q;
    memset(used,0,sizeof(used));
    int br=0;
    used[1]=1;
    q.push(1);
    br++;
    deque<int>::iterator it;
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        for(it=gr[cur].begin();it!=gr[cur].end();it++)
        {
            if(!used[*it])used[*it]++,q.push(*it),br++;
        }
    }
    return br==n;
}
void solve()
{
    queue<int> q;
    sort(e.begin(),e.end(),cmp);
    for(int i=0;i<m;i++)
    {
        add(e[i]);
        q.push(i);
        while(!q.empty()&&bfs())
        {
            int curr=q.front();
            getmin(e[curr].c,e[i].c);
            q.pop();
            remove(e[curr]);
        }
    }
}
int main()
{
    read();solve();
    cout<<bmin<<" "<<bmax<<"\n";
}
