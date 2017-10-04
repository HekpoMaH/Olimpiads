#include<bits/stdc++.h>
using namespace std;
struct point
{
    int x,y;
};
point a[409];
int parent[409];
int n,h,br;
struct edge
{
    int f,s;long long t;
};
vector<edge> v;
vector<edge>t;
long long dist(point p1,point p2)
{
    return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
}
void makeg()
{
    edge wr;
    for(int i=1;i<=n;i++)parent[i]=i;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            wr.f=i;
            wr.s=j;
            wr.t=dist(a[i],a[j]);
            v.push_back(wr);
        }
    }
}
bool cmp(edge e1,edge e2)
{
    if(e1.t<e2.t)return true;
    return false;
}
bool find(int p,int q)
{
    while(p!=parent[p])p=parent[p];
    while(q!=parent[q])q=parent[q];
    if(p==q)return true;
    return false;
}
void uni(int p,int q)
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
void kruskal()
{
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<v.size();i++)
    {
        if(find(v[i].f,v[i].s)==false)
        {
            t.push_back(v[i]);
            uni(v[i].f,v[i].s);
        }
        if(t.size()==n-1)break;
    }
    long long mx=9999999999;
    //cout<<mx<<endl;
    for(int i=0;i<n-1;i++)mx=min(mx,t[i].t);
    int ans=(int)(double)(sqrt(mx)*10000);
    printf("%.4lf\n",sqrt(mx));
}
int main()
{
    cin>>h>>n;
    br=n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].x>>a[i].y;
        a[++br].x=a[i].x;
        a[br].y=0;
        a[++br].x=a[i].x;
        a[br].y=h;
    }
    n=br;
    makeg();
    kruskal();
}
