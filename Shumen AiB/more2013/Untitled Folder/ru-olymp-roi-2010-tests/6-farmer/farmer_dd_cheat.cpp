#include <iostream>
#include <fstream>
#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <string>
#include <map>
#include <ctime>

using namespace std;

const long double TL = 1.8;
const int MAXN = 4000;

int n, m;
int ma[MAXN][MAXN];

void Load()
{
	scanf("%d%d", &n, &m);
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			char c = getchar();
			while (! ((c == '0') || (c == '1'))) c = getchar();
			ma[i][j] = c - '0';
		}
	}
}

int sameup[MAXN][MAXN];
int fc[MAXN][MAXN];

void Prepare()
{
	int i, j;
	memset(sameup, 0, sizeof(sameup));
	for (j = 0; j < m - 1; j++) if (ma[0][j] == ma[0][j + 1]) sameup[0][j] = 1;
	for (i = 1; i < n; i++)
	{
		for (j = 0; j < m - 1; j++)
		{
			if (ma[i][j] == ma[i][j + 1]) sameup[i][j] = 1 + sameup[i - 1][j];
			else sameup[i][j] = 0;
		}
	}
	for (j = 0; j < m; j++) fc[0][j] = -1;
	for (i = 1; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (ma[i][j] != ma[i - 1][j]) fc[i][j] = i - 1;
			else fc[i][j] = fc[i - 1][j];
		}
	}
}

class Group
{
public:
	int len, type, l, r;
};

int oans, lft, rgt, up, dwn;
Group cg[MAXN];
int ncg;

void Find(int h)
{
	int i, j, tl, tr;
	for (i = h - 1; i < n; i++)
	{
		ncg = 0;
		j = 0;
		while (j < m)
		{
			int nj = j;
			while (nj < m - 1 && sameup[i][nj] >= h) nj++;
			nj++;
			cg[ncg].len = nj - j;
			cg[ncg].type = 0;
			cg[ncg].l = j;
			cg[ncg].r = nj - 1;
			if (ma[i][j] == 1)
			{
				int t = fc[i][j];
				if (t < i - h + 1) cg[ncg].type = 2;
				else
				{
					if (t != -1) t = fc[t][j];
					if (t != -1) t = fc[t][j];
					if (t < i - h + 1) cg[ncg].type = 1;
				}
			}
			else
			{
				int t = fc[i][j];
				if (t != -1) t = fc[t][j];
				if (t < i - h + 1) cg[ncg].type = 1;
			}
			ncg++;
			j = nj;
		}
		for (j = 0; j < ncg; j++)
		{
			if (cg[j].type == 2)
			{
				tl = cg[j].l;
				tr = cg[j].r;
				if (j + 1 < ncg && cg[j + 1].type == 1) 
				{
					tr = cg[j + 1].r;
					if (j + 2 < ncg && cg[j + 2].type == 2) tr = cg[j + 2].r;
				}
				if ((tr - tl + 1) * h > oans)
				{
					oans = (tr - tl + 1) * h;
					lft = tl;
					rgt = tr;
					up = i - h + 1;
					dwn = i;
				}
			}
			else if (cg[j].type == 1)
			{
				tl = cg[j].l;
				tr = cg[j].r;
				if (j + 1 < ncg && cg[j + 1].type == 2)
				{
					tr = cg[j + 1].r;
				}
				if ((tr - tl + 1) * h > oans)
				{
					oans = (tr - tl + 1) * h;
					lft = tl;
					rgt = tr;
					up = i - h + 1;
					dwn = i;
				}
			}
		}
	}
}

void FindInner(int u, int l, int d, int r)
{
	int i, j;
	int uu, ll, dd, rr;
	uu = ll = 2000000000;
	dd = rr = -2000000000;
	for (i = u; i <= d; i++)
	{
		for (j = l; j <= r; j++)
		{
			if (ma[i][j] == 0)
			{
				if (i < uu) uu = i;
				if (j < ll) ll = j;
				if (i > dd) dd = i;
				if (j > rr) rr = j;
			}
		}
	}
	if (uu == 2000000000)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				if (ma[i][j] == 0) 
				{
					uu = dd = i;
					ll = rr = j;
				}
			}
		}
	}
	printf("%d %d %d %d\n", uu + 1, ll + 1, dd + 1, rr + 1);
}

void Solve()
{
	Prepare();
	oans = 0;
	lft = rgt = up = dwn = 0;
	int s;
	clock_t begtime = clock();
	for (s = 1; s <= n * m; s++)
	{
		if (oans > s) continue;
		int b;
		for (b = 1; b <= m; b++)
		{
			if (s % b != 0) continue;
			int a = s / b;
			if (a > n) continue;
			Find(a);
		}
		if (clock() - begtime > TL * CLOCKS_PER_SEC) break;
	}
	FindInner(up, lft, dwn, rgt);
	printf("%d %d %d %d\n", up + 1, lft + 1, dwn + 1, rgt + 1);
	printf("%d\n", oans);
}

int main()
{
	freopen("farmer.in", "rt", stdin);
	freopen("farmer.out", "wt", stdout);
	Load();
	Solve();
	return 0;
}
