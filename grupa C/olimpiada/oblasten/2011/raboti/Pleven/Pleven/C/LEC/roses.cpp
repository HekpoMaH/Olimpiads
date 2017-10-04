#include<iostream>
using namespace std;
 long long a[1001][1001],n,m,k,b,i,j,max1;

int main()
{
  cin>>n>>m>>k;
  for (i=1;i<=n;i++)
  {
    for (j=1;j<=m;j++)
    {
      cin>>b;
      a[i][j]=b+a[i-1][j]+a[i][j-1]-a[i-1][j-1];
    }
  }
  for (i=1;i<=n;i++)
  {
    for (j=1;j<=m;j++)
    {
      if (i-k>=0&&j-k>=0)
      {
        b=a[i][j]-(a[i][j-k]+a[i-k][j])+a[i-k][j-k];
        if (b>max1) {max1=b;}
      }
    }
  }

  cout<<a[n][m]-max1<<endl;
  return 0;
}
/*
3 4 2
1 1 1 2
2 3 4 1
2 1 9 2
*/