/*
TASK: knapsacks
LANG: C++
AUTHOR: Alexander Georgiev
CONTEST: Winter Mathematical Festivals
*/

#include <cstdio>
#include <cstring>

#define MAX 512
#define MOD 1000000007

FILE *in; FILE *out;
int n, c1, c2, c3;
int a[MAX];
int dyn[2][MAX][MAX];

int eval()
{
	int ans = 0, sum = 0;
	int idx1 = 0, idx2 = 1;

	memset(dyn, 0, sizeof(dyn));
	dyn[idx1][c1][c2] = 1;

	for (int cur = 0; cur < n; cur++)
	{
		ans = 0;
		sum += a[cur];
		idx1 ^= 1; idx2 ^= 1;
		for (int cap1 = 0; cap1 <= c1; cap1++)
		{
			for (int cap2 = 0; cap2 <= c2; cap2++)
			{
				dyn[idx1][cap1][cap2] = 0;
				int cap3 = c3 - (sum - (c1 - cap1) - (c2 - cap2));
				if (cap3 < 0 || cap3 > c3) continue;

				if (cap1 + a[cur] <= c1)
				{
					dyn[idx1][cap1][cap2] += dyn[idx2][cap1 + a[cur]][cap2];
					if (dyn[idx1][cap1][cap2] >= MOD) dyn[idx1][cap1][cap2] -= MOD;
				}
				if (cap2 + a[cur] <= c2)
				{
					dyn[idx1][cap1][cap2] += dyn[idx2][cap1][cap2 + a[cur]];
					if (dyn[idx1][cap1][cap2] >= MOD) dyn[idx1][cap1][cap2] -= MOD;
				}
				if (cap3 + a[cur] <= c3)
				{
					dyn[idx1][cap1][cap2] += dyn[idx2][cap1][cap2];
					if (dyn[idx1][cap1][cap2] >= MOD) dyn[idx1][cap1][cap2] -= MOD;
				}
				ans += dyn[idx1][cap1][cap2]; if (ans >= MOD) ans -= MOD;
			}
		}
	}
	return ans;
}

int main(void)
{
	in = stdin; out = stdout;
//	in = fopen("knapsacks.in", "rt"); out = fopen("knapsacks.out", "wt");

	fscanf(in, "%d %d %d %d", &n, &c1, &c2, &c3);
	for (int i = 0; i < n; i++) fscanf(in, "%d", &a[i]);

	fprintf(out, "%d\n", eval());
	return 0;
}

