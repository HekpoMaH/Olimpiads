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

	for (int x = 0; x < (1 << n); x++)
	{
		cout << bitString(x, n) << " " << x << endl;
	}
	return 0;
}
