#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct edge
{
    int a,b,t;
};
vector<edge> g,t;
edge e;
int n,m,teglo;
int price[1002],parent[1002];
int x,y,z;
bool cmp(edge first,edge second)
{
    if(first.t<second.t)return true;
    if(first.t>second.t)return false;
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
        parent[p]=k;
        p=q;
    }
    parent[p]=k;
}
bool cmp2(edge first,edge second)
{
    if(first.a<second.a)return true;
    if(first.a>second.a)return false;
    if(first.b<second.b)return true;
    return false;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)parent[i]=i;
    for(int i=1;i<=n;i++)
    {
        cin>>price[i];
    }
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y>>z;
        if(x>y)swap(x,y);
        if(z%2==0)
        {
            teglo=price[x]*(z/2)+price[y]*(z/2);
        }
        else
        {
            teglo=price[x]*(z/2+1)+price[y]*(z-(z/2+1));
        }
        e.a=x;e.b=y;e.t=teglo;
        g.push_back(e);
    }
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
    int sum=0;
    for(int i=0;i<t.size();i++)sum+=t[i].t;
    cout<<sum<<endl;
    sort(t.begin(),t.end(),cmp2);
    for(int i=0;i<t.size();i++)
    {
        cout<<t[i].a<<" "<<t[i].b<<endl;
    }
    return 0;
}