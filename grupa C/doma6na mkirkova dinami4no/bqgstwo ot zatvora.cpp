#include <iostream>
using namespace std;
int main()
{
  int m, n;
  int a [701][701];
  cin >> m >> n;
  for (int i=1; i<=m; i++)
      for (int j=1; j<=n; j++)
          cin>>a[i][j];
  for (int i=2; i<=m;i++) if (a[i-1][1]==0) a[i][1]=0;
  for (int j=2; j<=n; j++)if ( a[1][j-1]==0)a[1][j]=0;
  for (int i=2; i<=m; i++)
      for (int j=2; j<=n; j++)
          if (a[i][j]!=0) a[i][j]=a[i-1][j]+a[i][j-1];

  if (a[m][n]!=0) cout<< a[m][n]<<endl;
  else cout <<"Impossible"<<endl;
  return 0;
}
