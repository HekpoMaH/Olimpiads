#include<iostream>
using namespace std;
int a[100][100],n,m,l,r;
int mem[108][108][108];
int c(int k,int l,int okr)
{
  if(k==n-1&&l==m-1){
    if(okr==a[k][l]){return 1;}
    else return 0;
  }
  if(mem[k][l][okr]!=-1)return mem[k][l][okr];
  int res=0;
  if(l<m-1){res+=c(k,l+1,okr-a[k][l]);}
  if(k<n-1){res+=c(k+1,l,okr-a[k][l]);}
  mem[k][l][okr]=res;
  return res;
}
int main()
{
  cin>>n>>m;
  cin>>l>>r;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      cin>>a[i][j];
    }
  }
  //for(int i=0;i<102;i++)
  //{
    //for(int j=0;j<102;j++)
   // {
     // mem[i][j]=-1;
   // }
  //}
  int sum=0;
  for(int i=l;i<=r;i++)
  {
    for(int u=0;u<102;u++)
  {
    for(int j=0;j<102;j++)
    {
      for(int y=0;y<102;y++)
      {
      mem[u][j][y]=-1;}
    }
  }
    sum+=c(0,0,i);
  }
  cout<<sum<<endl;
  return 0;
}
