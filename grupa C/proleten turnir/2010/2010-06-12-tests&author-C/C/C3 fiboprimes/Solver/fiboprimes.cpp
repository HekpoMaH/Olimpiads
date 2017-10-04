#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <stdio.h>
#include <iostream>

#define FIB 128
using namespace std;
FILE *in; FILE *out;

map <int, int> dyn;
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
	if (dyn.find(num) != dyn.end()) return dyn[num];
	
	int best = 0, add = 0;
	if (isPrime(num)) {best = 1; add = 1;}
	for (int i = 0; fib[i] < num; i++)
		best = max(best, add + eval(num / fib[i]));
	
	return dyn[num] = best;
}

int main(void)
{
//	int numTests = 20;
//	for (int curTest = 1; curTest <= numTests; curTest++)
//	{
//		unsigned sTime = clock();
//		fprintf(stderr, "Solving testcase %d...", curTest);

//		char inpFile[32], outFile[32];
//		sprintf(inpFile, "FiboPrimes.%02d.in", curTest);
//		sprintf(outFile, "FiboPrimes.%02d.out", curTest);
//		in = fopen(inpFile, "rt"); out = fopen(outFile, "wt");

		char tmp[32];
		scanf("%s", tmp);
		long long n = 0;
		for (int i = 0; i < (int)strlen(tmp); i++) n = n * 10 + tmp[i] - 48;
	
		fib[0] = 2; fib[1] = 3; len = 2;
		while (fib[len-1] <= n) fib[len++] = fib[len - 1] + fib[len - 2];
		
		dyn.clear();
		printf("%d\n", eval(n));
//		fclose(in); fclose(out);
//		fprintf(stderr, " Execution time was %.3lfs\n", (double)(clock() - sTime) / (double)CLOCKS_PER_SEC);
//	}
//	fprintf(stderr, "Finished solving tests!\n");
//	system("pause");	
	return 0;
}
