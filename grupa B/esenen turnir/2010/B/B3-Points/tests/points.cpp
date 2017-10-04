#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 36;

int main()
{
	int n;
	long long t;
	long long points[MAXN + 1];
  vector < long long > scores;

	cin >> n >> t;
	for (int i = 0; i < n; i++)
		cin >> points[i];

	int middle = n / 2;
	for (int mask = 0; mask < (1 << middle); mask++)
		{
			long long tempSum = 0;
			for (int i = 0; i < middle; i++)
				if (mask & (1 << i)) tempSum += points[i];

			scores.push_back(tempSum);
		}

	int size = scores.size();
	sort(scores.begin(), scores.end());

	long long res = 0;

	int remain = n - middle;
	for (int mask = 0; mask < (1 << remain); mask++)
		{
			long long tempSum = 0;
			for (int i = 0; i < remain; i++)
				if (mask & (1 << i)) tempSum += points[middle + i];

			int lf = -1, rt = size, mid;
			while (lf + 1 < rt)
				{
					mid = lf + rt; mid = mid >> 1;
					if (tempSum + scores[mid] >= t)
						rt = mid;
					else
						lf = mid;
				}

			res += size - rt;
		}

	cout << res << endl;

	return 0;
}
