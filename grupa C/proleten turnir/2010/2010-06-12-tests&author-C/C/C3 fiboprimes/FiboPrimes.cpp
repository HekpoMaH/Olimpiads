/*
LANG: C++
TASK: fibo
AUTH: Alexander Georgiev
COMP: Spring National Contest
*/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

#define MAX 100000000
#define FIB 128

FILE *in; FILE *out;

char dyn[MAX];
long long fib[FIB]; int len;

int isPrime(long long num)
{
	if (num < 2) return 0;
	for (long long i = 2; i * i <= num; i++)
		if (num % i == 0) return 0;
	return 1;
}

int eval(long long num)
{
	if (num < 2) return 0;

	if (num < MAX && dyn[num] != -1) return dyn[num];

	int best = 0, add = 0;
	if (isPrime(num)) {best = 1; add = 1;}
	for (int i = 0; fib[i] < num; i++)
		best = std::max(best, add + eval(num / fib[i]));

	if (num < MAX) dyn[num] = best;
	return best;
}

int main(void)
{
	in = stdin; out = stdout;
//	in = fopen("FiboPrimes.in", "rt"); out = fopen("FiboPrimes.out", "wt");

	char tmp[32];
	fscanf(in, "%s", tmp);
	long long n = 0;
	for (int i = 0; i < (int)strlen(tmp); i++) n = n * 10 + tmp[i] - 48;

	fib[0] = 2; fib[1] = 3; len = 2;
	while (fib[len-1] <= n) fib[len++] = fib[len - 1] + fib[len - 2];

	memset(dyn, -1, sizeof(dyn));
	fprintf(out, "%d\n", eval(n));
	return 0;
}
