#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
int a[2048],n,m,b[2048],used[2048],p;
vector<int> v[2048];
void read()
{
    int i,k1,k2;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&k1,&k2);
        v[k1].push_back(k2);
        v[k2].push_back(k1);
    }
}
void bfs(int k)
{
    int i,j,g=0,sz;
    used[k]=1;
    a[k-1]=1;
    b[g++]=k;
    for(i=0;i<g;i++)
    {
        sz=v[b[i]].size();
        for(j=0;j<sz;j++)
        {
            if(used[v[b[i]][j]]==0){
            b[g++]=v[b[i]][j];
            used[v[b[i]][j]]=1;
            a[v[b[i]][j]-1]=a[b[i]-1]+1;}
        }
    }
}
void solve()
{
    int i,br=0,k=0;
    sort(a,a+n);
    k=a[0];
    if(k)br=1;
    for(i=1;i<n;i++)
    {
        if(a[i]==k&&k)br++;
        else
        {
            if(br>p)p=br;
            br=1;
            k=a[i];
        }
    }
    if(br>p)p=br;
}
void write()
{
    cout<<p<<endl;
}
int main()
{
    read();
    bfs(1);
    solve();
    write();
}
