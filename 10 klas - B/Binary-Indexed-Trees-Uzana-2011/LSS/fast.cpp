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

int getMax(int p)
{ int res = d[p];
  for(int i=p & (p-1); i>0; i = i & (i-1))
    if(res<d[i]) res = d[i];
  return res;
}

void update(int p, int x)
{ for(int i = p; i<=n; i = i + (i & (-i)))
    if(d[i]<x) d[i] = x;
}

int main()
{ cout << "n = "; cin >> n;
  gen(n);
  if(n<21) show();

  for(int i=1; i<=n; i++)
    d[i]=0;

  for(int i=1; i<=n; i++)
    update(a[i],1+getMax(a[i]));

  int dmax = d[1];
  for(int i=2; i<=n; i++)
    if(dmax<d[i]) dmax = d[i];
  cout << dmax << endl;

  return 0;
}

