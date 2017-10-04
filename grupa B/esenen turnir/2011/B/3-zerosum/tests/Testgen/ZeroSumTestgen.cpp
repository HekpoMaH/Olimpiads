/*
ID: espr1t
LANG: C++
TASK: ZeroSum Testgen
COMP: Autumn National Contest, Shumen 2011
KEYWORDS: Inner cycle optimization, Binary Search, Brute Force
*/

#include <cstdio>
#include <vector>

#define MAX 10002

using namespace std;
FILE* in; FILE* out;

int a[MAX], n;

int isPrime(int n)
{
	if (n < 2) return 0;
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0) return 0;
	return 1;
}

void sampleInput()
{
	n = 10;
	int arr[10] = {2, -5, 2, 3, -4, 7, -4, 0, 1, -6};
	for (int i = 0; i < n; i++) a[i] = arr[i];
}

void testWithOneNumber()
{
	n = 1;
	a[0] = 42;
}

void testWithAnswerZero()
{
	n = 5;
	a[0] = -5; a[1] = 3; a[2] = 3; a[4] = -2; a[5] = 4;
}

void testWithPrimeNumbers(int n_)
{
	n = n_;
	vector <int> primes;
	for (int i = 2; i <= 10000; i++)
	{
		if (primes.size() >= n) break;
		if (isPrime(i)) primes.push_back(i);
	}
	for (int i = 0; i < n; i++)
		a[i] = primes[rand() % (int)primes.size()];
	for (int i = 0; i < n; i++)
		if (rand() % 2) a[i] = -a[i];
}

void testWithFibonacciNumbers(int n_)
{
	n = n_;
	vector <int> fibo;
	fibo.push_back(0);
	fibo.push_back(1);
	while (fibo.back() <= 10000)
		fibo.push_back(fibo[fibo.size() - 1] + fibo[fibo.size() - 2]);
	fibo.pop_back();
	for (int i = 0; i < n; i++)
		a[i] = fibo[rand() % (int)fibo.size()];
	for (int i = 0; i < n; i++)
		if (rand() % 2) a[i] = -a[i];
}

void testWithSymmetricNumbers(int n_)
{
	n = n_;
	for (int i = 0; i < n; i++)
		a[i] = i - n / 2;
}

void testWithAllZero(int n_)
{
	n = n_;
	for (int i = 0; i < n; i++) a[i] = 0;
}

void testWithTwoDistinctValues(int n_)
{
	n = n_;
	for (int i = 0; i < n / 3; i++) a[i] = 42;
	for (int i = n / 3; i < n; i++) a[i] = -21;
}

void testWithTenDistinctValues(int n_)
{
	n = n_;
	int arr[10] = {2, -5, 2, 3, -4, 7, -4, 0, 1, -6};
	for (int i = 0; i < n; i++) a[i] = arr[rand() % 10];
}

void testWithMostlyPositive(int n_)
{
	n = n_;
	a[0] = -42;
	a[1] = -13;
	a[2] = -666;
	a[3] = -1337;
	for (int i = 4; i < n; i++)
		a[i] = rand() % 10001;
}

void randomTest(int n_)
{
	n = n_;
	for (int i = 0; i < n; i++)
		a[i] = rand() % 20001 - 10000;
}

void printTest(int test)
{
	char fileName[32];
	sprintf(fileName, "ZeroSum.%02d.in", test);
	FILE* out = fopen(fileName, "wt");
	fprintf(out, "%d\n", n);
	for (int i = 0; i < n; i++)
		fprintf(out, "%d%c", a[i], i + 1 == n ? '\n' : ' ');
	fclose(out);
}

int main(void)
{
	srand(42);
	int numTests = 20;
	for (int test = 0; test <= numTests; test++)
	{
		if (test == 0) sampleInput();
		if (test == 1) testWithOneNumber();
		if (test == 2) testWithAnswerZero();
		if (test == 3) testWithPrimeNumbers(20);
		if (test == 4) testWithFibonacciNumbers(20);
		if (test == 5) testWithSymmetricNumbers(100);
		if (test == 6) testWithAllZero(1000);
		if (test == 7) randomTest(2000);
		if (test == 8) testWithSymmetricNumbers(2000);
		if (test == 9) testWithPrimeNumbers(2000);
		if (test == 10) testWithTwoDistinctValues(5000);
		if (test == 11) testWithTenDistinctValues(5000);
		if (test == 12) testWithFibonacciNumbers(3000);
		if (test == 13) randomTest(4000);
		if (test == 14) randomTest(5000);
		if (test == 15) testWithMostlyPositive(7000);
		if (test == 16) testWithSymmetricNumbers(8000);
		if (test == 17) testWithTwoDistinctValues(10000);
		if (test == 18) testWithTenDistinctValues(10000);
		if (test == 19) randomTest(9000);
		if (test == 20) randomTest(10000);
		printTest(test);
	}
	fprintf(stderr, "Finished generating tests!\n");
	system("pause");
	return 0;
}
