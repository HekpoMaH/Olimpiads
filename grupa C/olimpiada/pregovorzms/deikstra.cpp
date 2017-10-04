#include<iostream>
#include<vector>
using namespace std;
vector<pair<int, int> >a[100];
int d[100],t[100],m,n,p,x,y,z,u;
int start;
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y>>z;
        a[x].push_back(pair<int,int>(y,z));
        a[y].push_back(pair<int,int>(x,z));
    }
    cin>>start;
    for(int i=1;i<=n;i++)d[i]=1000;
    d[start]=0;
    for(int i=1;i<=n;i++)t[i]=i;
    
    for(int k=1;k<=n;k++)
    {
        p=k;
        for(int i=k+1;i<=n;i++)if(d[t[i]]<d[t[p]])p=i;
        swap(t[k],t[p]);
        u=t[k];
        for(auto q: a[u])
        {
            x=q.first;
            y=q.second;
            if(d[u]+y<d[x])d[x]=d[u]+y;
        }
    }
    for(int i=1;i<=n;i++)cout<<d[i]<<" ";
    cout<<endl;
    return 0;
}