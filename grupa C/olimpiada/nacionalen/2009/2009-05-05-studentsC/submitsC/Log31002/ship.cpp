/*
TASK: ship
LANG: C++
*/
#include <iostream>
using namespace std;
struct bidon 
{
       long long v;
       long long p;
};

bidon a[10002];
long long x, n, i, minsum;

void scan ()
{
     scanf ("%d", &n);
     for( i=1; i<=n; i++ )
     {
          scanf ("%d", &x);
          a[i].v = x;
     }
     for( i=1; i<=n; i++ )
     {
          scanf ("%d", &x);
          a[i].p = x + 1;
     }  
}

void solve ()
{
     for( i=1; i<=n; i++ )
          if( a[i].p != i )
          {
              long long v1, v2, p1;
              v1 = a[i].v;
              p1 = a[i].p;
              v2 = a[p1].v;
              minsum += v1;
              minsum += v2;
              a[i].v = a[p1].v;
              a[i].p = a[p1].p;
              a[p1].v = v1;
              a[p1].p = p1;
          }
     cout << minsum << endl;
}

main ()
{
     scan ();
     solve ();
     exit (0);
}
// o.O
