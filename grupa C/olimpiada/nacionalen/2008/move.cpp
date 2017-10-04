#include<iostream>
#include<queue>
using namespace std;
long long a[1000005],d[1000005],n,x,y,b,t,p;
queue<int> q;
long prog(long r)
{
  return 1+(r-1)/n;
}
int main()
{
  ios::sync_with_stdio(false);
  cin>>n>>x>>y;
  cin>>b;
  for(int i=1;i<=b;i++)
  {
    cin>>t;
    a[t]=1;
  }
  for(int i=1;i<=n*n;i++)d[i]=-1;
  d[x]=0;
  q.push(x);
  while(!(q.empty()))
  {
    t=q.front();q.pop();
    p=t-1;
    while(prog(p)==prog(t)&&a[p]==0)
    {
      if(d[p]==-1){d[p]=d[t]+1;q.push(p);}
      p--;
    }
    p=t+1;
    while(prog(p)==prog(t)&&a[p]==0)
    {
      if(d[p]==-1){d[p]=d[t]+1;q.push(p);}
      p++;
    }
    p=t+n;
    while(p<=n*n&&a[p]==0)
    {
      if(d[p]==-1){d[p]=d[t]+1;q.push(p);}
      p+=n;
    }
    p=t-n;
    while(p>=0&&a[p]==0)
    {
      if(d[p]==-1){d[p]=d[t]+1;q.push(p);}
      p-=n;
    }
  }
  cout<<d[y]<<endl;
  return 0;
}
