#include<bits/stdc++.h>
using namespace std;
const int maxm=105000,maxn=102;
long long n,m,b;
const long long inf=1e15;
struct state
{
    long long cost;
    set<int> ufr;
    long long bc;//bought computers
};
struct fr
{
    long long x,k,m;
    long long probl[22];
};
fr frs[maxn];
state dp[maxm];
void read()
{
    cin>>n>>m>>b;
    for(int i=1;i<=n;i++)
    {
        cin>>frs[i].x>>frs[i].k>>frs[i].m;
        for(int j=0;j<frs[i].m;j++)cin>>frs[i].probl[j];
    }
}
//we solve it like a BFS
//NOT
void solve()
{
    state x;
    queue<long long> toc;
    dp[0].cost=0;
    dp[0].bc=0;
    dp[0].ufr.clear();
    long long mask=0;
    long long amask=0;
    for(long long i=0;i<m;i++)amask+=(1<<i);
    //cout<<"amask="<<amask<<endl;;
    for(int i=1;i<=amask;i++)dp[i].cost=inf;
    for(int i=0;i<=amask;i++)
    {
        //cout<<i<<" "<<dp[i].cost<<"\n";
        if(dp[i].cost!=inf)
        {
            //x.cost
            for(int j=1;j<=n;j++)
            {
                if(x.ufr.find(j)!=x.ufr.end())continue;
                x=dp[i];
                mask=i;
                x.cost+=max(0LL,frs[j].k-x.bc)*b;
                x.bc=max(x.bc,frs[j].k);
                x.cost+=frs[j].x;
                x.ufr.insert(j);
                for(int j1=0;j1<frs[j].m;j1++)
                {
                    mask|= 1<<(frs[j].probl[j1]-1);
                    //cout<<"solving probl "<<frs[j].probl[j1]<<" adding "<< (1<<(frs[j].probl[j1]-1))<<" ";
                }
                //cout<<"mask="<<mask<<"\n";
                if(dp[mask].cost>x.cost)dp[mask]=x;
            }
        }
    }
    if(dp[amask].cost==inf)cout<<"-1\n";
    else cout<<dp[amask].cost<<"\n";
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    read();
    solve();
}
