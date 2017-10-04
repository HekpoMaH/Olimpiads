#include <iostream>
using namespace std;

int s, n, i, t, o, k, a, j, r;
int b[101];

int main()
{
  cin >> s;
  cin >> n;

  for (i=0; i<n; i++) {
    cin >> b[i];
  }

  for(i=0; i<n; i++) {
    for(j=n; j>i; --j) {
      if(b[i] < b[j]) {
        t = b[i];
        b[i] = b[j];
        b[j] = t;
      }
    }
  }

  o = s % b[0];

  r = s / b[0];

  if(o == s) cout << "1";
  else {
    for(i=1; i<n; i++) {
      a = o % b[i];

      if((a<o) && (a>=0)) {
        r += o / b[i];
        o = a;

        if(a==0) break;
      }
    }
  }

  cout << r;
  cout << "\n";

  return 0;
}

