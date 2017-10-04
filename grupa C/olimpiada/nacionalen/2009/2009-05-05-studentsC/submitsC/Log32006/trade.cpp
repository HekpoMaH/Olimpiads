/*
TASK: trade
LANG: C++
*/
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
struct edge{
    int x;
    double l;
};
int n, used[1 << 17];
double sum = 0, val[1 << 17];
vector <edge> v[1 << 17];
void scan(){
    edge t;
    scanf("%d", &n);
    int x, y;
    double l;
    for ( int i = 0; i < n; ++i ){
        scanf("%d%d", &x, &y); cin >> l;
        t.x = y;
        t.l = 2 * l;
        v[x].push_back(t);
        t.x = x;
        v[y].push_back(t);
    }
}
void dfs(int i, double ss){//cout << i << endl;
    used[i] = 1;
    ss *= -1;
    for ( int j = 0; j < v[i].size(); ++j ){
        if ( v[i][j].x == 1 )
            sum = ss + v[i][j].l;
        if ( !used[v[i][j].x] )
            dfs(v[i][j].x, ss + v[i][j].l);
    }
}
void makesum(double t, int i, double r){
    used[i] = 1;
    val[i] = r - t;
    for ( int j = 0; j < v[i].size(); ++j )
        if ( !used[v[i][j].x])
            makesum(val[i], v[i][j].x, v[i][j].l);
}
void solve(){
    dfs(1, 0);
    if ( n % 2 == 0 ){
        if ( sum == 0 ) cout << "too many\n";
        else cout << "impossible\n";
        return;
    }
    printf("%.2f", sum / 2.0);
    memset(used, 0, sizeof(used));
    used[1] = 1;
    makesum(sum/2.0, v[1][1].x, v[1][1].l);
    for ( int i = 2; i <= n; ++i )
     printf(" %.2f", val[i]);
    printf("\n");
}
int main(){
    scan();
    solve();
}
