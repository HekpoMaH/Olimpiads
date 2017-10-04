/*
ID: espr1t
LANG: C++
TASK: ZeroSum
COMP: Autumn National Contest, Shumen 2011
KEYWORDS: Brute Force
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
//	freopen("ZeroSum.in", "rt", stdin);
//	freopen("ZeroSum.out", "wt", stdout);

	int a[10000], n;

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
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
	cout << ans << endl;
	return 0;
}
