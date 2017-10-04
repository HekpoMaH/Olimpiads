/*
TASK:ship
lang:C++
*/ 
#include <cstdio>
#include <algorithm>
using namespace std;
int n, a[1 << 14], c[1 << 14];
void scan(){
    scanf("%d", &n);
    for ( int i = 0; i < n; ++i )
        scanf("%d", &a[i]);
    for ( int i = 0; i < n; ++i )
        scanf("%d", &c[i]);
}
long long greedymin(){
    int b[n + 2], d[n + 2], used[n + 2], rez = 0;
    memset(used, 0, sizeof(used));
    for ( int i = 0; i < n; ++i ){
        b[i] = a[i];d[i] = c[i];
    }
    for ( int k = 0; k < n - 1; ++k ){
        int mx = 0, j = 0;
        for ( int i = 0; i < n; ++i )
            if ( !used[i] && i != c[i] && (b[i] > mx || (b[i] == mx && b[c[j]] > b[c[i]]))){
                mx = b[i];
                j = i;
            }
        used[c[j]] = 1;rez += b[j]; rez += b[c[j]];
        swap(b[j], b[c[j]]);
        swap(c[j], c[c[j]]);
    }
    return rez;
}
long long greedymax(){
    int b[n + 2], d[n + 2], used[n + 2], rez = 0;
    memset(used, 0, sizeof(used));
    for ( int i = 0; i < n; ++i ){
        b[i] = a[i];d[i] = c[i];
    }
    for ( int k = 0; k < n - 1; ++k ){
        int mx = 999999, j = 0;
        for ( int i = 0; i < n; ++i )
            if ( !used[i] && (b[i] < mx || (b[i] == mx && b[c[j]] > b[c[i]]))){
                mx = b[i];
                j = i;
            }
      used[c[j]] = 1;rez += b[j]; rez += b[c[j]];
        swap(b[j], b[c[j]]);
        swap(c[j], c[c[j]]);
    }
    return rez;
}
long long notgreedy(){
    int b[n + 2], d[n + 2], used[n + 2], rez = 0;
    memset(used, 0, sizeof(used));
    for ( int i = 0; i < n; ++i ){
        b[i] = a[i];d[i] = c[i];
    }
    for ( int k = 0; k < n - 1; ++k ){
        int mx = 999999, j = 0;
        for ( int i = 0; i < n; ++i )
            if ( !used[i] ){
                mx = b[i];
                j = i;break;
            }
        used[c[j]] = 1;rez += b[j]; rez += b[c[j]];
        swap(b[j], b[c[j]]);
        swap(c[j], c[c[j]]);
    }
//    for ( int i = 0; i < n; ++i )
  //      printf("%d ", b[i]);
//    printf("\n");
    return rez;
}
void solve(){
    long long mn = 100 * 1000000;
    mn = greedymin();
  //  printf("%d\n", mn);
    mn = min(mn, greedymax());
   // printf("%d", mn);
    mn = min(mn, notgreedy());
  //  printf("%d", mn);
    long long s = 0;
    for ( int i = 0; i < n; ++i )
        s += a[i];
    s *= 2;
    mn = min(s, mn);
    printf("%d\n", mn);
}
int main(){
    scan();
    solve();
}
