#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define y1 y11
using namespace std;

const int MAXN = 150010;
int mh = 0, mv = 0;
int n, q;
int xh[MAXN], yh[MAXN];
int xv[MAXN], yv[MAXN];
int m;
int x[MAXN], y[MAXN];
int x1[MAXN], y1[MAXN], x2[MAXN], y2[MAXN];
pair <int, int> pt[2 * MAXN];
int atot[MAXN];
int ans[MAXN];
int fen[MAXN];
pair <int, int> sobs[2 * MAXN];
vector <int> ad[MAXN];

void adfen(int t)
{
	for (int i = t; i < MAXN; i = (i | (i + 1)))
	{
		fen[i]++;
	}
}

int getfen(int t)
{
	int af = 0;
	for (int i = t; i >= 0; i = ((i & (i + 1)) - 1))
	{
		af += fen[i];
	}
	return af;
}

void solve()
{
	for (int i = 0; i < MAXN; i++) fen[i] = 0, ad[i].clear();
	for (int i = 0; i < m; i++) ad[x[i]].push_back(y[i]);;
	for (int i = 0; i < q; i++)
	{
		ans[i] = 0;
		sobs[i * 2] = make_pair(x1[i] - 1, i + 1);
		sobs[i * 2 + 1] = make_pair(x2[i], -(i + 1));
	}
	sort(sobs, sobs + 2 * q);
	int pp = 0;
	sobs[2 * q].first = MAXN;
	for (int i = 0; i < MAXN; i++)
	{
		for (int j = 0; j < ad[i].size(); j++)
		{
			adfen(ad[i][j]);
		}
		while (sobs[pp].first == i)
		{
			if (sobs[pp].second < 0)
			{
				int v = -sobs[pp].second - 1;
				ans[v] += (getfen(y2[v]) - getfen(y1[v] - 1));
			}
			else
			{
				int v = sobs[pp].second - 1;
				ans[v] -= (getfen(y2[v]) - getfen(y1[v] - 1));
			}
			pp++;
		}
	}
}

int main()
{
	freopen("repair.in", "r", stdin);
	freopen("repair.out", "w", stdout);
	scanf("%d%d", &n, &q);
	scanf("%d%d", &n, &q);
	n--;
	for (int i = 0; i < n; i++)
	{
		char tp[3];
		int xc, yc;
		scanf("%s%d%d", tp, &xc, &yc);
		pt[i * 2] = make_pair(xc, yc);
		if (tp[0] == 'h')
		{
			xh[mh] = xc, yh[mh] = yc;
			mh++;
			pt[i * 2 + 1] = make_pair(xc + 1, yc);
		}
		else
		{
			xv[mv] = xc, yv[mv] = yc;
			mv++;
			pt[i * 2 + 1] = make_pair(xc, yc + 1);
		}
	}
	for (int i = 0; i < q; i++)
	{
		scanf("%d%d%d%d", &x1[i], &y1[i], &x2[i], &y2[i]);
	}
	m = 0;
	sort(pt, pt + 2 * n);
	for (int i = 0; i < 2 * n; i++)
	{
		if ((i == 0) || (pt[i] != pt[i - 1]))
		{
			x[m] = pt[i].first, y[m] = pt[i].second;
			m++;
		}
	}
	solve();
	for (int i = 0; i < q; i++) atot[i] = ans[i],cerr<<atot[i]<<"\n";
        exit(0);

	m = mh;
	for (int i = 0; i < m; i++) x[i] = xh[i], y[i] = yh[i];
	for (int i = 0; i < q; i++) x2[i]--;
	solve();
	for (int i = 0; i < q; i++)
	{
		x2[i]++;
		atot[i] -= ans[i];
	}
	
	m = mv;
	for (int i = 0; i < m; i++) x[i] = xv[i], y[i] = yv[i];
	for (int i = 0; i < q; i++) y2[i]--;
	solve();
	for (int i = 0; i < q; i++)
	{
		y2[i]++;
		atot[i] -= ans[i];
	}

	for (int i = 0; i < q; i++)
	{
		printf("%d\n", atot[i]);
	}
	return 0;
}

