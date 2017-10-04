#include<iostream>
using namespace std;
struct graph
{
  int st,ul[1995];
};
graph g[1995][1995];
int n,m,p[44],x,y,ulica,xl,yl,jhouse,br;
void solve()
{
  int b=1,e=br+1,mnstreet=0;
  p[b]=jhouse;
  for(int i=1;i<=n;i++)
  {
    if(st[i]%2==1)
    {
      cout<<"Round trip does not exist"<<endl;
      return;
    }
  }
  while(b!=e)
  {
    if(st[p[b]]==0)
    {
      p[e]=p[b];
      e--;
      b--;
    }
    if(st[p[b]]>0)
    {
      for(int i=1;i<=n;i++)
      {
        if(g[p[b]][i].st>0)
        {
          for(int j=1;j<=g[p[b]][i].st;j++)
          {
            if(mnstreet<g[p[b]][i].ul[j])
            {
              mnstreet=g[p[b]][i].ul[j];
              pointed=i;
            }
          }
        }
      }
      for(int i=1;i<=g[p[b]][pointed].st;i++)
      {
        if(mnstreet==g[p[b]][pointed].ul[i])
        {
          for(int j=i+1;j<=g[p[b]][pointed].st;j++)
          {
            g[p[b]][pointed].ul[j-1]=g[p[b]][pointed].ul[j];
          }
        }
      }
      for(int i=1;i<=g[pointed][p[b]].st;i++)
      {
        if(mnstreet==g[pointed][p[b]].ul[i])
        {
          for(int j=i+1;j<=g[pointed][p[b]].st;j++)
          {
            g[pointed][p[b]].ul[j-1]=g[pointed][p[b]].ul[j];
          }
        }
      }
      p[b+1]=pointed;
      g[p[b]][pointed].st--;g[pointed][p[b]].st--;
      b++;
    }
  }

int main()
{
  do
  {
    xl=x;yl=y;
    cin>>x>>y;
    if(x!=0)
    {
      cin>>ulica;
      g[x][y].st++;
      g[x][y].ul[st]=ulica;
      st[x]++;st[y]++;
      br++;
      if(xl==0&&yl==0){jhouse=min(x,y);}
    }
    if(x==0&&y==0&&x1!=0&&y1!=0)solve();
  }while(!(xl==0&&yl==0&&x==0&&y==0));