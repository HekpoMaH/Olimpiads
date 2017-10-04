//O(n) solution

#include <cstdio>
#include <cassert>
#include <memory>
#include <cstring>
#include <algorithm>

using std::min;

const int MAXN = 200000;
const int INF = 1 << 30;

char * s[MAXN + 2];
char st[12], fin[12];
int d[MAXN + 2];
int p[MAXN + 2];
int mv[11];
int mp[11];
char blank[12];


int lcp(int a, int b)
{
	for (int i = 0; i < 10; ++i)
	{
		if (s[a][i] != s[b][i]) return i;
	}
	return 10;
}

int FT[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

int F(int a, int b) 
{
	return FT[lcp(a, b)];
}

bool cmp(char * a, char * b)
{
	return strcmp(a, b) < 0;
}

int main()
{
	memset(blank, 0, sizeof(blank));
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
			s[cs] = strdup(blank);
			assert(scanf("%11s", s[cs]) == 1 && strlen(s[cs]) == 10);
			++cs;
		}
		if (i == 0 || i == 4) cs = lb[i] + 1;
		rb[i] = cs - 1;
	}

	

	s[lb[0]] = strdup(st);
	s[lb[4]] = strdup(fin);
	assert(0 <= sum && sum <= MAXN);
	


	for (int i = 0; i < 5; ++i)
	{
		std::sort(s + lb[i], s + rb[i] + 1, cmp);
	}

/*	for (int i = 0; i < 5; ++i)
	{
	//	fprintf(stderr, "%d: %d %d\n", i, lb[i], rb[i]);
		fprintf(stderr, "%d\n", i);
		for (int j = lb[i]; j <= rb[i]; ++j)
		{
			fprintf(stderr, "%s\n", s[j]);
		} 
	} */

	memset(d, 63, sizeof(d));
	memset(p, -1, sizeof(p));

	d[0] = 0;
	for (int i = 1; i < 5; ++i)
	{

		for (int dir = -1; dir <= 1; dir += 2)
		{
			memset(mv, 63, sizeof(mv));
			memset(mp, -1, sizeof(mp));

			int lj = dir == 1 ? lb[i] 		: rb[i];
			int rj = dir == 1 ? rb[i] + 1 		: lb[i] - 1;
			int lk = dir == 1 ? lb[i - 1] 		: rb[i - 1];
			int rk = dir == 1 ? rb[i - 1] + 1 	: lb[i - 1] - 1;


			for (int j = lj, k = lk; j != rj; j += dir)
			{
	//			fprintf(stderr, "%d %d %d %d\n", lj, j, rj, k);
	//			if (k == rk) k -= dir;
	
				if (j != lj)
				{
					int len = lcp(j - dir, j);
					for (int q = len + 1; q <= 10; ++q)
					{
						if (mv[len] > mv[q])
						{
							mv[len] = mv[q];
							mp[len] = mp[q];
						}
						mv[q] = INF;
						mp[q] = -1;
					}
				}

				while (k != rk && dir * strcmp(s[k], s[j]) <= 0)
				{
					int len = lcp(k, j);
					if (mv[len] > d[k])
					{
						mv[len] = d[k];
						mp[len] = k;
					}
					k += dir;
				}

				for (int q = 0; q <= 10; ++q)
				{
					if (d[j] > mv[q] + FT[q])
					{
						d[j] = mv[q] + FT[q];
						p[j] = mp[q];
					}
				}
			}
		}
	}

/*	for (int i = 0; i < cs; ++i)
	{
		printf("%d : %s dist: %d prev: %d\n", i, s[i], d[i], p[i]);
	}  */
	
	//return 0;

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
