#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
using namespace std;

typedef long long ll;

set <pair <int, int> > gd;
typedef set <pair <int, int> >::iterator siter;
const int MAXN = 300003;
ll sm[4 * MAXN];
int val[4 * MAXN];
int mx[4 * MAXN];
ll ans = 0;
char s[MAXN];

int lv, rv;
int nv;
int n, q;

void set_val(int v, int vl, int sz)
{
	val[v] = vl;
	ans -= sm[v];
	sm[v] = (ll)vl * (ll)sz;
	ans += sm[v];
	mx[v] = vl;
}

void set_val2(int v, int vl, int sz)
{
	val[v] = vl;
	sm[v] = (ll)vl * (ll)sz;
	mx[v] = vl;
}

void push(int v, int sz)
{
	if (val[v] == -1) return;
	set_val2(v * 2 + 1, val[v], (sz + 1) / 2);
	set_val2(v * 2 + 2, val[v], sz / 2);
	val[v] = -1;
}


void modify_rmq(int v, int l, int r)
{
	if (l > rv) return;
	if (lv > r) return;
	int sz = (r - l + 1);
	if ((lv <= l) && (r <= rv) && (mx[v] <= nv))
	{
		set_val(v, nv, sz);
		return;
	}
	if (l == r) return;
	push(v, sz);
	if (mx[v * 2 + 1] < nv) modify_rmq(v * 2 + 2, (l + r) / 2 + 1, r);
	modify_rmq(v * 2 +  1, l, (l + r) / 2);
	mx[v] = mx[v * 2 + 2];
	sm[v] = sm[v * 2 + 1] + sm[v * 2 + 2];
}


void ad(int lg, int rg)
{
	siter it = gd.lower_bound(make_pair(lg, 0));
	it--;
	if (it->second + 1 < lg) it++;
	else lg = it->first;
	siter sit = it;
	while (it->first <= rg + 1)
	{
		if (it->second > rg) rg = it->second;
		it++;
	}
	gd.erase(sit, it);
	gd.insert(make_pair(lg, rg));
	lv = lg, rv = rg, nv = rg + 1;
	modify_rmq(0, 0, n - 1);
}


void er(int lg, int rg)
{
	int l1 = -1, r1 = -1, l2 = -1, r2 = -1;
	siter it = gd.lower_bound(make_pair(lg, 0));
	it--;
	if (it->second >= lg)
	{
		l1 = it->first, r1 = lg - 1;
	}
	else it++;
	siter sit = it;
	while (it->second <= rg)
	{
		it++;
	}
	if (it->first <= rg)
	{
		l2 = rg + 1, r2 = it->second;
		it++;
	}
	gd.erase(sit, it);
	if (l1 != -1) gd.insert(make_pair(l1, r1));
	if (l2 != -1) gd.insert(make_pair(l2, r2));
}

int main()
{
	freopen("lamps.in", "r", stdin);
	freopen("lamps.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	scanf("%d%d", &n, &q);
	for (int i = 0; i < 4 * MAXN; i++) val[i] = mx[i] = sm[i] = 0;
	ans = -((ll)n * (ll)(n - 1)) / 2;
	gd.insert(make_pair(-2, -2));
	gd.insert(make_pair(n + 1, n + 1));
	for (int i = 0; i < n; i++)
	{
		lv = rv = nv = i;
		modify_rmq(0, 0, n - 1);
	}
	scanf("%s", s);
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '1') ad(i, i);
	}
	cout << ans << "\n";
	for (int i = 0; i < q; i++)
	{
		int l, r, c;
		scanf("%d%d%d", &l, &r, &c);
		l--, r--;
		if (c == 0) er(l, r);
		else ad(l, r);
		cout << ans << "\n";
	}
	return 0;
}
