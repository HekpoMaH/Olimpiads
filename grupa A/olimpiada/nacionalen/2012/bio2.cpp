#include <cstdio>
#include <iostream>
using namespace std;

int m, n;

int ll[32768], rr[32768], uu[32768], dd[32768];
int nzrn, nzr[16384], nzcn, nzc[16384];

int main ()
{
	int k;
	scanf ("%d %d %d", &k, &n, &m);

	for (int i = 0; i <= n + 1; ++i) { ll[i] = 0; rr[i] = m + 1; }
	for (int i = 0; i <= m + 1; ++i) { uu[i] = 0; dd[i] = n + 1; }

	int tr, tc;
	char td;
	for (int i = 0; i < k; ++i)
	{
		scanf ("%d %d %c\n", &tr, &tc, &td);

		if (td == 'u') if (uu[tc] < tr) uu[tc] = tr;
		if (td == 'd') if (dd[tc] > tr) dd[tc] = tr;
		if (td == 'l') if (ll[tr] < tc) ll[tr] = tc;
		if (td == 'r') if (rr[tr] > tc) rr[tr] = tc;
	}

	for (int i = 0; i <= n; ++i) if (ll[i] >= rr[i]) ll[i] = rr[i] - 1;
	for (int i = 0; i <= m; ++i) if (uu[i] >= dd[i]) uu[i] = dd[i] - 1;

	for (int i = 0; i <= n + 1; ++i) cout << ll[i] << ' ' << rr[i] << endl;
	for (int i = 0; i <= m + 1; ++i) cout << uu[i] << ' ' << dd[i] << endl;

	int t, dirty = 0;
	for (int i = 0; i <= n; ++i) if ((t = m + 1 + ll[i] - rr[i]) > 0)
	{
		dirty += t;
		nzr[nzrn++] = i;
	}
	for (int i = 0; i <= m; ++i) if ((t = n + 1 + uu[i] - dd[i]) > 0)
	{
		dirty += t;
		nzc[nzcn++] = i;
	}

	//cout << dirty << endl;

	for (int i = 0; i < nzrn; ++i)
		for (int j = 0; j < nzcn; ++j)
		{
			dirty -= ((ll[nzr[i]] >= nzc[j] || rr[nzr[i]] <= nzc[j]) &&
								(uu[nzc[j]] >= nzr[i] || dd[nzc[j]] <= nzr[i]) ) ? 1 : 0;
			//cout << nzr[i] << ' ' << nzc[j] << ' ' << dirty << endl;
		}

	printf ("%d\n", dirty);
	return 0;
}
