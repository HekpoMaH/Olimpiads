#include <iostream>

using namespace std;

int main()
{
	int n, m, k;
	int a, b;

	cin >> n >> m >> k;

	bool answ = false;
	for(int i = 0; i < k; i++)
	{
		cin >> a >> b;
		if (n - a < 5 || a <= 5 || m - b < 5 || b <= 5)
		{
			answ = true;
		}
	}

	if(answ)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}

	return 0;
}
