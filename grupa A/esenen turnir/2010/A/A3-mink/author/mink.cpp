#include<iostream>
using namespace std;

int a[30];
int n, k;
bool okk;

void next(int i, int k)
{
  bool ok;
  long long left = 1, right = n;
  for(int j = 1; j < i; j++)
  {
    left *= 1+a[j];
    right *= a[j];
  }
  if (left >= right) return;
  if (i == k)
  { if (left == (left/(right-left)) * (right-left))
      {
        a[k] = left/(right-left);
        okk = true;
      }
    return;
  }
  a[i] = a[i-1];
  do
  {
    ok = false;
    for (int j = i; j <= k; j++)
     { left *= 1 + a[i];
       right *= a[i];
     }
    if (left >= right)
      { ok = true;
        next(i+1, k);
        if (okk) return;
      }
    for (int j=i; j<=k; j++)
     { left /= 1 + a[i];
       right /= a[i];
     }
    a[i]++;
  } while(ok);
}

int main()
{
  cin >> n;
  k = 1;
  while (n > (1<<k)) k++;
  okk = false;
  while (!okk)
  {
    a[0] = 1;
    for (int i = 1; i < 30; i++) a[i] = 0;
    next(1, k);
    k++;
  }
  cout << k - 1 << endl;
  return 0;
}