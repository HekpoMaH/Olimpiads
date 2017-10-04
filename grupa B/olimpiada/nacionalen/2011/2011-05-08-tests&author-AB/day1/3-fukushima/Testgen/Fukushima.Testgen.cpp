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

int random()
{
	return (((rand() & ((1 << 15) - 1)) << 15) | (rand() & ((1 << 15) - 1)));
}
int nn[10] = {7, 11, 50, 101, 200, 333, 500, 700, 900, 1000};
int mm[10] = {6, 20, 113, 666, 242, 3333, 10000, 8907, 8500, 10000};


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

int solve()
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
	return ans;
}

void printTest(int test)
{
	char fileName[32];
	sprintf(fileName, "Fukushima.%02d.in", test);
	
	if (n < 1 || n > MAX_NODES)
		fprintf(stderr, "  -- number of nodes is %d but should be in [%d, %d]!\n", n, 1, MAX_NODES);
	if (m < 0 || m > MAX_EDGES)
		fprintf(stderr, "  -- number of edges is %d but should be in [%d, %d]!\n", m, 0, MAX_EDGES);
	
	FILE* out = fopen(fileName, "wt");
	fprintf(out, "%d %d\n", n, m);
	
	int printedEdges = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int c = 1; c <= n; c++) if (ma3x[i][c] < INF)
		{
			printedEdges++;
			fprintf(out, "%d %d %d\n", i, c, ma3x[i][c]);
		}
	}
	if (printedEdges != m)
		fprintf(stderr, "  -- number of printed edges differs from noted.\n");
	fclose(out);
}

void sampleInput1()
{
	n = 7; m = 13;
	ma3x[2][1] = 6;
	ma3x[6][4] = 64;
	ma3x[1][6] = 42;
	ma3x[4][3] = 17;
	ma3x[4][7] = 12;
	ma3x[3][7] = 20;
	ma3x[7][6] = 19;
	ma3x[6][7] = 11;
	ma3x[7][5] = 35;
	ma3x[3][5] = 4;
	ma3x[3][2] = 13;
	ma3x[7][2] = 55;
	ma3x[2][5] = 1;
}

void sampleInput1Reversed()
{
	n = 7; m = 13;
	ma3x[1][2] = 6;
	ma3x[4][6] = 64;
	ma3x[6][1] = 42;
	ma3x[3][4] = 17;
	ma3x[7][4] = 12;
	ma3x[7][3] = 20;
	ma3x[6][7] = 19;
	ma3x[7][6] = 11;
	ma3x[5][7] = 35;
	ma3x[5][3] = 4;
	ma3x[2][3] = 13;
	ma3x[2][7] = 55;
	ma3x[5][2] = 1;
}

void sampleInput2()
{
	n = 4; m = 3;
	ma3x[2][1] = 6;
	ma3x[4][2] = 6;
	ma3x[3][1] = 6;
}

void sampleInput2Reversed()
{
	n = 4; m = 3;
	ma3x[1][2] = 6;
	ma3x[2][4] = 6;
	ma3x[1][3] = 6;
}

void noEdges()
{
	n = 42; m = 0;
}

void randomMinusOne(int test)
{
	n = nn[test - 1];
	m = mm[test - 1];

	int actualEdges = 0;
	for (int i = 0; i < m; i++)
	{
		int node1 = random() % n + 1;
		int node2 = random() % n + 1;
		if (node1 == node2) continue;
		if (ma3x[node1][node2] < INF) continue;

		ma3x[node1][node2] = random() % MAX_PRICE + 1;
		if (eval(INF))
			actualEdges++;
		else ma3x[node1][node2] = INF + 1;
	}
	m = actualEdges;
}

void randomNotMinusOne(int test)
{
	if (test >= 11) test -= 11;
	n = nn[test];
	m = mm[test];

	int actualEdges = 0;
	for (int i = 0; i < m; i++)
	{
		int node1 = random() % n + 1;
		int node2 = random() % n + 1;
		if (node1 == node2) continue;
		if (ma3x[node1][node2] < INF) continue;

		actualEdges++;
		ma3x[node1][node2] = random() % MAX_PRICE + 1;
	}
	while (eval(INF))
	{
		int node1 = random() % n + 1;
		int node2 = random() % n + 1;
		if (node1 == node2) continue;
		if (ma3x[node1][node2] < INF) continue;

		actualEdges++;
		ma3x[node1][node2] = random() % MAX_PRICE + 1;
	}
	m = actualEdges;
}

int main(void)
{
	srand(42);
	int numTests = 20;
	for (int test = 0; test <= numTests; test++)
	{
		fprintf(stderr, "Generating test nr. %d...\n", test);
		for (int i = 0; i < MAX; i++)
			for (int c = 0; c < MAX; c++)
				ma3x[i][c] = INF + 1;

		if (test == 0) sampleInput1();
		if (test == 1) sampleInput2Reversed();
		if (test == 2) noEdges();
		if (test == 3) randomMinusOne(test);
		if (test == 4) randomMinusOne(test);
		if (test == 5) randomMinusOne(test);
		if (test == 6) randomMinusOne(test);
		if (test == 7) randomMinusOne(test);
		if (test == 8) randomMinusOne(test);
		if (test == 9) randomMinusOne(test);
		if (test == 10) randomMinusOne(test);
		if (test == 11) sampleInput1Reversed();
		if (test == 12) randomNotMinusOne(test);
		if (test == 13) randomNotMinusOne(test);
		if (test == 14) randomNotMinusOne(test);
		if (test == 15) randomNotMinusOne(test);
		if (test == 16) randomNotMinusOne(test);
		if (test == 17) randomNotMinusOne(test);
		if (test == 18) randomNotMinusOne(test);
		if (test == 19) randomNotMinusOne(test);
		if (test == 20) randomNotMinusOne(test);
		printTest(test);
		fprintf(stderr, "  -- expected answer is %d\n", solve());
	}
	fprintf(stderr, "All tests generated successfully!\n");
	system("pause");
	return 0;
}
