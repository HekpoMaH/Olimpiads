//Dijkstra solution O(n^2)

#include <cstdio>
#include <vector>
#include <cassert>
#include <memory>
#include <cstring>

using std::vector;

const int MAXN = 200000;

char s[MAXN][12];
char st[12], fin[12];
int d[MAXN];
int p[MAXN];
bool used[MAXN];

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

	vector<int> * a = new vector<int>[cs];

	for (int i = 0; i < 5; ++i)
	{
		for (int j = lb[i]; j <= rb[i]; ++j)
		{
			for (int k = lb[i + 1]; k <= rb[i + 1]; ++k)
			{
				a[j].push_back(k);
			}
		}
	}

	memset(d, 63, sizeof(d));
	memset(p, -1, sizeof(p));
	memset(used, false, sizeof(used));
	
	d[lb[0]] = 0;

	while (true) 
	{
		int u = -1;
		for (int i = 0; i < cs; ++i)
		{
			if (!used[i] && (u == -1 || d[u] > d[i]))
			{
				u = i;
			}
		}
		if (u == -1) break;
		used[u] = true;
		for (int j = 0; j < a[u].size(); ++j)
		{
			int v = a[u][j];
			if (d[v] > d[u] + F(u, v))
			{
				d[v] = d[u] + F(u, v);
				p[v] = u;
			}
		}
	}


	vector<int> ans;
	int x = lb[4];
	while (x >= 0)
	{
		ans.push_back(x);
		x = p[x]; 
	}

	printf("%d %d\n", d[lb[4]], ans.size());

	for (int i = ans.size() - 1; i >= 0; --i)
	{
		printf("%s\n", s[ans[i]]);
	}

	return 0;
}
