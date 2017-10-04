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
int head[MAXN], level[MAXN], parent[MAXN], dist[MAXN];
int dist_min, dist_max;
TIndexedValue answ;

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
		if (graph[i].to != parent[c]) {
			flag = 0;
			parent[graph[i].to] = c;
			dist[graph[i].to] = dist[c] + graph[i].l;
			dfs(graph[i].to);
		}
		i = graph[i].next;
	}
	if (flag) {
		dist_min = min(dist_min, dist[c]);
		dist_max = max(dist_max, dist[c]);
	}
}

void solve() {
	int i, j;

	answ.v = INF;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) parent[j] = -1;
		dist[i] = 0;
		dist_min = INF;
		dist_max = -1;
		dfs(i);
		if (dist_max - dist_min < answ.v) {
			answ.v = dist_max - dist_min;
			answ.i = i;
		}
	}
	
	printf("%d %d\n", answ.i, answ.v);
}

int main () {
	readInput();
	solve();
}