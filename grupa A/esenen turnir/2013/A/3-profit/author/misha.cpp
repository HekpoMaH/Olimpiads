#include <cstdio>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;
#define mp make_pair
#define pb push_back
#define sc second
#define fs first
#define sz(a) ((int) (a).size())
const int N = (int) 1e6;
vector<int> adj[N];
int intime[N], outime[N], rmq[4 * N], upd[4 * N], who[N], curtime, n, m, u, v, w;
vector< pair< pair<int, int>, pair<int, int> > > e;

bool isparent(int u, int v) {
	return (intime[u] <= intime[v]) && (outime[v] <= outime[u]);
}

void dfs(int v, int p = -1) {
	intime[v] = curtime, who[curtime++] = v;
	for (int i = 0; i < sz(adj[v]); ++i)
		if (adj[v][i] != p)
			dfs(adj[v][i], v);
	outime[v] = curtime;
}

void add_rect(int x1, int x2, int y1, int y2, int w) {
	e.pb(mp(mp(x1, w), mp(y1, y2)));
	e.pb(mp(mp(x2, -w), mp(y1, y2)));
}

void update(int t, int l, int r, int x, int y, int delta) {
	if ((y <= l) || (r <= x)) return;
	if ((x <= l) && (r <= y)) {
		upd[t] += delta;
		rmq[t] += delta;
	} else {
		int m = (l + r) / 2;
		update(t * 2 + 1, l, m, x, y, delta);
		update(t * 2 + 2, m, r, x, y, delta);
		rmq[t] = max(rmq[t * 2 + 1], rmq[t * 2 + 2]) + upd[t];
	}
}

int get_max_pos(int t, int l, int r) {
	if (l + 1 == r) return l;
	int m = (l + r) / 2;
	if (rmq[t * 2 + 1] > rmq[t * 2 + 2])
		return get_max_pos(t * 2 + 1, l, m);
	else
		return get_max_pos(t * 2 + 2, m, r);
}

bool cmp_intime(int u, int v) {
	return intime[u] < intime[v];
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i + 1 < n; ++i) {
		scanf("%d%d", &u, &v), --u, --v;
		adj[u].pb(v), adj[v].pb(u);
	}
	for (int i = 0; i < n; ++i)
		if (sz(adj[i]) > 1) {
			dfs(i);
			break;
		}
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d", &u, &v, &w), --u, --v;
		if (intime[u] > intime[v]) swap(u, v);
		if (isparent(u, v)) {
			int nxt = upper_bound(adj[u].begin(), adj[u].end(), v, cmp_intime) - adj[u].begin() - 1;
			add_rect(0, intime[adj[u][nxt]], intime[v], outime[v], w);
			add_rect(intime[v], outime[v], outime[adj[u][nxt]], curtime, w);
		} else
			add_rect(intime[u], outime[u], intime[v], outime[v], w);
	}
	sort(e.begin(), e.end());
	int best = -1, pos_x = -1, pos_y = -1;
	for (int i = 0; i < sz(e); ++i) {
		update(0, 0, curtime, e[i].sc.fs, e[i].sc.sc, e[i].fs.sc);
		if (rmq[0] > best) {
			best = rmq[0];
			pos_x = who[e[i].fs.fs];
			pos_y = who[get_max_pos(0, 0, curtime)];
		}
	}	
	printf("%d %d %d\n", pos_x + 1, pos_y + 1, best);
	return 0;
}