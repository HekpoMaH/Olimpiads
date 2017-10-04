#include <set>
#include <cstdio>
using namespace std;

set <int> read;

int main ()
{
  int n, p; scanf ("%d", &n);
  for (int i = 0; i < n; ++i)
  {
    scanf ("%d", &p);
    pair <set<int> :: iterator, bool> ins = read.insert (p);
    if (!ins.second) read.erase (p);
  }

  set <int> :: iterator sii = read.begin ();
  printf ("%d ", *sii);
  ++sii;
  printf ("%d\n", *sii);
  return 0;
}
