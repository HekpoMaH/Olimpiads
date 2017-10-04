#include<iostream>
#include<queue>
using namespace std;
int n,m,a[100][100],used[100],v1,v2,gr;
queue<int> q;
int main()
{
  cin>>n>>m;
  for(int i=0;i<m;i++)
  {
    cin>>v1>>v2;
    a[v1][v2]=1;
    a[v2][v1]=1;
  }
  q.push(1);
  used[1]=1;
  while(!q.empty())
  {
    gr=q.front();
    used[gr]=1;
    q.pop();
    for(int i=1;i<=n;i++)
    {
      if(a[gr][i]==1&&used[i]==0)q.push(i);
    }
    if(!q.empty())cout<<gr<<endl;
  }
  return 0;
}
