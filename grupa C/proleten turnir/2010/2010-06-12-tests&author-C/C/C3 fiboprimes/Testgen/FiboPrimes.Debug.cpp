#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <vector>

#define MAX 100000000
#define FIB 128

using namespace std;
FILE *in; FILE *out;

char dyn[MAX];
long long fib[FIB]; int len;

int isPrime(long long num)
{
	for (long long i = 2; i * i <= num; i++)
		if (num % i == 0) return 0;
	return 1;
}

vector < pair <long long, long long> > v;

int eval(long long num)
{
	if (num < 2) return 0;
	if (num < MAX && dyn[num] != -1) return dyn[num];
	
	int best = 0, add = 0;
	long long with = -1;
	if (isPrime(num)) {best = 1; add = 1;}
	for (int i = 0; fib[i] < num; i++)
	{
		int cur = add + eval(num / fib[i]);
		if (best < cur) {with = fib[i]; best = cur;}
	}
//		best = max(best, add + eval(num / fib[i]));
	
	if (num < MAX) dyn[num] = best;
//	v.push_back(make_pair(num, with));
	return best;
}

int main(void)
{
	in = stdin; out = stdout;
	in = fopen("FiboPrimes.in", "rt"); out = fopen("FiboPrimes.out", "wt");
	
	char tmp[32];
	fscanf(in, "%s", tmp);
	long long n = 0;
	for (int i = 0; i < (int)strlen(tmp); i++) n = n * 10 + tmp[i] - 48;

	fib[0] = 2; fib[1] = 3; len = 2;
	while (fib[len-1] <= n) fib[len++] = fib[len - 1] + fib[len - 2];
	
	memset(dyn, -1, sizeof(dyn));
	long long nn = 1000000000000LL;
	while(1)
	{
		while (!isPrime(nn)) nn--;
		
		/*
		n = 0;
		for (int i = 0; i < 4; i++)
			n = n * 1000 + rand() % 1000;
		*/
		
		n = nn--;
		
//		v.clear();
//		memset(dyn, -1, sizeof(dyn));
		int best = eval(n);

		cout << n << " with best " << best << endl;
		if (best >= 17) system("pause");
		
		/*
		vector <int> p, d;
		while (n > 0)
		{
			long long with = -1;
			for (int i = 0; i < (int)v.size(); i++)
				if (v[i].first == n) {with = v[i].second; break;}
//			cout << n << " divided by " << with << " is " << n / with << endl;
			p.push_back(n); d.push_back(with);
			n /= with;
		}
		*/
		/*
		for (int i = 0; i < (int)p.size(); i++)
			cout << p[i] << ", "; cout << endl;
		for (int i = 0; i < (int)p.size(); i++)
			if (isPrime(p[i])) cout << p[i] << ", "; cout << endl;
		for (int i = 0; i < (int)d.size(); i++)
			cout << d[i] << ", "; cout << endl;
		*/
		/*
		int flag = 0;
		for (int i = 0; i < (int)d.size(); i++)
			if (d[i] > 21) {flag = 1; break;}
		if (flag)
		{
			cout << n << endl;
			for (int i = 0; i < (int)d.size(); i++)
				cout << d[i] << ", "; cout << endl;
			break;
		}
		*/
	}
	system("pause");	
	return 0;
}
