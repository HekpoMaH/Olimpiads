#include<iostream>
#include<vector>
using namespace std;
vector<pair<int,int> >a[100];
const int inf=1000;
int n,m,x,u,v,s,g;
int t[100],d[100];
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v>>g;
        a[u].push_back(pair<int,int>(v,g));
        a[v].push_back(pair<int,int>(u,g));
    }
    cin>>s;
    for(int i=1;i<=n;i++)d[i]=inf;
    d[s]=0;
    for(int i=1;i<=n;i++)t[i]=i;
    int p,x;
    for(int k=1;k<=n;k++)
    {
        p=k;
        for(int i=k+1;i<=n;i++)if(d[t[i]]<d[t[p]])p=i;
        swap(t[k],t[p]);
        u=t[k];
        for(auto q: a[u])
        {
            v=q.first;
            x=q.second;
            if(d[v]>d[u]+x)d[v]=d[u]+x;
        }
    }
    for(int i=1;i<=n;i++)cout<<d[i]<<" ";
    cout<<endl;
    return 0;
}