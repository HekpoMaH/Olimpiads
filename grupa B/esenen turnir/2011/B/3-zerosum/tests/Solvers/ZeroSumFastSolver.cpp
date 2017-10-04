/*
ID: espr1t
LANG: C++
TASK: ZeroSum
COMP: Autumn National Contest, Shumen 2011
KEYWORDS: Binary Search, Brute Force
*/

#include <cstdio>
#include <string>
#include <algorithm>

#define MAX 32768

using namespace std;
FILE* in; FILE* out;

int a[MAX], n;

string toString(long long num)
{
	if (num <= 0) return "0";
	string ret;
	while (num) {ret.push_back(num % 10 + 48); num /= 10;}
	reverse(ret.begin(), ret.end());
	return ret;
}

long long solve()
{
	sort(a, a + n);

	long long ans = 0;
	for (int i = 0; i < n; i++)
	{
		int idx1 = i + 1, idx2 = n - 1, lidx2 = n;
		while (idx1 < idx2)
		{
			int sum = a[i] + a[idx1] + a[idx2];
			if (sum == 0)
			{
				if (a[idx1] == a[idx2])
				{
					ans += idx2 - idx1;
					idx1++;
				}
				else
				{
					if (lidx2 > idx2)
					{
						lidx2 = idx2;
						while (lidx2 - 1 >= 0 && a[lidx2 - 1] == a[idx2]) lidx2--;
					}
					ans += idx2 - lidx2 + 1;
					idx1++;
				}
			}
			else if (sum < 0) idx1++;
			else idx2--;
		}
	}
	return ans;
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
		
		in = fopen(outFile, "rt");
		char buff[32];
		fscanf(in, "%s", buff);
		long long realAns = 0;
		for (int i = 0; i < (int)strlen(buff); i++)
			realAns = realAns * 10 + buff[i] - 48;
		
		if (ans == realAns)
			fprintf(stderr, "  >> answer %s is correct, solved for %.3lf seconds\n",
				toString(ans).c_str(), (double)(clock() - sTime) / CLOCKS_PER_SEC);
		else
		{
			fprintf(stderr, "  >> answer %s is incorrect, solved for %.3lf seconds\n",
				toString(ans).c_str(), (double)(clock() - sTime) / CLOCKS_PER_SEC);
			system("pause");
		}
		
		/*
		FILE* out = fopen(outFile, "wt");
		fprintf(out, "%s\n", toString(ans).c_str());
		fclose(out);
		fprintf(stderr, "  >> answer is %s, solved for %.3lf seconds.\n",
			toString(ans).c_str(), (double)(clock() - sTime) / CLOCKS_PER_SEC);
		*/
	}
	fprintf(stderr, "Solved all testcases.\n");
	system("pause");
	return 0;
}
