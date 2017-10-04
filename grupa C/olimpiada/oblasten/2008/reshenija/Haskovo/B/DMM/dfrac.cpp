#include<iostream>
#include<iomanip>
using namespace std;


void f ( long long a, long long b, long long k, int p )

{
    int t;
    int count = 1;
    do {
       if( a < b )
            { a *= 10;
              t = a / b;
              a = a - (t * b);
              if ( count >= k ) cout<< t;
              count++;
            }
       else {
             t = a / b;
             a = a - ( t * b );
            }
       }
    while ( count < k + p );
}
   
   
int main ()

{
    int p;
    long long a, b, k;
    cin>> a >> b;
    cin>> k >> p;
    f( a, b, k, p );
    cout << endl;
    return 0;
}
