/*
TASK:money
LANG:C++
*/ 
#include <cstdio>
#include <algorithm>
using namespace std;
int n, a[1 << 20]; 
void scan(){
    scanf("%d", &n);
    for ( int i = 0; i < n; ++i )
        scanf("%d", &a[i]);
}
void solve(){
    sort(a, a + n);
    int l = 0, r = 2, ans = 1;
    while ( r < n ){ 
        if ( a[l] + a[l + 1] > a[r] ){
            if ( ans < r - l ) ans = r - l;
            ++r;continue;
        }
        else
            if ( r - l == 2 ){++l; ++r;}
            else ++l;
    }
    ++ans;
    if ( ans < 3 ) ans = 1;
    printf("%d\n", ans );
}
int main(){
    scan();
    solve();
}
