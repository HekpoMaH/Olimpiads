#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const long long INF = 1LL << 62;

char a[64];

vector < long long > f[64][64];

void read() {
    scanf ( "%s" , a );
}

inline long long calc ( long long a , long long b , char sign ) {
    if ( sign == '*' ) return a * b;
    if ( sign == '-' ) return a - b;
    if ( sign == '+' ) return a + b;
    return 42;
}

void init ( int l , int r ) {
    if ( (int)f[l][r].size() ) return ;
    if ( l == r ) {
        f[l][r].push_back ( a[l] - '0' );
        return ;
    }
    
    int i , j , k;
    
    for (i = l + 1; i < r; i += 2) {
        init ( l , i - 1 );
        init ( i + 1 , r );
        
        for (j = 0; j < (int)f[l][i - 1].size(); j++)
            for (k = 0; k < (int)f[i + 1][r].size(); k++)
                f[l][r].push_back ( calc ( f[l][i - 1][j] , f[i + 1][r][k] , a[i] ) );
    }
}

void solve() {
    long long ans = INF;
    int i;
    int n = strlen ( a );
    
    init ( 0 , n - 1 );
     
    for (i = 0; i < (int)f[0][n - 1].size(); i++) 
        ans = min ( ans , f[0][n - 1][i] );
        
    cout << ans << '\n';
}

int main() {
    read();
    solve();
    
    return 0;
}
