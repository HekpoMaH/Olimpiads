#include<bits/stdc++.h>

#define MAX 52
#define MASK 4096
#define INF 999666333

using namespace std;
FILE* in; FILE* out;

struct Edge
{
	int to, price;
	Edge(int initTo = 0, int initPrice = 0) {to = initTo; price = initPrice;}
	bool operator < (const Edge& r) const {return price != r.price ? price > r.price : to < r.to;}
};

int n, m;
vector <Edge> v[MAX][13];
int dyn[MAX][13][MASK];

int recurse(int node, int rem, int mask)
{
	if (node == n) return 0;
	if (dyn[node][rem][mask] != -1) return dyn[node][rem][mask];

	int ans = INF;
	for (int i = 1; i < 13; i++) if (!(mask & (1 << (i - 1))))
	{
		int idx = (i - rem + 13) % 13;
		for (int c = 0; c < (int)v[node][idx].size(); c++)
			ans = min(ans, recurse(v[node][idx][c].to, i, mask | (1 << (i - 1))) + v[node][idx][c].price);
	}
	return dyn[node][rem][mask] = ans;
}

int dijkstra(int startNode, int endNode)
{
	static int dist[MAX];
	memset(dist, 111, sizeof(dist));
	Edge cur, nxt;
	priority_queue <Edge> q;
	nxt.to = startNode; nxt.price = 0;
	q.push(nxt); dist[nxt.to] = nxt.price;
	while (!q.empty())
	{
		cur = q.top(); q.pop();
		if (dist[cur.to] == -1) continue;
		if (cur.to == endNode) return dist[cur.to];
		dist[cur.to] = -1;

		for (int i = 0; i < 13; i++)
		{
			for (int c = 0; c < (int)v[cur.to][i].size(); c++)
			{
				nxt.to = v[cur.to][i][c].to;
				nxt.price = v[cur.to][i][c].price + cur.price;
				if (nxt.price < dist[nxt.to])
				{
					dist[nxt.to] = nxt.price;
					q.push(nxt);
				}
			}
		}
	}
	return INF;
}

int main(void)
{
	in = stdin; out = stdout;
//	in = fopen("Friday.in", "rt"); out = fopen("Friday.out", "wt");

	int numTests;
	fscanf(in, "%d", &numTests);

	for (int test = 0; test < numTests; test++)
	{
		fscanf(in, "%d %d", &n, &m);
		for (int i = 0; i < MAX; i++)
			for (int c = 0; c < 13; c++)
				v[i][c].clear();

		for (int i = 0; i < m; i++)
		{
			int from, to, price;
			fscanf(in, "%d %d %d", &from, &to, &price);
			v[from][price % 13].push_back(Edge(to, price));
		}

		char type[16];
		fscanf(in, "%s", &type);

		int ans;
		if (type[0] == 'T')
		{
			memset(dyn, -1, sizeof(dyn));
			ans = recurse(1, 0, 0);
		}
		else
			ans = dijkstra(1, n);
		fprintf(out, "%d\n", ans >= INF ? -1 : ans);
	}
	return 0;
}
