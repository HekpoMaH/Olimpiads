#include<iostream>
#include<algorithm>
using namespace std;
int g[104][104];
int n,m,k;
bool used[105];
long long v[105];
int pred[106],pat[105];
int mn,i0,j0,a,b,c;
int main()
{
  cin>>n>>m>>k;
  for(int i=0;i<=n;i++)
  {
    for(int j=0;j<=n;j++)
    {
      g[i][j]=9999;

    }
  }
  do
  {
    cin>>a>>b;
    if(a!=0&&b!=0)g[a][b]=1;
    if(a!=0&&b!=0)g[b][a]=1;
  }while(a!=0&&b!=0);
  used[m]=1;
  pred[m]=-1;
  do
  {
    mn=99;
    for(int i=1;i<=n;i++)
    {
      if(used[i]==0)
      {
        for(int j=1;j<=n;j++)
        {
          if(used[j]==1)
          {
            if(v[j]+g[i][j]<mn)
            {
              mn=v[j]+g[i][j];i0=i;j0=j;
            }
          }
        }
      }
    }
    if(mn<99)
    {
      used[i0]=1;
      v[i0]=mn;
      pred[i0]=j0;
    }
  }while(mn<99);
  int d=k,br=0;//cout<<v[k]<<endl;
  if(v[k]==0)cout<<"NO"<<endl;//cout<<v[k]<<endl;
  else{while(d!=-1)
  {
    pat[br]=d;
    br++;
    d=pred[d];
  }
  for(int i=0;i<br/2;i++)swap(pat[i],pat[br-i-1]);cout<<pat[0];
  for(int i=1;i<br;i++)cout<<" "<<pat[i];
  cout<<endl;}
  return 0;
}
/*
10 1 9
1 2
1 3
1 5
1 7
1 8
4 6
5 7
5 9
5 10
6 8
9 10
0 0
*/
