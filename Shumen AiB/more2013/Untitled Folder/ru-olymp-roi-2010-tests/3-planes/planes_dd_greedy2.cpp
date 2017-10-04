#include <iostream>
#include <fstream>
#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <string>
#include <map>
#include <cstring>

using namespace std;

const int MAXN = 100000;
const int MAXD = 100000;

class Passenger
{
public:
	int l, r, t, id;
};

int n, k, m;
Passenger psg[MAXN];

void Load()
{
	scanf("%d%d%d", &n, &m, &k);
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%d%d%d", &psg[i].l, &psg[i].r, &psg[i].t);
		psg[i].id = i;
	}
}

bool operator<(const Passenger &a, const Passenger &b)
{
	return a.l < b.l;
}

class Psg
{
public:
	int r, id, t;
	Psg(int a, int b, int c) { r = a; id = b; t = c; }
};

bool operator<(const Psg &a, const Psg &b)
{
	if (a.r < b.r) return true;
	if (a.r > b.r) return false;
	if (a.t > b.t) return true;
	if (a.t < b.t) return false;
	return a.id < b.id;
}

const int TSIZE = 131072;
long long tmax[2 * TSIZE + 1];
long long tadd[2 * TSIZE + 1];
int result[MAXN];
int tl[2 * TSIZE + 1];
int tr[2 * TSIZE + 1];

void BT(int v)
{
	if (v >= TSIZE)
	{
		tl[v] = tr[v] = v - TSIZE + 1;
		return;
	}
	BT(v << 1);
	BT((v << 1) ^ 1);
	tl[v] = tl[v << 1];
	tr[v] = tr[(v << 1) ^ 1];
}

void FlushTAdd(int v)
{
	if (tadd[v] != 0)
	{
		if (v < TSIZE) 
		{
			tmax[v << 1] += tadd[v];
			tmax[(v << 1) ^ 1] += tadd[v];
			tadd[v << 1] += tadd[v];
			tadd[(v << 1) ^ 1] += tadd[v];
		}
		tadd[v] = 0;
	}
}

void TreeAdd(int v, int l, int r, int d)
{
	FlushTAdd(v);
	if (l == tl[v] && r == tr[v])
	{
		tadd[v] += d;
		tmax[v] += d;
		return;
	}
	if (l <= tr[v << 1])
	{
		TreeAdd(v << 1, l, min(r, tr[v << 1]), d);
	}
	if (r >= tl[(v << 1) ^ 1])
	{
		TreeAdd((v << 1) ^ 1, max(l, tl[(v << 1) ^ 1]), r, d);
	}
	tmax[v] = max(tmax[v << 1], tmax[(v << 1) ^ 1]);
}

void TreeFill(int p, long long v)
{
	int ver = 1;
	while (ver <= TSIZE - 1)
	{
		FlushTAdd(ver);
		if (p <= tr[ver << 1]) ver <<= 1;
		else ver = (ver << 1) ^ 1;
	}
	FlushTAdd(ver);
	tmax[ver] = v;
	while (ver > 1)
	{
		ver >>= 1;
		tmax[ver] = max(tmax[ver << 1], tmax[(ver << 1) ^ 1]);
	}
}

void Solve()
{
	sort(psg, psg + n);
	memset(tmax, 0, sizeof(tmax));
	memset(tadd, 0, sizeof(tadd));
	BT(1);
	int cd;
	int md = -1;
	int i;
	for (i = 0; i < n; i++) if (psg[i].r > md) md = psg[i].r;
	for (i = 1; i <= md; i++)
	{
		tmax[i + TSIZE - 1] -= ((long long)i) * ((long long)k);
	}
	for (i = TSIZE + md; i <= 2 * TSIZE; i++) tmax[i] = -2000000000000000000ll;
	for (i = TSIZE - 1; i >= 1; i--)
	{
		tmax[i] = max(tmax[i << 1], tmax[(i << 1) ^ 1]);
	}
	for (i = 0; i < n; i++)
	{
		if (psg[i].t == 1)
		{
			TreeAdd(1, psg[i].r, md, 1);
		}
	}
	set<Psg> have0;
	set<Psg> have1;
	have0.clear();
	have1.clear();
	int cp = 0;
	for (cd = 1; cd <= md; cd++)
	{
		while (cp < n && psg[cp].l == cd) 
		{
			if (psg[cp].t == 1) 
			{
				have1.insert(Psg(psg[cp].r, psg[cp].id, psg[cp].t));
			}
			else
			{
				have0.insert(Psg(psg[cp].r, psg[cp].id, psg[cp].t));
			}	
			cp++;
		}
		while (have0.size() > 0 && have0.begin()->r < cd)
		{
			have0.erase(have0.begin());
		}
		while (have1.size() > 0 && have1.begin()->r < cd)
		{
			printf("0\n");
			return;
		}
		int cur = 0;
		while (have0.size() + have1.size() > 0 && cur < k)
		{
			int wtk;
			if (have0.size() == 0) wtk = 1;
			else if (have1.size() == 0) 
			{
				long long mx = tmax[1] + (cd - 1) * ((long long)k);
				if (mx >= (k - cur)) 
				{
					have0.erase(have0.begin());
					continue;
				}
				wtk = 0;
			}
			else
			{
				if (have1.begin()->r < have0.begin()->r) wtk = 1;
				else
				{
					long long mx = tmax[1] + (cd - 1) * ((long long)k);
					if (-mx >= 0) wtk = 1;
					else wtk = 0;
				}
			}
			if (wtk == 1)
			{
				result[have1.begin()->id] = cd;
				TreeAdd(1, have1.begin()->r, md, -1);
				have1.erase(have1.begin());
			}
			else
			{
				result[have0.begin()->id] = cd;
				have0.erase(have0.begin());
			}
			cur++;
		}
		TreeFill(cd, -2000000000000000000ll);
	}
	for (i = 0; i < n; i++)
	{
		if (psg[i].t == 1 && result[psg[i].id] == 0) 
		{
			printf("0\n");
			return;
		}
	}
	int ans = 0;
	for (i = 0; i < n; i++) if (result[i] != 0) ans++;
	printf("%d\n", ans);
	for (i = 0; i < n; i++) printf("%d ", result[i]);
}

int main()
{
	freopen("planes.in", "rt", stdin);
	freopen("planes.out", "wt", stdout);
	Load();
	Solve();
	return 0;
}
