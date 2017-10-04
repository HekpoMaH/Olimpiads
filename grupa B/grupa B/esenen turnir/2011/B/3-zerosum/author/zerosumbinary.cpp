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
	in = stdin; out = stdout;
//	in = fopen("ZeroSum.in", "rt"); out = fopen("ZeroSum.out", "wt");
	
	fscanf(in, "%d", &n);
	for (int i = 0; i < n; i++)
		fscanf(in, "%d", &a[i]);
	fprintf(out, "%s\n", toString(solve()).c_str());
	return 0;
}
