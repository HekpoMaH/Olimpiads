/*
ID: espr1t
LANG: C++
TASK: Frog Testgen
*/

#include <cstdio>
#include <cstdlib>

#define MAX 131072

int nn[21] = {7, 20, 500, 1000, 2000, 5000, 10000, 20000, 30000, 50000, 70000, 80000, 90000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000};

int n;
int a[MAX][3];

int random()
{
	return (((rand() & ((1 << 15) - 1)) << 15) | (rand() & ((1 << 15) - 1)));
}

void sampleInput()
{
	n = 7;
	a[0][0] = -3; a[0][1] = 1; a[0][2] = 3;
	a[1][0] = -5; a[1][1] = 2; a[1][2] = 8;
	a[2][0] = 16; a[2][1] = 5; a[2][2] = 4;
	a[3][0] = 15; a[3][1] = 2; a[3][2] = 9;
	a[4][0] =  6; a[4][1] = 5; a[4][2] = 15;
	a[5][0] = -8; a[5][1] = 3; a[5][2] = 1;
	a[6][0] = 27; a[6][1] = 4; a[6][2] = 2;
}

void handTest1(int test)
{
	n = nn[test];
	for (int i = 0; i < n; i++)
	{
		a[i][0] = 3;
		a[i][1] = (rand() & 1) * 4 + 1;
		a[i][2] = 4;
	}
}

void handTest2(int test)
{
	n = nn[test];
	for (int i = 0; i < n; i++)
	{
		a[i][0] = i % 5 + 1;
		a[i][1] = 3;
		a[i][2] = 3;
	}
}

void onlyNegative(int test)
{
	n = nn[test];
	for (int i = 0; i < n; i++)
	{
		a[i][0] = -(rand() % 1000);
		a[i][1] = rand() % 5 + 1;
		a[i][2] = rand() % 20 + 1;
	}
}

void randomTest(int test)
{
	n = nn[test];
	for (int i = 0; i < n; i++)
	{
		a[i][0] = random() % 20001 - 10000;
		a[i][1] = rand() % 5 + 1;
		a[i][2] = random() % 100000 + 1;
	}
	if (test >= 7)
	{
		int idx = n / 2 + rand() % (n / 10) - n / 20;
		int offset = rand() % 5000 + 1000;
		for (int i = 0; i < offset; i++)
			a[idx + i][0] = -(random() % 100001);
	}
}

void largeGaps1(int test)
{
	n = nn[test];
	for (int i = 0; i < n; i++)
	{
		if (i % 1000 == 0)
		{
			a[i][0] = 10000;
			a[i][1] = 1;
		}
		else
		{
			a[i][0] = rand() % 10 - 5;
			a[i][1] = 5;
		}
		a[i][2] = 1013;
	}
}

void largeGaps2(int test)
{
	n = nn[test];
	for (int i = 0; i < n; i++)
	{
		if (i % 10000 == 0)
		{
			a[i][0] = 10000;
			a[i][1] = 1;
		}
		else
		{
			a[i][0] = rand() % 6 - 3;
			a[i][1] = 5;
		}
		a[i][2] = 10001;
	}
}

void maxAnsPositive(int test)
{
	n = nn[test];
	for (int i = 0; i < n; i++)
	{
		a[i][0] = 10000;
		a[i][1] = 1;
		a[i][2] = 100000;
	}
}

void maxAnsNegative(int test)
{
	n = nn[test];
	for (int i = 0; i < n; i++)
	{
		a[i][0] = -10000;
		a[i][1] = 5;
		a[i][2] = 1;
	}
}

void printTest(int test)
{
	char fileName[32];
	sprintf(fileName, "Frog.%02d.in", test);
	FILE *out = fopen(fileName, "wt");

	fprintf(out, "%d\n", n);
	for (int i = 0; i < n; i++)
		fprintf(out, "%d %d %d\n", a[i][0], a[i][1], a[i][2]);
	fclose(out);
}

int main(void)
{
	srand(42);
	int numTests = 20;
	for (int test = 0; test <= numTests; test++)
	{
		fprintf(stderr, "Generating testcase %d...\n", test);

		if (test == 0) sampleInput();
		if (test == 1) handTest1(test);
		if (test == 2) handTest2(test);
		if (test == 3) onlyNegative(test);
		if (test == 4) randomTest(test);
		if (test == 5) randomTest(test);
		if (test == 6) randomTest(test);
		if (test == 7) randomTest(test);
		if (test == 8) randomTest(test);
		if (test == 9) randomTest(test);
		if (test == 10) randomTest(test);
		if (test == 11) randomTest(test);
		if (test == 12) randomTest(test);
		if (test == 13) randomTest(test);
		if (test == 14) randomTest(test);
		if (test == 15) randomTest(test);
		if (test == 16) randomTest(test);
		if (test == 17) largeGaps1(test);
		if (test == 18) largeGaps2(test);
		if (test == 19) maxAnsPositive(test);
		if (test == 20) maxAnsNegative(test);
		printTest(test);
	}
	fprintf(stderr, "Finished generating all tests!\n");
	system("pause");
	return 0;
}
