//Greedy solution --- chooses K best in each layer.

#include <cstdio>
#include <cassert>
#include <memory>
#include <vector>
#include <cstring>
#include <algorithm>

using std::vector;
using std::pair;
using std::sort;

const int MAXN = 200000;
const int K = 5;

char s[MAXN][12];
char st[12], fin[12];
int d[MAXN];
int p[MAXN];

int F(int a, int b) 
{
	for (int i = 0; i < 10; ++i)
	{
		if (s[a][i] != s[b][i]) return 10 - i;
	}
	return 0;
}

int main()
{
	memset(s, 0, sizeof(s));
	freopen("sms.in", "rt", stdin);
	freopen("sms.out", "wt", stdout);
	
	int lb[5];
	int rb[5];

	int cs = 0;
	int sum = 0;

	assert(scanf("%11s", st) == 1 && strlen(st) == 10);
	assert(scanf("%11s", fin) == 1 && strlen(fin) == 10);


	for (int i = 0; i < 5; ++i)
	{
		int k;
		assert(scanf("%d", &k) == 1);
		assert(0 <= k && k <= MAXN);
		sum += k;
		if (i != 0 && i != 4 && k == 0) {
			printf("No solution\n");
			return 0;
		}
		lb[i] = cs;
		for (int j = 0; j < k; ++j)
		{
			assert(scanf("%11s", s[cs]) == 1 && strlen(s[cs]) == 10);
			++cs;
		}
		if (i == 0 || i == 4) cs = lb[i] + 1;
		rb[i] = cs - 1;
	}

	strcpy(s[lb[0]], st);
	strcpy(s[lb[4]], fin);
	assert(0 <= sum && sum <= MAXN);

	memset(d, 63, sizeof(d));
	memset(p, -1, sizeof(p));
	d[0] = 0;
	for (int i = 0; i < 5; ++i)
	{
		vector< pair<int, int> > g;
		for (int j = lb[i]; j <= rb[i]; ++j)
		{
			g.push_back(pair<int, int>(d[j], j));
		}
		
		sort(g.begin(), g.end());

		for (int tj = 0; tj < g.size() && tj <= K; ++tj)
		{
			int j = g[tj].second;
			for (int k = lb[i + 1]; k <= rb[i + 1]; ++k)
			{
				int tv = F(j, k);	
				if (d[k] > d[j] + tv) 
				{
					d[k] = d[j] + tv;
					p[k] = j;
				}
			}
		}
	}

	printf("%d 5\n", d[lb[4]]);
	
	int a[5];
	a[4] = lb[4];
	for (int i = 3; i >= 0; --i)
	{
		a[i] = p[a[i + 1]];
	}

	for (int i = 0; i < 5; ++i)
	{
		printf("%s\n", s[a[i]]);
	}

	return 0;
}
