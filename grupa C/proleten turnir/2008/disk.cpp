#include<iostream>
using namespace std;
long long a[21][21],k,n;
int main()
{
  cin>>n>>k;
  for(int i=0;i<=k;i++)
  {
    a[0][i]=1;
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=i;j<=n&&j<=i+k;j++)
    {
      a[i][j]=a[i-1][j]+a[i][j-1];
    }
  }
  cout<<a[n][n]<<endl;
  return 0;
}
