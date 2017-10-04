#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int NMAX = 1000000+10;

int   a[NMAX];
int   d[NMAX];

int n;

void gen(int n)
{// srand(time(0));
  for(int i=1; i<=n; i++)
    a[i] = 1 + rand()%n;
}

void show()
{ for(int i=1; i<=n; i++)
    cout << a[i] << " ";
  cout << endl;
}

int main()
{ cout << "n = "; cin >> n;
  gen(n);
  if(n<21) show();

  d[1]=1;
  for (int i = 2; i <= n; ++i)
  { int max = 0;
    for (int j = 1; j < i; j++)
      if (a[j] <= a[i] && max < d[j])
        max = d[j];
    d[i] = max + 1;
  }

  int dmax = d[1];
  for(int i=2; i<=n; i++)
    if(dmax<d[i]) dmax = d[i];
  cout << dmax << endl;

  return 0;
}

