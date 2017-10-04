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
#define MM 201

FILE *in; FILE *out;
int n, c1, c2, c3;
int a[MAX];
int dyn[MM][MM][MM];

int recurse(int cur, int rem1, int rem2, int rem3)
{
	if (cur >= n) return 1;
	if (dyn[cur][rem1][rem2] != -1) return dyn[cur][rem1][rem2];
	
	int ans = 0;
	if (rem1 >= a[cur]) {ans += recurse(cur + 1, rem1 - a[cur], rem2, rem3); if (ans >= MOD) ans -= MOD;}
	if (rem2 >= a[cur]) {ans += recurse(cur + 1, rem1, rem2 - a[cur], rem3); if (ans >= MOD) ans -= MOD;}
	if (rem3 >= a[cur]) {ans += recurse(cur + 1, rem1, rem2, rem3 - a[cur]); if (ans >= MOD) ans -= MOD;}	
	return dyn[cur][rem1][rem2] = ans;
}

int main(void)
{
	in = stdin; out = stdout;
//	in = fopen("knapsacks.in", "rt"); out = fopen("knapsacks.out", "wt");
	
	fscanf(in, "%d %d %d %d", &n, &c1, &c2, &c3);
	for (int i = 0; i < n; i++) fscanf(in, "%d", &a[i]);
	
	memset(dyn, -1, sizeof(dyn));
	int ans = recurse(0, c1, c2, c3);
	fprintf(out, "%d\n", ans);

	return 0;
}
