#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int bitCount(int x)
{
	int cnt = 0;
	while (x > 0)
	{
		cnt++;
		x = x & (x - 1);
		//x = x - (x & (-x)); second way
	}

	return cnt;
}

string bitString(int x, int n)
{
	string res = "";
	for (int i = 0; i < n; i++)
	{
		if (x & 1)
		{
			res = "1" +res;
		}
		else
		{
			res = "0" + res;
		}
		x = x >> 1;
	}

	return res;
}

long long binCoef(int n, int k)
{
	if (k > n - k) k = n - k;
	if (k == 0) return 1;
	if (k < 0) return 0;

	long long res = 1;
	for (int i = 1; i <= k; i++)
	{
		res = res * (n - i + 1) / i;
	}

	return res;
}

int main()
{
	int n, k;
	cin >> n >> k;

	cout << binCoef(n, k) << endl;

	/*
	int res = 0;
	for (int x = 0; x < (1 << n); x++)
	{
		if (bitCount(x) == k)
		{
			cout << bitString(x, n) << " " << res << endl;
			res++;
		}
		//cout << bitString(x, n) << " " << x << endl;
	}
	*/
	return 0;
}
