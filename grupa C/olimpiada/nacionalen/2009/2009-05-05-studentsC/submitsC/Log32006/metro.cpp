/*
TASK:metro
LANG:C++
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
struct edge{
    int x, l;
};
struct vertex{
    int x, l;
    bool operator<(vertex t)const {
        if ( t.l < l ) return 1;
        return 0;
    }
};
priority_queue <vertex> q;
int n, a[1 << 13], d[1 << 21], used[ 1 << 21], last[1 << 21];
vector <edge> v[1 << 21];
void scan(){
    cin >> n;
    for ( int i = 0; i < n; ++i )
        scanf("%d", &a[i]);
}
inline int sqr(int x){
    return x * x;
}
void dijkstra(){
    vertex t;
    int p = ( 1 << 21 );
    for ( int i = 0; i < p; ++i )
        d[i] = 100000000;
    d[0] = 0;
    t.x = 0;
    t.l = 0;
    q.push(t);
    while(!q.empty()){
        t = q.top();
        q.pop();
        if ( used[t.x] == 1 ) continue;
        used[t.x] = 1;
        for ( int i = 0; i < v[t.x].size(); ++i )
            if ( !used[v[t.x][i].x] && d[v[t.x][i].x] > d[t.x] + v[t.x][i].x ){
                d[v[t.x][i].x] = d[t.x] + v[t.x][i].l;
                vertex t1;
                t1.x = v[t.x][i].x;
                t1.l = d[t1.x];
                last[t1.x] = t.x;
                q.push(t1);
        }
    }
}
void solve(){
    edge t;
    for ( int j = 1; j < 100; ++j ){
        t.x = 1000 + j;
        if ( j == a[0] ) t.l = 0;
        if ( j < a[0] ) t.l = sqr( a[0] - j );
        if ( j > a[0] ) t.l = 7 * ( j - a[0]);
        v[0].push_back(t);
    }
    for ( int i = 0; i < n - 1; ++i )
        for ( int j = 1; j < 100; ++j ){
            int q = (i + 1) * 1000 + j;
            if ( j > 0 ){
                int p = j - 1;
                t.x = (i + 2) * 1000 + p;
                if ( p == a[i + 1] ) t.l = 1;
                if ( p < a[i + 1] ) t.l = sqr( a[i + 1] - p );
                if ( p > a[i + 1] ) t.l = 7 * ( p - a[i + 1]);
                v[q].push_back(t);
            }
            if ( j > 1 ){
                int p = j - 2;
                t.x = (i + 2) * 1000 + p;
                if ( p == a[i + 1] ) t.l = 1;
                if ( p < a[i + 1] ) t.l = sqr( a[i + 1] - p );
                if ( p > a[i + 1] ) t.l = 7 * ( p - a[i + 1]);
                v[q].push_back(t);
            }
                int p = j;
                t.x = (i + 2) * 1000 + p;
                if ( p == a[i + 1] ) t.l = 1;
                if ( p < a[i + 1] ) t.l = sqr( a[i + 1] - p );
                if ( p > a[i + 1] ) t.l = 7 * ( p - a[i + 1]);
                v[q].push_back(t);
            
            if ( j < 99 ){
                int p = j + 1;
                t.x = (i + 2) * 1000 + p;
                if ( p == a[i + 1] ) t.l = 1;
                if ( p < a[i + 1] ) t.l = sqr( a[i + 1] - p );
                if ( p > a[i + 1] ) t.l = 7 * ( p - a[i + 1]);
                v[q].push_back(t);
            }
    }
    dijkstra();
    int mn = 999999999;
    int cc;
    for ( int i = 1; i < 100; ++i )
        if ( mn > d[n * 1000 + i] ){ mn = d[n * 1000 + i];cc = n * 1000 + i;}
    cout << mn << endl;
}
int main(){
    scan();
    solve();
}
