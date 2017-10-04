/*
TASK: diet
LANG: C++
*/

#include <iostream>
using namespace std;
int x1, x2, x3, c, ans;

main ()
{
     scanf ("%d%d%d", &x1, &x2, &x3);
     
     if( x1 >= x2 && x2 >= x3 )
     {
         while (1)
         {
               if( x1 - 2 < x2 + 1 ) break;
               x1 -= 2;
               x2 ++;
         }
         while (1)
         {
               if( x2 - 1 < x3 + 1 ) break;
               x2 --;
               x1 --;
               x3 ++;
         }
         ans = min( x1, x2 );
         ans = min( ans, x3 );
     }
     
     else 
     
     if( x1 >= x2 && x1 >= x3 && x3 >= x2 )
     {
         while (1)
         {
               if( x1 - 2 < x2 + 1 ) break;
               x1 -= 2;
               x2 ++;
         }
         while (1)
         {
               if( x3 - 1 < x2 + 1 ) break;
               c ++;
               x3 --;
               x1 ++;
               x2 ++;
         }
         ans = min( x1, x2 );
         ans = min( ans, x3 );
     }
     
     else
     
     if( x2 >= x1 && x2 >= x3 && x1 >= x3 )
     {
         while (x1 > x3)
         {
               x1 --;
               x2 --;
               x3 ++;
         }
         while (1)
         {
               if( x2 - 1 < x1 + 2 ) break;
               c ++;
               x2 --;
               x1 += 2;
         }
         ans = min( x1, x2 );
         ans = min( ans, x3 );
     }
     
     else
     
     if( x2 >= x1 && x2 >= x3 && x3 >= x1 )
     {
         while ( x2 > x1 )
         {
               c ++;
               x2 --;
               x1 += 2;
         }
         while (1)
         {
               if( x1 - 1 < x3 + 1 ) break;
               x1 --;
               x2 --;
               x3 ++;
         }
         ans = min( x1, x2 );
         ans = min( ans, x3 );   
     }
     
     else
     
     if( x3 >= x1 && x3 >= x2 && x2 >= x1 )
     {
         while (1)
         {
               if( x3 - 1 < x2 + 1 ) break;
               c ++;
               x3 --;
               x1 ++;
               x2 ++;
         }
         while (x2 > x1)
         {
               c ++;
               x2 --;
               x1 += 2;
         }
         ans = min( x1, x2 );
         ans = min( ans, x3 );
     }
     
     else 
     
     if( x3 >= x1 && x3 >= x2 && x1 >= x2 )
     {
         while (1)
         {
               if( x3 - 1 < x1 + 1 ) break;
               c ++;
               x3 --;
               x1 ++;
               x2 ++;
         }
         while (1)
         {
               if( x1 - 2 < x2 + 1 ) break;
               x1 -= 2;
               x2 ++;
         }
         ans = min( x1, x2 );
         ans = min( ans, x3 );
     }
     printf ("%d %d\n", ans, c);
     exit (0);
}
