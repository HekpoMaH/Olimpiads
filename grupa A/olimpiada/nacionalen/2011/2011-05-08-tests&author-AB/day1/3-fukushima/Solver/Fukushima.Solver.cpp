/*
ID: espr1t
LANG: C++
TASK: Fukushima
COMP: NOI Round 3, 2011
KEYWORDS: Binary Search, Topological Sorting
*/

#include <cstdio>
#include <cstring>
#include <cstdlib>

#define MAX 1024
#define INF 999666333

#define MAX_NODES 1000
#define MAX_EDGES 10000
#define MAX_PRICE 100000

int n, m;
int ma3x[MAX][MAX];

int ans = 0;
int order[MAX], deg[MAX];

int eval(int cutoff)
{
	for (int i = 1; i <= n; i++)
		deg[i] = 0;

	for (int i = 1; i <= n; i++)
		for (int c = 1; c <= n; c++)
			if (ma3x[i][c] <= cutoff) deg[c]++;
	
	for (int i = 1; i <= n; i++)
	{
		int idx = -1;
		for (int c = 1; c <= n; c++)
			if (deg[c] == 0) {idx = c; break;}
		if (idx == -1) return 0;

		deg[idx] = -1;
		order[i] = idx;
		for (int c = 1; c <= n; c++)
			if (ma3x[idx][c] <= cutoff) deg[c]--;
	}
	return 1;
}

void solve()
{
	ans = 0;
	int left = 0, right = INF, mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (eval(mid))
		{
			left = mid + 1;
			if (ans < mid) ans = mid;
		}
		else
			right = mid - 1;
	}
	eval(ans);
}

void readInput(FILE *in)
{
	for (int i = 0; i < MAX; i++)
		for (int c = 0; c < MAX; c++)
			ma3x[i][c] = INF + 1;

	fscanf(in, "%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int node1, node2, price;
		fscanf(in, "%d %d %d", &node1, &node2, &price);
		ma3x[node2][node1] = price;
	}
}

void writeOutput(FILE *out)
{
	fprintf(out, "%d\n", ans >= INF ? -1 : ans);
	for (int i = 1; i <= n; i++)
		fprintf(out, "%d%c", order[i], i == n ? '\n' : ' ');
}

int main(void)
{
	int numTests = 20;
	for (int test = 0; test <= numTests; test++)
	{
		fprintf(stderr, "Solving test nr. %d...\n", test);

		char inpFile[32], outFile[32];
		sprintf(inpFile, "Fukushima.%02d.in", test);
		sprintf(outFile, "Fukushima.%02d.sol", test);
		
		FILE *in = fopen(inpFile, "rt");
		FILE *out = fopen(outFile, "wt");
		
		readInput(in);
		solve();
		writeOutput(out);
		fclose(in); fclose(out);
	}
	fprintf(stderr, "All tests generated successfully!\n");
	system("pause");
	return 0;
}
