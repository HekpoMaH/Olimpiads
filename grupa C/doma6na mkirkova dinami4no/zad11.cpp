#include<iostream>
using namespace std;
int m,n,a[11][11];
int main()
{
  cin>>m>>n;
  for(int i=1;i<=m;i++)a[i][0]=1;
  for(int i=1;i<=n;i++)a[0][i]=1;
  for(int i=1;i<=m;i++)
  {
    for(int j=1;j<=n;j++)
    {
      a[i][j]=a[i-1][j]+a[i][j-1];
    }
  }
  cout<<a[m][n]<<endl;
  return 0;
}
