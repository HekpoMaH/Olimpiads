/*
LANG: C++
TASK: fuel
ID: espr1t
TOUR: Winter 2011
*/

#include <cstdio>
#include <cstring>

#define MAX 1048576
#define MOD 1000000007

using namespace std;
FILE *in; FILE *out;

int n, k, l;
int a[MAX], dyn[MAX];

int recurse(int cur)
{
	if (cur > n) return 1;
	if (dyn[cur] != -1) return dyn[cur];
	
	int ans = 0;
	for (int i=cur+1; i<=n+1; i++)
		if (a[i] - a[cur] <= l) ans = (ans + recurse(i)) % MOD;
	
	return dyn[cur] = ans;
}

int main(void)
{
	in = stdin; out = stdout;
//	in = fopen("fuel.in", "rt"); out = fopen("fuel.out", "wt");
	
	fscanf(in, "%d %d %d", &n, &k, &l);
	a[0] = 0; a[n + 1] = k;
	for (int i=1; i<=n; i++) fscanf(in, "%d", &a[i]);
	
	memset(dyn, -1, sizeof(dyn));
	fprintf(out, "%d\n", recurse(0));

	return 0;
}
