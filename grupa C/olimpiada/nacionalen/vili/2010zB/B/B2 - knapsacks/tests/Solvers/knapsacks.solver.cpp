/*
TASK: knapsacks solver
LANG: C++
AUTHOR: Alexander Georgiev
CONTEST: Winter Mathematical Festivals
*/

#include <cstdio>
#include <cstring>
#include <ctime>
#include <cstdlib>

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

void solve(int test)
{
	char inFile[32], outFile[32];
	sprintf(inFile, "knapsacks.%02d.in", test);
	sprintf(outFile, "knapsacks.%02d.sol", test);
	in = fopen(inFile, "rt"); out = fopen(outFile, "wt");
	
	fscanf(in, "%d %d %d %d", &n, &c1, &c2, &c3);
	for (int i = 0; i < n; i++) fscanf(in, "%d", &a[i]);	
	fprintf(out, "%d\n", eval());
	fclose(in); fclose(out);
}

int main(void)
{
	int numTests = 10;
	for (int test = 1; test <= numTests; test++)
	{
		unsigned sTime = clock();
		fprintf(stderr, "Currently solving test nr.%02d...", test);
		solve(test);
		unsigned eTime = clock();
		fprintf(stderr, " Execution time %.3lf sec\n", (double)(eTime - sTime) / (double)CLOCKS_PER_SEC);
	}
	system("pause");
	return 0;
}
