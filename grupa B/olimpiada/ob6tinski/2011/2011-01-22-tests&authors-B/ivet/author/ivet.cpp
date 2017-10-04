/**
PROGRAM NAME: ivet
AUTHOR: Evgenii Vassilev
*/

#include <iostream>
#include <cmath>
#include <iomanip>
#define PI acos(-1)
using namespace std;

int main() {
  double L1, L2;
  cin >> L1 >> L2;
  cout << fixed << setprecision(3) << (L2-L1)/PI/14 << endl;
  return 0;
}
