/*
TASK: metro
LANG: C++
*/

#include <iostream>
using namespace std;
int a[1024], n, i;

main ()
{
     scanf ("%d", &n);
     for( i=1; i<=n; i++ ) 
          scanf ("%d", &a[i]);
     cout << n << endl;
     exit (0);
}
