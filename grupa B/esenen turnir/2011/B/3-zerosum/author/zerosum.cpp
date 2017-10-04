/*
ID: espr1t
LANG: C++
TASK: ZeroSum
COMP: Autumn National Contest, Shumen 2011
KEYWORDS: Inner Cycle Optimization, Brute Force
*/

#include <iostream>
#include<algorithm>
#define MAX 16384
using namespace std;
FILE* in; FILE* out;

int a[MAX], n;

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
	in = stdin; out = stdout;
//	in = fopen("ZeroSum.in", "rt"); out = fopen("ZeroSum.out", "wt");

	fscanf(in, "%d", &n);
	for (int i = 0; i < n; i++)
		fscanf(in, "%d", &a[i]);

	fprintf(out, "%s\n", toString(solve()).c_str());
	return 0;
}
