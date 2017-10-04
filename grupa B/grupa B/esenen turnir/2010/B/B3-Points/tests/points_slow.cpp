// tries all possible combinations and checks whether the sum is bigger or equal to t

#include <iostream>

using namespace std;

const int MAXN = 36;

int n;
long long t;
long long points[MAXN + 1];

long long res = 0;

void generateAll(int i, long long sum)
{
	if (i >= n)
		{
			if (sum >= t) res++;
			return;
		}

	generateAll(i + 1, sum);
	generateAll(i + 1, sum + points[i]);
}

int main()
{
	cin >> n >> t;
	for (int i = 0; i < n; i++)
		cin >> points[i];

	generateAll(0, 0);

	cout << res << endl;

	return 0;
}
