//Task: war
//Author: Momchil Ivanov

#include <stdio.h>

#define MAXN 1000005
#define INF 2000000000

#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))

typedef struct TEdge {
	int to, l, next;
} TEdge;

typedef struct TIndexedValue {
	int v, i;
} TIndexedValue;

int n;
TEdge graph[MAXN * 2];
int head[MAXN];
int level[MAXN];
int parent[MAXN];
TIndexedValue min1[MAXN], min2[MAXN], max1[MAXN], max2[MAXN];
int sol_min[MAXN], sol_max[MAXN];

void readInput() {
	int i, gn = -1;
	int x, y, l;

	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		head[i] = -1;
		level[i] = 0;
	}

	for (i = 0; i < n-1; i++) {
		scanf("%d %d %d", &x, &y, &l);
		gn++;
		graph[gn].to = y;
		graph[gn].l = l;
		graph[gn].next = head[x];
		head[x] = gn;

		gn++;
		graph[gn].to = x;
		graph[gn].l = l;
		graph[gn].next = head[y];
		head[y] = gn;

		level[x]++;
		level[y]++;
	}
}

void dfs(int c) {
	int i = head[c], flag = 1;
	while (i != -1) {
		if (parent[c] != graph[i].to) {
			flag = 0;
			parent[graph[i].to] = c;
			dfs(graph[i].to);

			if (min1[graph[i].to].v + graph[i].l < min1[c].v) {
				min2[c] = min1[c];
				min1[c].v = min1[graph[i].to].v + graph[i].l;
				min1[c].i = graph[i].to;
			} else if (min1[graph[i].to].v + graph[i].l < min2[c].v) {
				min2[c].v = min1[graph[i].to].v + graph[i].l;
				min2[c].i = graph[i].to;
			}

			if (max1[graph[i].to].v + graph[i].l > max1[c].v) {
				max2[c] = max1[c];
				max1[c].v = max1[graph[i].to].v + graph[i].l;
				max1[c].i = graph[i].to;
			} else if (max1[graph[i].to].v + graph[i].l > max2[c].v) {
				max2[c].v = max1[graph[i].to].v + graph[i].l;
				max2[c].i = graph[i].to;
			}
		}
		i = graph[i].next;
	}

	if (flag) {
		min1[c].v = 0;
		max1[c].v = 0;
	}
}

void dfs2(int c, int up_min, int up_max) {
	int i = head[c], to_pass_min, to_pass_max, flag = 1;

	sol_min[c] = min(up_min, min1[c].v);
	sol_max[c] = max(up_max, max1[c].v);

	while (i != -1) {
		if (parent[c] != graph[i].to) {
			flag = 0;

			if (min1[c].i != graph[i].to) {
				to_pass_min = min(up_min, min1[c].v);
			} else {
				to_pass_min = min(up_min, min2[c].v);
			}

			if (max1[c].i != graph[i].to) {
				to_pass_max = max(up_max, max1[c].v);
			} else {
				to_pass_max = max(up_max, max2[c].v);
			}

			dfs2(graph[i].to, to_pass_min + graph[i].l, to_pass_max + graph[i].l);
		}
		i = graph[i].next;
	}

	if (flag) {
		sol_min[c] = up_min;
		sol_max[c] = up_max;
	}
}

void solve() {
	int i, root;
	TIndexedValue minlost;
	for (i = 1; i <= n; i++)
		if (level[i] > 1) {
			root = i;
			break;
		}

	for (i = 1; i <= n; i++) {
		parent[i] = -1;
		min1[i].v = INF;
		min2[i].v = INF;
		max1[i].v = -INF;
		max2[i].v = -INF;
	}

	dfs(root);
	dfs2(root, INF, -INF);

	minlost.v = INF;
	for (i = 1; i <= n; i++) {
		if (sol_max[i] - sol_min[i] < minlost.v) {
			minlost.v = sol_max[i] - sol_min[i];
			minlost.i = i;
		}
	}

	printf("%d %d\n", minlost.i, minlost.v);
}

int main () {
	readInput();
	solve();
}
