/*
TASK: knapsacks
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
int dyn[MAX][MAX][MAX];

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

void solve(int test)
{
	char inFile[32], outFile[32];
	sprintf(inFile, "knapsacks.%02d.in", test);
	sprintf(outFile, "knapsacks.%02d.out", test);
	in = fopen(inFile, "rt"); out = fopen(outFile, "wt");
	
	fscanf(in, "%d %d %d %d", &n, &c1, &c2, &c3);
	for (int i = 0; i < n; i++) fscanf(in, "%d", &a[i]);
	memset(dyn, -1, sizeof(dyn));
	fprintf(out, "%d\n", recurse(0, c1, c2, c3));
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
