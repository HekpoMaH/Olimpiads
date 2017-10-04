#include<iostream>
#include<queue>
using namespace std;
long long a[107][107],i0=-1,j0=-1,m,n,k,r,br,s,used[107][107];
queue<int> q,q1;
int main()
{
  cin>>m>>n>>r>>k;
  for(int i=0;i<m;i++)
  {
    for(int j=0;j<n;j++)
    {
      br++;
      a[i][j]=br;
      if(br==r){i0=i;j0=j;}
    }
  }
  q.push(i0);q1.push(j0);
  //used[i0][j0]=1;
  long long curi,curj,nexti,nextj;
  while(!q.empty())
  {
    curi=q.front();
    curj=q1.front();
    q.pop();q1.pop();
    if(curi+1<=m-1)
    {
      if(used[curi+1][curj]<k)
      {
        q.push(curi+1);
        q1.push(curj);
        used[curi+1][curj]=used[curi][curj]+1;
      }
    }
    if(curi-1>=0)
    {
      if(used[curi-1][curj]<k)
      {
        q.push(curi-1);
        q1.push(curj);
        used[curi-1][curj]=used[curi][curj]+1;
      }
    }
    if(curj+1<=n-1)
    {
      if(used[curi][curj+1]<k)
      {
        q.push(curi);
        q1.push(curj+1);
        used[curi][curj+1]=used[curi][curj]+1;
      }
    }
    if(curj-1>=0)
    {
      if(used[curi][curj-1]<k)
      {
        q.push(curi);
        q1.push(curj-1);
        used[curi][curj-1]=used[curi][curj]+1;
      }
    }
    cout<<a[curi][curj]<<endl;
  }
  for(int i=0;i<m;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(used[i][j]==k){s+=a[i][j];}
    }
  }
  cout<<s<<endl;
  return 0;
}
