/*
TASK: knapsacks testgen
LANG: C++
AUTHOR: Alexander Georgiev
CONTEST: Winter Mathematical Festivals
*/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

#define MAX 1024
#define MOD 1000000007

int n, c1, c2, c3;
int a[MAX];

void printTest(int test)
{
	char outName[32];
	sprintf(outName, "knapsacks.%02d.in", test);
	FILE *out = fopen(outName, "wt");

	fprintf(out, "%d %d %d %d\n", n, c1, c2, c3);
	for (int i = 0; i < n; i++)
		fprintf(out, "%d%c", a[i], i == n - 1 ? '\n' : ' ');

	fclose(out);
}

void specCase1()
{
	n = 50; c1 = 50, c2 = 50, c3 = 50;
	for (int i = 0; i < n; i++) a[i] = 42;
}

void specCase2()
{
	n = 4; c1 = 9, c2 = 7, c3 = 3;
	a[0] = 1; a[1] = 4; a[2] = 4; a[3] = 8;
}

void randCase(int N, int C1, int C2, int C3)
{
	n = N; c1 = C1; c2 = C2; c3 = C3;
	
	int maxc = std::max(c1, std::max(c2, c3)) / 2;
	int cap = (c1 + c2 + c3) / n, sum = c1 + c2 + c3;
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % cap + 1;
		sum -= a[i];
	}
	while (sum > 30)
	{
		int idx = rand() % n;
		int add = rand() % std::min(maxc, (sum - 30)) + 1;
		a[idx] += add; sum -= add;
	}
}

int main(void)
{
	int numTests = 10;
	for (int test = 1; test <= numTests; test++)
	{
		srand(test);
		if (test == 1) specCase1();
		if (test == 2) specCase2();
		if (test == 3) randCase(10, 21, 31, 27);
		if (test == 4) randCase(20, 101, 102, 103);
		if (test == 5) randCase(100, 199, 198, 197);
		if (test == 6) randCase(50, 255, 255, 255);
		if (test == 7) randCase(40, 400, 400, 400);
		if (test == 8) randCase(100, 299, 399, 499);
		if (test == 9) randCase(100, 500, 403, 455);
		if (test == 10) randCase(500, 499, 498, 497);

		printTest(test);
	}
	return 0;
}
