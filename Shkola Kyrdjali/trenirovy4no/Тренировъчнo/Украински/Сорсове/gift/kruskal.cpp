#define _CRT_SECURE_NO_DEPRECATE
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <sstream>
#include <map>
#include <set>
#include <stack>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <memory>
using namespace std;
#define INF 1000000000
#define L(s) (int)((s).end()-(s).begin())
#define FOR(i,a,b) for (int _n(b), i(a); i <= _n; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define rep(i,n) FOR(i,1,(n))
#define rept(i,n) FOR(i,0,(n)-1)
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))

struct edge
{
	int a, b, s, g, id;
	edge() {}
	edge (int _a, int _b, int _s, int _g, int _id) : a(_a), b(_b), s(_s), g(_g), id(_id) {}
};

inline bool operator < (const edge & u, const edge & v)
{
	if (u.s < v.s) return true;
	if (u.s > v.s) return false;

	if (u.g < v.g) return true;
	if (u.g > v.g) return false;

	if (u.a < v.a) return true;
	if (u.a > v.a) return false;
	
	if (u.b < v.b) return true;
	if (u.b > v.b) return true;

	return u.id < v.id;
}

vector<int> pred;

inline int who(int x)
{
	if (pred[x] == -1) return x;
	return pred[x] = who(pred[x]);
}

inline void un(int x, int y)
{
	if (rand() & 1) pred[who(x)] = who(y);
	else			pred[who(y)] = who(x);
}

inline int count()
{
	int res = 0;
	rept(i, L(pred)) res += (pred[i] == -1);
	return res;
}

edge E[50001];
int main()
{
	freopen("gift.dat","rt",stdin); freopen("gift.sol","wt",stdout);
	
	int n, m, csilver, cgold;
	scanf("%d%d%d%d", &n, &m, &csilver, &cgold);
	
	vector<edge> E(m), Ec;

	rept(i, m)
	{
		int x, y, s, g;
		scanf("%d%d%d%d", &x, &y, &s, &g);
		x--; y--;
		E[i] = edge(x, y, s, g, i);
	}

	SORT(E);

	long long res = 9000000000000000000LL;

	vector<edge> cur[2];

	cur[0].assign(m, edge(0, 0, 0, 0, 0));
	cur[1].assign(m, edge(0, 0, 0, 0, 0));

	rept(i, L(E))
	{
		pred.assign(n, -1);

		int c = i & 1, cnt = 0;

		rept(j, i)
		{
			if (cur[c ^ 1][j].g <= E[i].g)
				cur[c][j] = cur[c ^ 1][j], cnt++;
			else
				cur[c][j + 1] = cur[c ^ 1][j];
		}

		cur[c][cnt] = E[i];

		int fs = -INF;
		rept(j, i + 1) 
			if (who(cur[c][j].a) != who(cur[c][j].b))
				un(cur[c][j].a, cur[c][j].b), fs = max(fs, cur[c][j].g);

		if (count() == 1)
			res = min(res, (long long)(E[i].s) * csilver + (long long)(fs) * cgold);
	}

	if (res != 9000000000000000000LL) cout << res << endl;
	else							  cout << -1 << endl;
	
	return 0;
}
