#include<iostream>
using namespace std;
int a[100][100],n,m;
int mem[108][108];
int c(int k,int l)
{
  if(k==n-1)if(l==m-1){return a[k][l];}
  if(mem[k][l]!=-1)return mem[k][l];
  int res=0;
  if(l<m-1){res=max(res,a[k][l]+c(k,l+1));}
  if(k<n-1){res=max(res,a[k][l]+c(k+1,l));}
  mem[k][l]=res;
  return res;
}
int main()
{
  cin>>n>>m;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      cin>>a[i][j];
    }
  }
  for(int i=0;i<102;i++)
  {
    for(int j=0;j<102;j++)
    {
      mem[i][j]=-1;
    }
  }
  cout<<c(0,0)<<endl;
  return 0;
}
