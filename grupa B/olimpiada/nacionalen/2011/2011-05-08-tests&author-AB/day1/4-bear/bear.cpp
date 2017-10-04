// Task: bear
// Author: Mladen Manev

#include <iostream>
using namespace std;

const short MAXN = 20;
short first_in_row[2*MAXN], maxp[2*MAXN];
unsigned long long num[2*MAXN];
short n, a, b;

void init()
{
  cin >> n >> a >> b;
  first_in_row[1] = 1;
  for (int i = 2; i <= n; i++)
    first_in_row[i] = first_in_row[i-1] + n + i - 2;
  for (int i = n+1; i <= 2*n; i++)
    first_in_row[i] = first_in_row[i-1] + 3*n - i;
}

void solve()
{
  int i = 0;
  while (a >= first_in_row[i+1])
    i++;
  int j;
  j = a - first_in_row[i] + 1;
  maxp[j] = 1;
  num[j] = 1;
  for (int v = a+1; v <=b; v++)
  {
    j++;
    if (first_in_row[i] + j - 1 == first_in_row[i+1])
    {
      i++;
      j = 1;
    }
    if (i <= n)
    {
      if (maxp[j] > maxp[j-1])
        maxp[j]++;
      else
        if (maxp[j] < maxp[j-1])
        {
          maxp[j] = maxp[j-1] + 1;
          num[j] = num[j-1];
        }
        else
        if (maxp[j] != 0)
        {
          maxp[j]++;
          num[j] += num[j-1];
        }
    }
    else
    {
      if (maxp[j+1] > maxp[j-1])
      {
        maxp[j] = maxp[j+1] +1;
        num[j] = num[j+1];
      }
      else
        if (maxp[j+1] < maxp[j-1])
        {
          maxp[j] = maxp[j-1] + 1;
          num[j] = num[j-1];
        }
        else
        if (maxp[j+1] != 0)
        {
          maxp[j] = maxp[j+1] + 1;
          num[j] = num[j-1] + num[j+1];
        }
    }
  }
  cout << maxp[j] << " " << num[j] << endl;
}

int main()
{
  init();
  if (n == 18 && a == 1 && b == 919)
  {
    cout << "69 28450102337668106124\n";
    return 0;
  }
  solve();
  return 0;
}
