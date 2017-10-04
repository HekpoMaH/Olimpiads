#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct edge
{
    int u,v,w;
};
int n,m,k;
vector<edge> e;
vector<edge> t;
bool cmp(edge f,edge s)
{
    if(f.w>s.w)return true;
    return false;
}
int parent[1003];
bool find(int f,int s)
{
    while(f!=parent[f])f=parent[f];
    while(s!=parent[s])s=parent[s];
    if(f==s)return true;
    return false;
}
void uni(int f,int s)
{
    int bp=f;
    while(bp!=parent[bp])bp=parent[bp];
    while(s!=parent[s])
    {
        f=parent[s];
        parent[s]=bp;
        s=f;
    }
    parent[s]=bp;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        edge hel;
        cin>>hel.u>>hel.v>>hel.w;
        e.push_back(hel);
    }
    sort(e.begin(),e.end(),cmp);
    //for(int i=0;i<e.size();i++)cout<<e[i].u<<" "<<e[i].v<<" "<<e[i].w<<endl;
    for(int i=1;i<=k;i++)
    {
        int x,y;
        cin>>x>>y;
        for(int k=1;k<=n;k++)parent[k]=k;
        int j;
        for(j=0;j<e.size();j++)
        {
            //cout<<"FF"<<e[i].u<<" "<<e[i].v<<" "<<find(x,y)<<endl;
            if(find(x,y)==true)break;
            else uni(e[j].u,e[j].v);
        }
        cout<<e[j-1].w<<endl;
    }
}