/**
  Task: apple
  Author: Mladen Manev
*/

#include <iostream>
using namespace std;

int f(int i)
{
  if (i <= 2) return i;
  if (i % 3 == 0) return 3 * f(i/3) + 1;
  if (i % 3 == 1) return f(i-1) + 1;
  return f(i-2) + 2;
}

int main()
{
  int x;
  cin >> x;
  cout << f(x) << endl;
  return 0;
}
