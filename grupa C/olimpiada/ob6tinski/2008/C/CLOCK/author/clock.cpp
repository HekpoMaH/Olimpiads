#include<iostream>

using namespace std;

int main()

{ char a1, a2, a3, a4 , a5, b1, b2, b3, b4, b5;
  cin >> a1 >> a2 >> a3 >> a4 >> a5;
  cin >> b1 >> b2 >> b3 >> b4 >> b5;
  int a = (10 * (a1 - '0') + (a2 - '0'))*60 + 10*(a4 - '0') + (a5 - '0');
  int b = (10 * (b1 - '0') + (b2 - '0'))*60 + 10*(b4 - '0') + (b5 - '0');
  if (a >= b) b = b + 1440;
  int c = b - a;
  if (c/60 < 10) cout << 0;
  cout << c/60 << ':';
  if (c%60 < 10) cout << 0;
  cout << c%60 << endl;
  return 0;
}

