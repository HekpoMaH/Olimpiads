/*
TASK:odd
LANG:C++
*/
#include <cstdio>
#include <algorithm>
using namespace std;
int n;
long long a[1 << 20];
void scan(){
     scanf("%d", &n); 
     for ( int i = 0; i < n; ++i )
         scanf("%lld", &a[i]);
}
void solve(){
     sort(a, a + n );
     long long p = a[0];
     int br = 1;
     a[n] = -1; ++n;
     for ( int i = 1; i < n; ++i )
         if ( a[i] == p )
            ++br;
         else{
              if ( br % 2 ){
                   printf("%lld\n", a[i - 1]);
                   return;
              }
              br = 1;
              p = a[i];
            }
}
int main(){
    scan();
    solve();
    return 0;
}
