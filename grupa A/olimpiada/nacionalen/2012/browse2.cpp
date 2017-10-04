/*
TASK: browse
LANG: C++
*/
#include <iostream>
#include <stdio.h>
#include <queue>
#include <algorithm>
#include <string.h>
#include <math.h>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int MAXN = 1 << 9;
const int MAXV = 1 << 10;
const int INF = 1 << 30;

struct el {
    int to, rd, prv;

    el() {}
    el(int _to, int _rd, int _prv): to(_to), rd(_rd), prv(_prv) {}
};

int n, m, k;
PII sh[MAXN], kosh[MAXN];
int d[MAXN][MAXN];
int D[250100], dlen;

int source, sink;
int idx[MAXV], cpy[MAXV];
int level[MAXV];
el g[502100];
int sz;

inline int dist(PII a, PII b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

void init() {
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 1; i <= n; i ++)
        scanf("%d %d", &sh[i].x, &sh[i].y);
    for(int i = 1; i <= m; i ++)
        scanf("%d %d", &kosh[i].x, &kosh[i].y);
/*
    cout << "sheeps\n";
    for(int i = 1; i <= n; i ++)
        cout << sh[i].x << " " << sh[i].y << endl;

    cout << endl;
    cout << "koshari\n";
    for(int i = 1; i <= m; i ++)
        cout << kosh[i].x << " " << kosh[i].y << endl;
    cout << endl;
*/
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++) {
            d[i][j] = dist(sh[i], kosh[j]);
            D[dlen] = d[i][j];
            dlen ++;
        }
    sort(D, D + dlen);
/*
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++)
            cout << d[i][j] << " ";
        cout << endl;
    }
*/
    source = 0;
    sink = n + m + 1;
}

void add(int a, int b, int c) {
    //cout << a << " " << b << " " << c << endl;
    g[sz] = el(b, c, idx[a]);
    idx[a] = sz ++;

    g[sz] = el(a, 0, idx[b]);
    idx[b] = sz ++;
}

void build(int X) {
    memset(idx, -1, sizeof(idx));
    sz = 0;

    //cout << endl;
    //cout << "Build " << x << endl;

    for(int i = 1; i <= n; i ++)
        add(source, i, 1);
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
            if(d[i][j] <= X)
                add(i, n + j, 1);
    for(int i = 1; i <= m; i ++)
        add(i + n, sink, k);
}

bool bfs() {
    queue<int> q;
    memset(level, -1, sizeof(level));

    q.push(sink);
    level[sink] = 0;
    while(!q.empty()) {
        int tmp = q.front();
        q.pop();

        if(tmp == source) return true;

        for(int i = idx[tmp]; i != -1; i = g[i].prv)
            if(level[ g[i].to ] == -1 && g[i ^ 1].rd) {
                level[ g[i].to ] = level[tmp] + 1;
                q.push(g[i].to);
            }
    }

    return level[source] != -1;
}

int dfs(int cur, int flow) {
    if(cur == sink)
        return flow;

    for(int &i = cpy[cur]; i != -1; i = g[i].prv)
        if(level[cur] - 1 == level[ g[i].to ] && g[i].rd) {
            int fl = dfs(g[i].to, min(flow, g[i].rd));
            if(fl) {
                g[i].rd -= fl;
                g[i ^ 1].rd += fl;
                return fl;
            }
        }

    level[cur] = -42;
    return 0;
}

int dinitz() {
    int maxFlow = 0, curFlow;
    while(bfs()) {
        memcpy(cpy, idx, sizeof(idx));
        while(curFlow = dfs(source, INF))
            maxFlow += curFlow;
    }
    //cout << maxFlow << endl;
    return maxFlow;
}

void solve() {
    //cout << "go\n";

    int le = 0, ri = dlen - 1, mid;
    int ans = -1;
    while(le <= ri) {
        mid = (le + ri) >> 1;
        build(D[mid]);
        if(dinitz() >= n) {
            ans = D[mid];
            ri = mid - 1;
        }
        else le = mid + 1;
    }

    //cout << ans << endl;
    printf("%.6lf\n", sqrt(ans));
}

int main()
{
    init();
    solve();

    return 0;
}
