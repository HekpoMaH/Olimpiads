#include <iostream>
using namespace std;

typedef long long matrix[2][2];

void mult(matrix a, matrix b)
{
  matrix c;
  for(int i=0; i<2; i++)
    for(int j=0; j<2; j++)
    {
      c[i][j]=0;
      for(int k = 0; k<2; k++)
        c[i][j] += a[i][k]*b[k][j];
    }
  for(int i=0; i<2; i++)
    for(int j=0; j<2; j++)
      a[i][j]=c[i][j];
}

void power(matrix x, int p)
{
  matrix ans= {1, 0,
               0, 1};
  while(p)
  {
    if (p&1) mult(ans,x);
      mult(x,x);
      p >>= 1;
  }
  x[0][0] = ans[0][0];
  x[0][1] = ans[1][0];
  x[1][0] = ans[1][0];
  x[1][1] = ans[1][1];
}

int main()
{
  int n, m;
  cin >> n;
  matrix d;
  for(int i=1; i<=n; i++)
  {
    cin >> m;
    d[0][0] = 3; d[0][1] = d[1][0] = d[1][1]= 2;
    power(d, m-1);
    cout << 6*(d[0][0] + d[0][1] + d[1][0] + d[1][1]) << endl;
  }
  return 0;
}
