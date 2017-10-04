#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{ int n,m,t,k;
  int x[2],y[2];

  cin >> n >> m >> t;
  cin >> x[0] >> y[0];

  cin >> x[1] >> y[1];
  if(cin.good()) k=2; else k=1;

  int cnt = 0;
  for(int i=1; i<=n; i++)
  for(int j=1; j<=m; j++)
  { int r = 1;
    for(int p=0; p<k; p++)
      if(abs(x[p]-i)+abs(y[p]-j) <= t) r = r*0;
    cnt = cnt + r;
  }

  cout << cnt << endl;

  return 0;
}

