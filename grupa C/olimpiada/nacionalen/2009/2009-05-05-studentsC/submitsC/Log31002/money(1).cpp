/*
TASK: money
LANG: C++
*/
#include <iostream>
using namespace std;
long long a[262144], n, i, j, mx, sum;

void scan ()
{
     scanf ("%d", &n);
     for( i=1;i<=n;i++ ) 
          scanf ("%d", &a[i]);
}

main ()
{
     scan ();
     if( n <= 10000 ) {
     sort( a+1, a+n+1 );
     a[n+1] = 2000000;
     
     for( i=1; i <= n-2; i ++ )
          if( n - i + 1 > mx )
          {
              int sum = a[i] + a[i+1];
              for( j=i+2; j<=n+1; j++ )
              {
                   if( a[j] >= sum ) 
                   {
                       j --;
                       mx = max( j - i + 1, mx );
                       break;
                   }
              } 
          }
          
     if( mx == 2 ) mx = 1; 
     cout << mx << endl;
     }
     else
     {
         sort( a+1, a+n+1 );
         a[n+1] = 2000000;
         sum = a[1] + a[2];
         for( i=3; i<=n; i++ ) 
              if( a[i] >= sum )
              {
                  i --;
                  mx = max( i, mx );
                  break;
              }
         if( mx == 2 ) mx = 1;
         cout << mx << endl;
     }
     exit (0);
}
// o.O 
