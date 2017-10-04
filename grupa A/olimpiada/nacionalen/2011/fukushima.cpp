#include<bits/stdc++.h>
using namespace std;
const int maxn=1009;
const int inf=1e9;
int n,m;
int g[maxn][maxn];
int ans=0;
int prenum[maxn],deg[maxn];
int chek(int cutoff)
{
    for(int i=1;i<=n;i++)deg[i]=0;
    for(int i=1;i<=n;i++)
    {
        for(int c=1;c<=n;c++)
        {
            if(g[i][c]<=cutoff)deg[c]++;
        }
    }
    for(int i=1;i<=n;i++)
    {
        int idx=-1;
        for(int c=1;c<=n;c++)
            if(deg[c]==0){idx=c;break;}
        if(idx==-1)return 0;
        deg[idx]=-1;
        prenum[i]=idx;
        for(int c=1;c<=n;c++)
        {
            if(g[idx][c]<=cutoff)deg[c]--;
        }
    }
    return 1;
}
void solve()
{
    int lef=0,righ=inf,mid;
    ans=0;
    while(lef<=righ)
    {

        mid=lef+righ;mid/=2;//cout<<lef<<" "<<righ<<" "<<mid<<" "<<chek(mid)<<" "<<ans<<endl;
        if(chek(mid))
        {
            lef=mid+1;
            if(ans<mid)ans=mid;
            //ans=max(ans,mid);
        }
        else righ=mid-1;
    }
    chek(ans);
}
void read()
{

    for(int i=0;i<=maxn;i++)
    {
        for(int j=0;j<=maxn;j++)
        {
            g[i][j]=inf+3;
        }
    }
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        g[y][x]=z;
    }
}
void write()
{
    //cout<<ans<<endl;
    if(ans>=inf)cout<<-1<<"\n";
    else cout<<ans<<"\n";
    for(int i=1;i<=n;i++)
    {
        cout<<prenum[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    read();
    solve();
    write();
}
