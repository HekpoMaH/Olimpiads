/*
ID: espr1t
LANG: C++
TASK: Graze
KEYWORDS: Testgen
*/

#include <cstdio>
#include <cstdlib>

#define MAX 131072
#define MM 1000000
using namespace std;

int n, m, k;
int a[MAX], b[MAX];

int random()
{
	return (((rand() & ((1 << 15) - 1)) << 16) | (rand() & ((1 << 16) - 1)));
}

void randomTest(int n_, int m_, int k_)
{
	n = n_; m = m_; k = k_;
	for (int i = 0; i < n; i++)
		a[i] = random() % MM + 1;
	for (int i = 0; i < m; i++)
		b[i] = random() % MM + 1;
}

void sampleInput()
{
	n = 7; m = 3; k = 3;
	a[0] = 4; a[1] = 9; a[2] = 8; a[3] = 2; a[4] = 4; a[5] = 6; a[6] = 5;
	b[0] = 2; b[1] = 7; b[2] = 2;
}

void shuffledSampleInput()
{
	n = 7; m = 3; k = 3;
	a[0] = 8; a[1] = 5; a[2] = 4; a[3] = 9; a[4] = 4; a[5] = 6; a[6] = 2;
	b[0] = 7; b[1] = 2; b[2] = 2;
}

void onlyOneSheep()
{
	n = 1; m = 5; k = 4;
	a[0] = 42;
	b[0] = 1; b[1] = 13; b[2] = 17; b[3] = 107; b[4] = 666;
}

void onlyOneBarn()
{
	n = 5; m = 1; k = 7;
	a[0] = 1; a[1] = 13; a[2] = 17; a[3] = 107; a[4] = 666;
	b[0] = 42;
}

void oneSheepPerBarn()
{
	randomTest(1000, 1000, 1);
}

void everyoneInOnePlace()
{
	n = 1000; m = 1000; k = 1;
	for (int i = 0; i < n; i++) a[i] = 42;
	for (int i = 0; i < m; i++) b[i] = 42;
}

void overflow()
{
	randomTest(33334, 33333, 99999);
}

void impossible1()
{
	randomTest(100000, 42666, 2);
}

void impossible2()
{
	randomTest(100000, 13, 7692);
}

void twoComponents()
{
	n = 66666; m = 22222; k = 4;
	for (int i = 0; i < n; i++)
		a[i] = i < 22222 ? random() % 20000 + 1 : random() % 20000 + 800000;
	for (int i = 0; i < m; i++)
		b[i] = i < 11111 ? random() % 200000 + 1 : random() % 200000 + 800000;
}


void threeComponents()
{
	n = 100000; m = 200; k = 5005;
	int off[3] = {1, 300000, 600000};
	for (int i = 0; i < n; i++)
		a[i] = off[rand() % 3] + random() % 100000;
	for (int i = 0; i < m; i++)
		b[i] = off[rand() % 3] + random() % 10000;
}

void oneVeryFarAway()
{
	n = 10000; m = 3000; k = 4;
	for (int i = 0; i < n - 5; i++)
		a[i] = random() % 10000 + 1;
	for (int i = n - 5; i < n; i++)
		a[i] = random() % 10000 + 500000;
	for (int i = 0; i < m - 1; i++)
		b[i] = random() % 5000 + 2501;
	b[m - 1] = 505505;
}

void allVeryFarAway()
{
	n = 100000; m = 100000; k = 1;
	for (int i = 0; i < n; i++)
		a[i] = rand() % 10 + 1;
	for (int i = 0; i < m; i++)
		b[i] = rand() % 10 + 999990;
}

void printTest(int test)
{
	int flag = 0;
	if (n < 1 || n > 100000)
		{fprintf(stderr, "n is out of bounds (%d, must be between 1 and 100000)\n", n); flag = 1;}
	if (m < 1 || m > 100000)
		{fprintf(stderr, "m is out of bounds (%d, must be between 1 and 100000)\n", m); flag = 1;}
	if (k < 1 || k > 100000)
		{fprintf(stderr, "k is out of bounds (%d, must be between 1 and 100000)\n", k); flag = 1;}
	for (int i = 0; i < n; i++) if (a[i] < 1 || a[i] > 1000000)
		{fprintf(stderr, "a[i] is out of bounds (%d, must be between 1 and 1000000)\n", a[i]); flag = 1;}
	for (int i = 0; i < m; i++) if (b[i] < 1 || b[i] > 1000000)
		{fprintf(stderr, "b[i] is out of bounds (%d, must be between 1 and 1000000)\n", b[i]); flag = 1;}
	if (flag) system("pause");
	
	char fileName[32];
	sprintf(fileName, "Graze.%02d.in", test);
	FILE* out = fopen(fileName, "wt");
	fprintf(out, "%d %d %d\n", n, m, k);
	for (int i = 0; i < n; i++)
		fprintf(out, "%d%c", a[i], i + 1 == n ? '\n' : ' ');
	for (int i = 0; i < m; i++)
		fprintf(out, "%d%c", b[i], i + 1 == m ? '\n' : ' ');
	fclose(out);
}


int main(void)
{
	srand(42);	
	int numTests = 20;
	for (int test = 0; test <= numTests; test++)
	{
		fprintf(stderr, "Currently generating test case Nr.%02d\n", test);
		
		if (test == 0) sampleInput();
		if (test == 1) shuffledSampleInput();
		if (test == 2) onlyOneSheep();
		if (test == 3) onlyOneBarn();
		if (test == 4) oneSheepPerBarn();
		if (test == 5) everyoneInOnePlace();
		if (test == 6) randomTest(50, 20, 3);
		if (test == 7) randomTest(100, 20, 5);
		if (test == 8) randomTest(200, 300, 2);
		if (test == 9) randomTest(500, 10, 52);
		if (test == 10) randomTest(1000, 100, 12);
		if (test == 11) twoComponents();
		if (test == 12) threeComponents();
		if (test == 13) oneVeryFarAway();
		if (test == 14) allVeryFarAway();
		if (test == 15) randomTest(80000, 100, 813);
		if (test == 16) randomTest(100000, 80000, 11);
		if (test == 17) randomTest(100000, 100000, 2);
		if (test == 18) impossible1();
		if (test == 19) impossible2();
		if (test == 20) overflow();
		
		printTest(test);
	}
	fprintf(stderr, "Finished all test cases!\n");
	system("pause");
	return 0;
}
