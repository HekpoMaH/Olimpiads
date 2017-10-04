/*
TASK: odd
LANG: C++
*/
#include <iostream>
using namespace std;
unsigned long long n, x, ans;
main ()
{
     scanf ("%d", &n);
     for( int i=1;i<=n;i++ )
     {
          cin >> x;
          ans = (ans ^ x);
     }
     cout << ans << endl;
     exit (0);
}
// o.O
