#include <ctime>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <sstream>
#include <map>
#include <set>
#include <cstdio>
#include <bitset>
using namespace std;
#define pb push_back
#define INF 1000000000
#define L(s) (int)((s).end()-(s).begin())
#define FOR(i,a,b) for (int _n(b), i(a); i <= _n; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define rep(i,n) FOR(i,1,(n))
#define rept(i,n) FOR(i,0,(n)-1)
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))
#define ppb pop_back

struct edge
{
	int a, b, s, g;
	edge() {}
	edge (int _a, int _b, int _s, int _g) : a(_a), b(_b), s(_s), g(_g) {}
};

struct cedge
{
	int v, g;
	bool used;
	cedge(){}
	cedge(edge e, int from)
	{
		used = false;
		if (from == 0)
			v = e.b;
		else
			v = e.a;
		g = e.g;
	}
};

inline bool operator < (const edge & u, const edge & v)
{
	if (u.s < v.s) return true;
	if (u.s > v.s) return false;

	if (u.g < v.g) return true;
	if (u.g > v.g) return false;
	
	if (u.a < v.a) return true;
	if (u.a > v.a) return false;
	
	return u.b < v.b;
}

vector<vector<cedge> > G;

vector<bool> used;

int stop;

bool dfs(int u, int pred)
{
	if (used[u]) {
		stop = u;
		return true;
	}

	used[u] = true;

	rept(i, L(G[u]))
		if (pred != G[u][i].v)
			if (dfs(G[u][i].v, u))
			{
				G[u][i].used = true;

				if (u == stop)	return false;
				else			return true;
			}

	return false;
}

int main()
{
	
	int n, m, csilver, cgold;
	scanf("%d%d%d%d", &n, &m, &csilver, &cgold);

	vector<edge> E(m);

	rept(i, m)
	{
		int x, y, s, g;
		scanf("%d%d%d%d", &x, &y, &s, &g);
		x--; y--;
		E[i] = edge(x, y, s, g);
	}

	SORT(E);

	used.assign(n, false);
	G.resize(n);

	rept(i, L(G))
		G[i].reserve(n);


	long long res = 9000000000000000000LL;

	rept(it, L(E))
	{
		int s = E[it].s, fs;

		// looking for exact match for current edge
		bool em = false;

		int a = E[it].a,
			b = E[it].b;

		rept(i, L(G[a]))
			if (G[a][i].v == b)
			{
				G[a][i].g = min(G[a][i].g, E[it].g);

				rept(j, L(G[b]))
					if (G[b][j].v == a)
						G[b][j].g = G[a][i].g;

				em = true;
				break;
			}

		if (!em) 
		{
			//removing max weight edge if cycle exists
			G[a].pb(cedge(E[it], 0));
			G[b].pb(cedge(E[it], 1));

			rept(i, L(G))
				rept(j, L(G[i]))
					G[i][j].used = false;

			used.assign(n, false);
			stop = -1;

			rept(i, n)
				if (!used[i] && stop == -1)
					dfs(i, -1);

			if (stop != -1)
			{
				int mx = -INF;
				rept(i, L(G))
					rept(j, L(G[i]))
						if (G[i][j].used)
							mx = max(mx, G[i][j].g);

				rept(i, L(G))
					rept(j, L(G[i]))
						if (G[i][j].used)
							if (mx == G[i][j].g)
							{
								int v = G[i][j].v;

								swap(G[i][j], G[i][L(G[i]) - 1]);
								G[i].pop_back();

								rept(k, L(G[v]))
									if (G[v][k].v == i)
									{
										swap(G[v][k], G[v][L(G[v]) - 1]);
										G[v].pop_back();
										break;
									}

								i = INF;
								j = INF;

								break;
							}
			}
		}

		int count = 0;
		rept(i, L(G))
			count += L(G[i]);

		if (count == 2 * (n - 1))
		{
			fs = -INF;
			rept(i, L(G))
				rept(j, L(G[i]))
					fs = max(fs, G[i][j].g);

			res = min(res, (long long)(s) * csilver + (long long)(fs) * cgold);
		}
	}

	if (res == 9000000000000000000LL) cout << -1 << endl;
	else						  	  cout << res << endl;
	
	return 0;
}