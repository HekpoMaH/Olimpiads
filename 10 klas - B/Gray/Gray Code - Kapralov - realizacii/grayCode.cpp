#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

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

int main()
{
	int n;
	cin >> n;

	int x = 0;
	cout <<  bitString(x, n) << " 0" << endl;
	for (int i = 1; i < (1 << n); i++)
	{
		int p = i & (-i);
		x = x ^ p;
		cout << bitString(x, n)  << " " << i << " " << bitString((i ^ (i << 1)) >> 1, n) << endl;
	}
	return 0;
}
