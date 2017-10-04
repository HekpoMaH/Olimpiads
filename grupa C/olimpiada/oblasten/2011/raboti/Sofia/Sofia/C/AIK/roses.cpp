#include <iostream>
using namespace std;

int g[1001][1001];
int k, m, n, i, j, h, l, d, t, s;
int a[1000];

int main()
{
  cin >> m;
  cin >> n;
  cin >> k;

  d = 0;
  s = 0;

  for (i=0; i<m; i++) {
    for (j=0; j<n; j++) {
      cin >> g[j][i];

      s += g[j][i];
    }
  }

  for (i=0; i<=m-k; i++) {
    for (j=0; j<=n-k; j++) {
      for (h=i; h<k+i; h++) {
        for (l=j; l<k+j; l++) {
          a[d] += g[l][h];
        }
      }
      d++;
    }
  }

  for (i=0; i<m*n; i++) {
    for (j=m*n; j>i; --j) {
      if(a[i] < a[j]) {
        t = a[j];
        a[j] = a[i];
        a[i] = t;
      }
    }
  }

  s = s - a[0];

  cout << s;
  cout << "\n";

  return 0;
}

