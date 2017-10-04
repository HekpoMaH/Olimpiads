#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
queue<int> q;
long long a,n,m,b,g[2020][2020],used[2020];
int main()
{
  ios::sync_with_stdio(false);
  cin>>n>>m;
  for(int i=0;i<m;i++)
  {
    cin>>a>>b;
    g[a][b]=1;
    g[b][a]=1;
  }
  q.push(1);
  used[1]=1;
  while(!q.empty())
  {
    a=q.front();//cout<<a<<endl;
    q.pop();
    for(int i=1;i<=n;i++)
    {
      b=i;
      if(used[b]==0&&g[a][b]==1)
      {
        //cout<<"b "<<b<<endl;
        used[b]=used[a]+1;
        q.push(b);
      }
    }
  }
  int mx=-1,brl[2009]={0};
  for(int i=1;i<=2000;i++)
  {
    brl[used[i]]++;
  }
  for(int i=1;i<=2000;i++)if(brl[i]>mx)mx=brl[i];
  cout<<mx<<"\n";
  return 0;
}
