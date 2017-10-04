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
#define C(a) memset((a),0,sizeof(a))
#define ll long long
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))
#define VI vector<int>
#define ppb pop_back
#define mp make_pair
#define pii pair<int,int>
#define pdd pair<double,double>
//#define x first
//#define y second
#define sqr(a) (a)*(a)
#define D(a,b) sqrt(((a).x-(b).x)*((a).x-(b).x)+((a).y-(b).y)*((a).y-(b).y))
#define pi 3.1415926535897932384626433832795028841971
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())

vector<int> V[201], S[201], G[201];

int n;

bool used[201];
inline bool check(int s, int g)
{
	memset(used,0,n);

	queue<int> Q;

	Q.push(0);
	used[0] = true;

	while (!Q.empty())
	{
		int cur = Q.front(); Q.pop();

		rept(v, L(V[cur]))
			if (!used[V[cur][v]])
				if (S[cur][v] <= s && G[cur][v] <= g)
				{
					used[V[cur][v]] = true;
					Q.push(V[cur][v]);
				}
	}
	rept(v, n)
		if (!used[v])
			return false;
	
	return true;
}

int main()
{
	
	int m, csilver, cgold;
	scanf("%d%d%d%d", &n, &m, &csilver, &cgold);

	vector<int> gold, silver;

	rept(i, m)
	{
		int x, y, s, g;
		scanf("%d%d%d%d", &x, &y, &s, &g);
		x--; y--;
		V[x].pb(y);		V[y].pb(x);
		G[x].pb(g);		G[y].pb(g);
		S[x].pb(s);		S[y].pb(s);
		gold.pb(g);		silver.pb(s);
	}

	UN(gold);
	UN(silver);
	long long res = 9000000000000000000LL;

	rept(i, L(silver))
	{
		int s = silver[i];

		int fs;

		if (!check(s, INF))
			fs = -1;
		else
		{
			//(L, R]
			int l = -1,
				r = L(gold) - 1;
			while (r - l > 1)
			{
				int tt = (l + r) / 2;
				if (check(s, gold[tt]))
					r = tt;
				else
					l = tt;
			}
			fs = gold[r];
		}
		
		if (fs != -1)
			res = min(res, (long long)(s) * csilver + (long long)(fs) * cgold);
	}

	if (res == 9000000000000000000LL) cout << -1 << endl;
	else						  	  cout << res << endl;

	return 0;
}