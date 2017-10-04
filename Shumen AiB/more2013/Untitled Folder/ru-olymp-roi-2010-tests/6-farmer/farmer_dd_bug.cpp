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

using namespace std;

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
int first[MAXN];
int last[MAXN];
int type[MAXN];
int head[MAXN];
vector<int> appear[MAXN];
vector<int> begood[MAXN];
vector<int> mmerge[MAXN];
int oans;
int ol, orr, ou, od;
	
void Check(int u, int d, int col)
{
	if (type[col] == 1)
	{
		int tl = col;
		if (col > 0 && type[first[col - 1]] == 2) tl = first[col - 1];
		int tr = last[col];
		if (tr < m - 1 && type[tr + 1] == 2) tr = last[tr + 1];
		if ((d - u + 1) * (tr - tl + 1) > oans)
		{
			oans = (d - u + 1) * (tr - tl + 1);
			ol = tl;
			orr = tr;
			ou = u;
			od = d;
		}
	}
	else if (type[col] == 2)
	{
		// to the left
		int tl = col;
		if (col > 0)
		{
			if (type[first[col - 1]] == 1) tl = first[col - 1];
			if (tl > 0)
			{
				if (type[first[tl - 1]] == 2) tl = first[tl - 1];
			}
		}
		int tr = last[col];
		if ((d - u + 1) * (tr - tl + 1) > oans)
		{
			oans = (d - u + 1) * (tr - tl + 1);
			ol = tl;
			orr = tr;
			ou = u;
			od = d;
		}
		// to the right
		tl = col;
		tr = last[col];
		if (tr < m - 1)
		{
			if (type[tr + 1] == 1) tr = last[tr + 1];
			if (tr < m - 1)
			{
				if (type[tr + 1] == 2) tr = last[tr + 1];
			}
		}
		if ((d - u + 1) * (tr - tl + 1) > oans)
		{
			oans = (d - u + 1) * (tr - tl + 1);
			ol = tl;
			orr = tr;
			ou = u;
			od = d;
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
	printf("%d %d %d %d\n", uu + 1, ll + 1, dd + 1, rr + 1);
}

void Solve()
{
	int i, j, k;
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
	oans = 0;
	ol = orr = ou = od = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= i; j++) 
		{
			appear[j].clear();
			begood[j].clear();
			mmerge[j].clear();
		}
		for (j = 0; j < m; j++)
		{
			if (ma[i][j] == 1)
			{
				int t = fc[i][j];
				begood[t + 1].push_back(j);
				if (t != -1)
				{
					t = fc[t][j];
					if (t != -1) t = fc[t][j];
				}
				appear[t + 1].push_back(j);
			}
			else
			{
				int t = fc[i][j];
				if (t != -1) t = fc[t][j];
				appear[t + 1].push_back(j);
			}
		}
		for (j = 0; j < m - 1; j++)
		{
			int t = i - sameup[i][j];
			if (t != i) mmerge[t + 1].push_back(j);
		}
		for (j = 0; j < m; j++)
		{
			head[j] = 1;
			first[j] = j;
			last[j] = j;
			type[j] = 0; // bad
		}
		for (j = 0; j <= i; j++)
		{
			// merge        
			for (k = 0; k < mmerge[j].size(); k++)
			{
				int q = mmerge[j][k];
				if (head[q] == 1 || head[q + 1] == 1)
				{
					last[first[q]] = last[q + 1];
					first[last[q + 1]] = first[q];
					head[q] = head[q + 1] = 0;
					if (first[q] == q) head[q] = 1;
					Check(j, i, first[q]);
				}
			}
			// appear
			for (k = 0; k < appear[j].size(); k++)
			{
				int q = appear[j][k];
				type[first[q]] = 1;
				Check(j, i, first[q]);
			}
			// be good
			for (k = 0; k < begood[j].size(); k++)
			{
				int q = begood[j][k];
				type[first[q]] = 2;
				Check(j, i, first[q]);
			}
		}
	}
	FindInner(ou, ol, od, orr);
	printf("%d %d %d %d\n", ou + 1, ol + 1, od + 1, orr + 1);
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
