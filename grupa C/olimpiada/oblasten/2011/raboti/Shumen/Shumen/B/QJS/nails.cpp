#include <iostream>
#include <vector>
using namespace std;
struct edge
{
  int x;
  int y;
  int x1;
  int y1;
};
edge e[1024];
vector <int> v[1024];
int used[1024],n=1,ans;
void read()
{
  while(cin>>e[n].x>>e[n].y>>e[n].x1>>e[n].y1)
  {
    n++;
  }
}
int cross(int a1, int a2)
{
  long long f1,f2,f3,f4;
  f1=e[a1].x*e[a1].y1-e[a1].y*e[a1].x1+e[a1].x1*e[a2].y-e[a1].y1*e[a2].x+e[a2].x*e[a1].y-e[a2].y*e[a1].x;
  f2=e[a1].x*e[a1].y1-e[a1].y*e[a1].x1+e[a1].x1*e[a2].y1-e[a1].y1*e[a2].x1+e[a2].x1*e[a1].y-e[a2].y1*e[a1].x;
  f3=e[a2].x*e[a2].y1-e[a2].y*e[a2].x1+e[a2].x1*e[a1].y-e[a2].y1*e[a1].x+e[a1].x*e[a2].y-e[a1].y*e[a2].x;
  f4=e[a2].x*e[a2].y1-e[a2].y*e[a2].x1+e[a2].x1*e[a1].y1-e[a2].y1*e[a1].x1+e[a1].x1*e[a2].y-e[a1].y1*e[a2].x;
  if(((f1>=0&&f2<=0)||(f1<=0&&f2>=0))&&((f3>=0&&f4<=0)||(f3<=0&&f4>=0))) return 1;
  return 0;
}
void dfs(int i)
{
  int sz=v[i].size(),j;
  used[i]=1;
  for(j=0;j<sz;j++)
  {
    if(!used[v[i][j]])
    {
      used[v[i][j]]=1;
      dfs(v[i][j]);
    }
  }
}
int main()
{
  read();
  for(int i=1;i<n;i++)
  {
    for(int j=1;j<n;j++)
    {
      if(i!=j)
      {
        if(cross(i,j)) { v[i].push_back(j); v[j].push_back(i); }
      }
    }
  }
  dfs(n-1);
  for(int i=1;i<n;i++)
  {
   // cout<<used[i]<<" ";
    if(!used[i]) ans++;
  }
 // cout<<endl;
  cout<<ans<<endl;
return 0;
}
