/*
LANG: C++
TASK: fuel
ID: espr1t
TOUR: Winter 2011
*/

#include <cstdio>

#define MAX 1048576
#define MOD 1000000007

using namespace std;
FILE *in; FILE *out;

int n, k, l;
int a[MAX], dyn[MAX];

int main(void)
{
	in = stdin; out = stdout;
//	in = fopen("fuel.in", "rt"); out = fopen("fuel.out", "wt");
	
	fscanf(in, "%d %d %d", &n, &k, &l);

	a[0] = 0; a[n + 1] = k;
	for (int i = 1; i <= n; i++)
		fscanf(in, "%d", &a[i]);
	
	dyn[n + 1] = 1;
	int right = n + 1, sum = 1;
	for (int left = n; left >= 0; left--)
	{
		while (a[right] - a[left] > l)
		{
			sum = (sum - dyn[right] + MOD) % MOD;
			right--;
		}
		dyn[left] = sum;
		sum = (sum + dyn[left]) % MOD;
	}
	fprintf(out, "%d\n", dyn[0]);
	return 0;
}
