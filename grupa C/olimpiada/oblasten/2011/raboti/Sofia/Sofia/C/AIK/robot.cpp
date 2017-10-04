#include <iostream>
using namespace std;

int m, n, r, k, i, j, t, s, l, h;
int a[101][101];

int main()
{
  cin >> m;
  cin >> n;
  cin >> r;
  cin >> k;

  t = 1;

  for(i=0; i<m; i++) {
    for(j=0; j<n; j++) {
      a[j][i] = t;

      if(t==r) {
        l = i;
        h = j;
      }

      t++;
    }
  }

  if(k==1) s = a[h+1][l] + a[h-1][l] + a[h][l+1] + a[h][l-1];
  else if(k!=1) s = a[h+1][l+1] + a[h-1][l-1] + a[h+1][l-1] + a[h-1][l+1]+ a[h+1][l] + a[h-1][l] + a[h][l+1] + a[h][l-1] + a[h][l];

  cout << s;
  cout << "\n";

  return 0;
}
