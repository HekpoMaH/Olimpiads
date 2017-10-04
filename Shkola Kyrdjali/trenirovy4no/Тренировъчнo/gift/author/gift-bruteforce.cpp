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

vector<int> V[201], S[201], G[201];
bool used[201];

int main()
{
	
	int n, m, csilver, cgold;
	scanf("%d%d%d%d", &n, &m, &csilver, &cgold);

	rept(i, m)
	{
		int x, y, s, g;
		scanf("%d%d%d%d", &x, &y, &s, &g);
		x--; y--;
		V[x].pb(y);		V[y].pb(x);
		G[x].pb(g);		G[y].pb(g);
		S[x].pb(s);		S[y].pb(s);
	}

	long long res = 9000000000000000000LL;

	pii best;

	rept(a, n)
		rept(b, n)
			rept(i, L(V[a]))
				rept(j, L(V[b]))
				{
					int s = S[a][i],
						g = G[b][j];

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
					bool connected = true;
					rept(v, n)
						if (!used[v])
						{
							connected = false;
							break;
						}

					if (connected) 
					{
						if ((long long)(s) * csilver + (long long)(g) * cgold<res)
						{
							res=(long long)(s) * csilver + (long long)(g) * cgold;
							best = mp(s, g);
						}
					}
				}

	if (res == 9000000000000000000LL) cout << -1 << endl;
	else						  	  cout << res << endl;
	
	return 0;
}