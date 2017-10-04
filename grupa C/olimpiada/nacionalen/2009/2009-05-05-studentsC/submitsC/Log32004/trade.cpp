/*
TASK: trade
LANG: C++
*/

#include <iostream>
using namespace std;
int n, x, y, i;
double t;
pair <int, pair <int, double> > a[100002];

main ()
{
     scanf ("%d", &n);
     for( i=1; i<=n; i++ ) 
     {
          scanf ("%d%d%f", &x, &y, &t);
          a[i].first = x;
          a[i].second.first = y;
          a[i].second.second = t;
     }
     sort( a+1, a+n+1 );
     for( i=1; i<=n; i++ )
     {
     }     
     cout << "too many" << endl;
     exit (0);
}
