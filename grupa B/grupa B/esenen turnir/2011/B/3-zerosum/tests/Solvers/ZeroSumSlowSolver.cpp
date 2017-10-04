/*
ID: espr1t
LANG: C++
TASK: ZeroSum
COMP: Autumn National Contest, Shumen 2011
KEYWORDS: Inner cycle optimization, Brute Force
*/

#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <string>

#define MAX 10002

using namespace std;
FILE* in; FILE* out;

int a[MAX], n;

long long solve()
{
	sort(a, a + n);
	long long ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > 0) break;
		for (int c = i + 1; c < n; c++)
		{
			if (a[i] + a[c] > 0) break;
			for (int j = c + 1; j < n; j++)
			{
				if (a[i] + a[c] + a[j] > 0) break;
				if (a[i] + a[c] + a[j] == 0) ans++;
			}
		}
	}
	return ans;
}

string toString(long long num)
{
	if (num <= 0) return "0";
	string ret;
	while (num) {ret.push_back(num % 10 + 48); num /= 10;}
	reverse(ret.begin(), ret.end());
	return ret;
}

int main(void)
{
	int numTests = 20;
	for (int test = 0; test <= numTests; test++)
	{
		unsigned sTime = clock();
		fprintf(stderr, "Solving testcase %d...\n", test);
		char inpFile[32], outFile[32];
		sprintf(inpFile, "ZeroSum.%02d.in", test);
		sprintf(outFile, "ZeroSum.%02d.sol", test);
		
		FILE* in = fopen(inpFile, "rt");
		fscanf(in, "%d", &n);
		for (int i = 0; i < n; i++)
			fscanf(in, "%d", &a[i]);
		fclose(in);
		
		long long ans = solve();
		FILE* out = fopen(outFile, "wt");
		fprintf(out, "%s\n", toString(ans).c_str());
		fclose(out);
		fprintf(stderr, "  >> answer is %s, solved for %.3lf seconds.\n",
			toString(ans).c_str(), (double)(clock() - sTime) / CLOCKS_PER_SEC);
	}
	fprintf(stderr, "Solved all testcases.\n");
	system("pause");
	return 0;
}
