#include <iostream>

#define p 1000000000

using namespace std;

__int64 n, f_1, f_2, ans, i;


void solve ()
{
    cin >> n;
    ans = 0;
    f_1 = 0;
    f_2 = 1;
    if ( n == 1 ) cout << f_1 << endl;
    else if ( n == 2) cout << f_2 << endl;
         else
         {
             for ( i = 3; i <= n; i++ )
             {
                ans = ( ( ( (i - 1) % p) * ( f_2 % p ) ) % p + ( ( (i - 1) % p) * ( f_1 % p ) ) % p ) % p;
                f_1 = f_2;
                f_2 = ans;
             }
            cout << ans << endl;
         }
}

int main ()
{
    int t;
    cin >> t;
    while ( t-- ) solve ();
    return 0;
}
