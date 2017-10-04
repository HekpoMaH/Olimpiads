#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct edge
{
  int x, y, t;
};
int cmp(edge e1, edge e2)
{
  if(e1.t<e2.t)return 1;
  if((e1.t==e2.t)&&(e1.x<e2.x))return 1;
  if((e1.t==e2.t)&&(e1.x==e2.x)&&e1.y<e2.y)return 1;
  return 0;
}
int cmp1(edge e1, edge e2)
{
  if(e1.x<e2.x)return 1;
  if((e1.x==e2.x)&&e1.y<e2.y)return 1;
  return 0;
}

int n,m;
int price[1<<17];
vector<edge> v,tree;
void read()
{
  int i, u,w,d;
  edge e;
  cin>>n>>m;
  for(i=1;i<=n;i++)
  cin>>price[i];
  for(i=1;i<=m;i++)
  {
    cin>>u>>w>>d;
    if(u>w)swap(u,w);
    e.x=u;
    e.y=w;
    if(d%2==0)e.t=d/2*price[u]+d/2*price[w];
    else e.t=(d/2+1)*price[u]+d/2*price[w];
    v.push_back(e);
  }
}
int parent[1<<17];
long long t_MST=0;
int Find(int u)
//връща родителя на u
{
  int i;
  i=u;
  while(parent[i]!=i)i=parent[i];
  return i;
}
int Union(int p,int q)
//добавя елементите на множеството q към множество с корен p
{
  int i;
  i=q;
  while(i!=parent[i]){q=parent[i];parent[i]=p;i=q;}
  parent[i]=p;
}
void MST()
{
  sort(v.begin(),v.end(),cmp);
  int i,brt=0,r;
  for(i=1;i<=n;i++)parent[i]=i;
  i=0;
  while(brt<n-1)
  {
    r=Find(v[i].x);
    if(r!=Find(v[i].y))
    {
      Union(r,v[i].y);
      tree.push_back(v[i]);t_MST+=v[i].t;
      brt++;
    }
    i++;
  }
}
  
int main()
{
    int i;
  read();
  MST();
  sort(tree.begin(),tree.end(),cmp1);
  cout<<t_MST<<endl;
  for(i=0;i<n-1;i++)
  {
    cout<<tree[i].x<<' '<<tree[i].y<<endl;
  }
  return 0;
}
