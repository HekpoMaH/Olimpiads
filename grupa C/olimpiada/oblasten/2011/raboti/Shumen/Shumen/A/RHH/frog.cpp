#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int a[16] , b[16];
int c[16];

void read() {
    int i;
    
    scanf ( "%d" , &n );
    for (i = 1; i <= 2 * n; i++)
        scanf ( "%d%d" , &a[i] , &b[i] );
}

int go ( int put , int x , int y ) {
    if ( put == n )
        return 0;

    int ans = 1 << 30;
    int i;
    
    for (i = 1; i <= 2 * n; i++)
        if ( !c[i] ) {
            c[i] = 1;
            ans = min ( ans , go ( put + 1 , a[i] , b[i] ) + max ( abs ( x - a[i] ) , abs ( y - b[i] ) ) );
            c[i] = 0;
        }
        
    return ans;
}

void solve() {
    printf ( "%d\n" , go ( 0 , 0 , 0 ) );
}

int main() {
    read();
    solve();
    
    return 0;
}
