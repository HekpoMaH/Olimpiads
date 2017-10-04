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

#define MAX 10002

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

int binarySearch(int leftPos, int rightPos, int num)
{
	if (a[rightPos] < num) return 0;

	int left, right, mid;
	int lower = rightPos + 1, upper = leftPos - 1;
	
	// Search left side of interval (lower_bound)
	left = leftPos; right = rightPos;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (a[mid] == num) lower = min(lower, mid);
		if (a[mid] < num) left = mid + 1;
		else right = mid - 1;
	}
	if (lower > rightPos) return 0;
	
	// Search right side of interval (upper_bound)
	left = leftPos; right = rightPos;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (a[mid] == num) upper = max(upper, mid);
		if (a[mid] <= num) left = mid + 1;
		else right = mid - 1;
	}
	return max(0, upper - lower + 1);
}

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
			ans += binarySearch(c + 1, n - 1, -a[i] - a[c]);
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
