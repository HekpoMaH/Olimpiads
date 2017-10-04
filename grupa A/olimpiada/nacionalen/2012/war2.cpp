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
int head[MAXN], level[MAXN], parent[MAXN];
TIndexedValue min1[MAXN], min2[MAXN], max1[MAXN], max2[MAXN];
int sol_min[MAXN], sol_max[MAXN];
int stack[MAXN];
int stack_size;
int indexes[MAXN], efp[MAXN]; // efp == (length of) edge from parent
int minfp[MAXN], maxfp[MAXN]; // minfp == min from parent, maxfp == max from parent

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

void dfs(int root) {
	int i, c, p;

	stack_size = 1;
	stack[stack_size-1] = root;
	indexes[root] = head[root];
	parent[root] = -1;

	while (stack_size) {
		c = stack[stack_size-1];
		if (indexes[c] != -1) {
			i = indexes[c];
			if (parent[c] != graph[i].to) {
				parent[graph[i].to] = c;
				efp[graph[i].to] = graph[i].l;
				indexes[graph[i].to] = head[graph[i].to];
				stack[stack_size++] = graph[i].to;
			}
			indexes[c] = graph[i].next;
		} else {
			if (parent[c] != -1) {
				if (level[c] == 1) {
					min1[c].v = 0;
					max1[c].v = 0;
				}

				p = parent[c];

				if (min1[c].v + efp[c] < min1[p].v) {
					min2[p] = min1[p];
					min1[p].v = min1[c].v + efp[c];
					min1[p].i = c;
				} else if (min1[c].v + efp[c] < min2[p].v) {
					min2[p].v = min1[c].v + efp[c];
					min2[p].i = c;
				}

				if (max1[c].v + efp[c] > max1[p].v) {
					max2[p] = max1[p];
					max1[p].v = max1[c].v + efp[c];
					max1[p].i = c;
				} else if (max1[c].v + efp[c] > max2[p].v) {
					max2[p].v = max1[c].v + efp[c];
					max2[p].i = c;
				}
			}
			stack_size--;
		}
	}
}

void dfs2(int root) {
	int i, c, p;

	stack_size = 1;
	stack[stack_size-1] = root;
	indexes[root] = head[root];
	minfp[root] = INF;
	maxfp[root] = -INF;
	sol_min[root] = min1[root].v;
	sol_max[root] = max1[root].v;

	while (stack_size) {
		c = stack[stack_size-1];

		if (indexes[c] != -1) {
			i = indexes[c];
			if (parent[c] != graph[i].to) {;
				if (min1[c].i != graph[i].to) {
					minfp[graph[i].to] = min(minfp[c], min1[c].v) + graph[i].l;
				} else {
					minfp[graph[i].to] = min(minfp[c], min2[c].v) + graph[i].l;
				}

				if (max1[c].i != graph[i].to) {
					maxfp[graph[i].to] = max(maxfp[c], max1[c].v) + graph[i].l;
				} else {
					maxfp[graph[i].to] = max(maxfp[c], max2[c].v) + graph[i].l;
				}

				sol_min[graph[i].to] = min(min1[graph[i].to].v, minfp[graph[i].to]);
				sol_max[graph[i].to] = max(max1[graph[i].to].v, maxfp[graph[i].to]);

				indexes[graph[i].to] = head[graph[i].to];
				stack[stack_size++] = graph[i].to;
			}
			indexes[c] = graph[i].next;
		} else {
			if (parent[c] != -1) {
				if (level[c] == 1) {
					sol_min[c] = minfp[c];
					sol_max[c] = maxfp[c];
				}
			}
			stack_size--;
		}
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
	dfs2(root);

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
