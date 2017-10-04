#include <iostream>
#include <fstream>
#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <string>
#include <map>

using namespace std;

const long double TL = 1.8;

long long n;

void Load()
{
	cin >> n;
}

void Solve()
{
	long long a, b;
	long long ba = ((long long)sqrt((long double)n / 6.0));
	long long vm = ba * ba * ba;
	long long ma, mb, mc;
	ma = mb = mc = ba;
	clock_t begtime = clock();
	for (a = ba; a <= n; a++)
	{
		long double bmax = (-2.0 * a + sqrt(4.0 * a * a + 2 * n)) / 2;
		long double ansmax = a * bmax * bmax;
		if (ansmax < vm) break;
		long long cb = (n / 2 - a) / (a + 1);
		if (cb > a) cb = a;
		//cerr << a << " " << cb << "\n";
		for (b = cb; b >= 1; b--)
		{
			if (b * b * a < vm) break;
			long long cc = (n / 2 - a * b) / (a + b);
			if (cc > b) break;
			if (a * b * cc > vm)
			{
				vm = a * b * cc;
				ma = a;
				mb = b;
				mc = cc;
			}
		}
		if (clock() - begtime >= TL * CLOCKS_PER_SEC) break;
	}
	cout << vm << "\n" << ma << " " << mb << " " << mc << "\n";
}

int main()
{
	freopen("gift.in", "rt", stdin);
	freopen("gift.out", "wt", stdout);
	Load();
	Solve();
	return 0;
}