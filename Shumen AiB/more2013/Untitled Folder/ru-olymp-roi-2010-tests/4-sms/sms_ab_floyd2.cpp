//Floyd solution O(n^3)
#include <cstdio>
#include <vector>
#include <cassert>
#include <memory>
#include <cstring>

using std::vector;

const int MAXN = 200000;
const int FLMAX = 2000; 


char s[MAXN][12];
char st[12], fin[12];
int g[FLMAX][FLMAX];
int f[FLMAX][FLMAX];

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

	if (cs > FLMAX) return 0;

	memset(g, 63, sizeof(g));
	memset(f, -1, sizeof(f));

	for (int i = 0; i < 5; ++i)
	{
		for (int j = lb[i]; j <= rb[i]; ++j)
		{
			for (int k = lb[i + 1]; k <= rb[i + 1]; ++k)
			{
				g[j][k] = F(j, k);
				f[j][k] = k;
			}
		}
	}


	for (int k = 0; k < cs; ++k)
	{
		for (int i = 0; i < cs; ++i)
		{
			if (g[i][k] > 1000000) continue;
			for (int j = 0; j < cs; ++j)
			{
				if (g[i][j] > g[i][k] + g[k][j])
				{
					g[i][j] = g[i][k] + g[k][j];
					f[i][j] = f[i][k];
				}
			}
		}
	}

	vector<int> ans;
	int x = 0;
	while (true)
	{
//		fprintf(stderr, "%d\n", x);
		ans.push_back(x);
		if (x == lb[4]) break;
		x = f[x][lb[4]]; 
	}

	printf("%d %d\n", g[lb[0]][lb[4]], ans.size());

	for (int i = 0; i < ans.size(); ++i)
	{
		printf("%s\n", s[ans[i]]);
	}

	return 0;
}
