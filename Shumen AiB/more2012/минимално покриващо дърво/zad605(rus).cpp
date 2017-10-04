#include<iostream>
#include<iomanip>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int n,br,parent[60];
struct edge
{
    int a1,b1,a2,b2,num1,num2;
    int t;
};
vector<edge> g,t;
edge e;
int x[60],y[60],m,d,dd;
bool cmp(edge first,edge second)
{
    if(first.t<second.t)return true;
    if(first.t>second.t)return false;
    if(first.a1<second.a1)return true;
    if(first.a1>second.a1)return false;
    if(first.b1<second.b1)return true;
    if(first.b2>second.b2)return true;
    if(first.a2<second.a2)return true;
    if(first.a2>second.a2)return false;
    if(first.b2<second.b2)return true;
    return false;
}
bool find(int p,int q)
{
    //cout<<p<<endl;
    while(p!=parent[p]){p=parent[p];}
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
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x[i]>>y[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            e.a1=x[i];e.b1=y[i];e.a2=x[j];e.b2=y[j];
            e.num1=i;e.num2=j;
            e.t=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
            g.push_back(e);
        }
    }
    for(int i=1;i<=n;i++)parent[i]=i;
    cin>>m;
    
    for(int i=1;i<=m;i++)
    {
        cin>>d>>dd;
        for(int j=0;j<g.size();j++)
        {
            if(g[j].a1==x[d]&&g[j].b1==y[d]&&g[j].a2==x[dd]&&g[j].b2==y[dd])
            {
                g[j].t=0;
            }
        }
    }
    sort(g.begin(),g.end(),cmp);
    /*for(int i=0;i<g.size();i++)
    {
        cout<<g[i].num1<<" "<<g[i].num2<<" "<<g[i].t<<endl;
    }*/
    bool fl;
    for(int i=0;i<g.size();i++)
    {
        //cout<<"?"<<endl;
        //cout<<g[i].num1<<" "<<g[i].num2<<endl;
        fl=find(g[i].num1,g[i].num2);
        if(!fl)
        {
            t.push_back(g[i]);
            uniset(g[i].num1,g[i].num2);
        }
    }
    double sum=0;
    for(int i=0;i<t.size();i++)
    {
        sum+=sqrt(t[i].t);
    }
    cout<<setiosflags(ios::fixed)<<setprecision(5)<<sum<<endl;
    return 0;
}