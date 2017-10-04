//little girl and problem on trees
//solve by BIT
// i dont know segment trees very good :|
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<stack>
#define MAX_N 100005
#define MAX_K 100005
using namespace std;
int n,q,a,b,v,x,d,kom;
vector<int> graf[100009];
bool mark[100009];
int chn[100009];
int dep[100009];
vector<long long> chainz[100009];
int size[100009];
int chn_amt;
long long dep_upd[100009];

inline int min1(int a, int b)
{
    if (a<b) return a;
    return b;
}

void d_update(int x, long long val)
{
    while (x <= MAX_K - 1)
    {
        dep_upd[x] += val;
        x += (x & -x);
    }
}
long long d_read(int x)
{
    long long sum=0;
    while (x > 0)
    {
        sum += dep_upd[x];
        x -= (x & -x);
    }
    return sum;
}


void update(int id, int x, long long val)
{
    while (x <= size[id])
    {
        chainz[id][x] += val;
        x += (x & -x);
    }
}
long long read(int id, int x)
{
    long long sum=0;
    while (x > 0)
    {
        sum += chainz[id][x];
        x -= (x & -x);
    }
    return sum;
}

inline void DFS()
{
    stack<int> dfs_stek;
    stack<int> depth;
    stack<int> chain_id;
    dfs_stek.push(1);
    depth.push(0);
    while (!dfs_stek.empty())
    {
        int xt = dfs_stek.top();
        int dt = depth.top();
        //printf("xt = %d, dt = %d\n",xt,dt);
        dfs_stek.pop();
        depth.pop();
        dep[xt] = dt;
        mark[xt] = true;
        if (xt == 1)
        {
            chn_amt = graf[xt].size();
            for (int i=0;i<graf[xt].size();i++)
            {
                dfs_stek.push(graf[xt][i]);
                depth.push(1);
                chain_id.push(i);
                mark[graf[xt][i]] = true;
            }
        }
        else
        {
            int ct = chain_id.top();
            chain_id.pop();
            chn[xt] = ct;
            size[ct] = dt;
            for (int i=0;i<graf[xt].size();i++)
            {
                if (!mark[graf[xt][i]])
                {
                    dfs_stek.push(graf[xt][i]);
                    depth.push(dt+1);
                    chain_id.push(ct);
                    mark[graf[xt][i]] = true;
                }
            }
        }
    }
}
int main()
{
    scanf("%d%d",&n,&q);
    for (int i=0;i<n-1;i++)
    {
        scanf("%d%d",&a,&b);
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    DFS();
    //printf("ziv_dfs\n");
    for (int i=0;i<chn_amt;i++)
    {
        chainz[i].resize(size[i]+5);
    }
    while (q--)
    {
        scanf("%d",&kom);
        if (kom == 0)
        {
            scanf("%d%d%d",&v,&x,&d);
            if (v == 1)
            {
                d_update(1,x);
                d_update(d+2,-x);
                //printf("depth updated from %d to %d\n",1,d+2);
            }
            else
            {
                int ch = chn[v];
                int l = dep[v] - d;
                int r = min1(size[ch],dep[v] + d);
                if (dep[v] <= d)
                {
                    d_update(1,x);
                    d_update(d-dep[v]+2,-x);
                    //printf("depth updated from %d to %d\n",1,d-dep[v]+2);
                    l = d-dep[v]+1;
                }
                update(ch,l,x);
                if (r < size[ch]) update(ch,r+1,-x);
                //printf("updated from %d to %d\n",l,r);
            }
        }
        else if (kom == 1)
        {
            scanf("%d",&v);
            long long ret = 0LL;
            int ch = chn[v];
            ret += read(ch,dep[v]);
            ret += d_read(dep[v]+1);
            //cout << ret << endl;
            printf("%I64d\n",ret);
        }
    }
}
