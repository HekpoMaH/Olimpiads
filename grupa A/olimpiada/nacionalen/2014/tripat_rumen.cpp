#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector< pair<int,int> > a[1 << 20];
int lvl[1 << 20], path[1 << 20];
int p[1 << 20][22];

void read() {
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        int p, c;
        
        scanf("%d%d", &p, &c);
        a[p].push_back(make_pair(i, c));
    }
}

void dfs(int x, int y) {
    path[x] = y;
    
    for (int i = 1; i < 21; i++) {
        p[x][i] = p[ p[x][i - 1] ][i - 1];
    }
    
    for (int i = 0; i < (int)a[x].size(); i++) {
        lvl[ a[x][i].first ] = lvl[x] + 1;
        p[a[x][i].first][0] = x;
        dfs(a[x][i].first, y + a[x][i].second);
    }
}

void solve() {
    lvl[1] = 0;
    dfs(1, 0);
    int q;
    exit(0);
    scanf("%d", &q);
    while (q --) {
        int w, e, t;
        int c1, c2, c3;
        
        scanf("%d%d%d", &w, &e, &t);
        c1 = path[w];
        c2 = path[e];
        
        for (int i = 20; i >= 0; i--) {
            if (lvl[w] - (1 << i) >= lvl[e]) {
                w = p[w][i];
            }
            if (lvl[e] - (1 << i) >= lvl[w]) {
                e = p[e][i];
            }
        }
        
        for (int i = 20; i >= 0; i--) {
            if (p[w][i] != p[e][i]) {
                w = p[w][i];
                e = p[e][i];
            }
        }
        
        if (w != e) {
            w = p[w][0];
        }
        
        c3 = path[w];
        
        c1 -= c3;
        c2 -= c3;
        
        int ans = c3 + c1 + c1 + c2;
        ans = min(ans, c1 + c3 + t);
        ans = min(ans, c3 + 2 * t + c2);
        ans = min(ans, t + c1 + c2);
        
        printf ("%d\n", ans);
    }
}

int main() {
    read();
    solve();
    
    return 0;
}
