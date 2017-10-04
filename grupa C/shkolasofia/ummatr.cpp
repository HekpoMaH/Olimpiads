#include<iostream>
using namespace std;
int a[50][50],b[50][50],c[50][50],m,n,x,y,s;
int main()
{
  cin>>m>>n>>x>>y;
  for(int i=0;i<m;i++)
  {
    for(int j=0;j<n;j++)4
    {
      cin>>a[i][j];
    }
  }
  for(int i=0;i<x;i++)
  {
    for(int j=0;j<y;j++)
    {
      cin>>b[i][j];
    }
  }
  for(int i=0;i<m;i++)
  {
    for(int j=0;j<y;j++)
    {
      s=0;
      for(int k=0;k<n;k++)
      {
        s+=a[i][k]*b[k][j];
      }
      c[i][j]=s;
    }
  }
  for(int i=0;i<m;i++)
  {
    for(int j=0;j<y;j++)
    {
      cout<<c[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}
