#include<iostream>
using namespace std;
int a[22][22],b[22][22],m,n;
int main()
{
  cin>>m>>n;
  for(int i=0;i<m;i++)
  {
    for(int j=0;j<n;j++)
    {
      cin>>a[i][j];
    }
  }
  b[0][0]=a[0][0];
  for(int i=1;i<m;i++)b[i][0]=b[i-1][0]+a[i][0];
  for(int i=1;i<n;i++)b[0][i]=b[i-1][0]+a[0][i];
  for(int i=1;i<m;i++)
  {
    for(int j=1;j<n;j++)
    {
      b[i][j]=max(b[i-1][j],b[i][j-1])+a[i][j];
    }
  }
  cout<<b[m-1][n-1]<<endl;
  return 0;
}