#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;
int a[10004],n,used[10004],pred[10004];
vector <int> v[10002];
vector <int> v2;
void read()
{
  int i;
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>a[i];
  }
}
int pal(int f, int l)
{
  int k=l;
  for(int j=f;j<=l;j++)
  {
    if(a[j]!=a[k]) return 0;
    k--;
  }
  return 1;
}
void bfs()
{
  int ft,pos=2;
  queue <int> q;
  q.push(1);
  used[1]=1;
  while(!q.empty())
  {
    ft=q.front();
    q.pop();
    for(int j=0;j<v[ft].size();j++)
    {
      if(!used[v[ft][j]])
      {
        q.push(v[ft][j]);
        used[v[ft][j]]=pos;
        pred[v[ft][j]]=ft;
        if(v[ft][j]==n+1) return;
      }
    }
    pos++;
  }
}
void prev(int j)
{
  v2.push_back(j);
  if(pred[j]!=1) prev(pred[j]);
}
int main()
{
  read();
  if(pal(1,n)) cout<<1<<endl;
  else
  {
      v[1].push_back(1);
      for(int i=1;i<=n;i++)
      {
        for(int j=i;j<=n;j++)
        {
          if(pal(i,j)) { v[i].push_back(j+1);}
        }
      }
      bfs();
      prev(n+1);
      cout<<v2.size()<<endl;
      for(int j=v2.size()-1;j>0;j--)
      {
        cout<<v2[j]-1<<" ";
      }
      cout<<endl;
  }
  return 0;
}
