#include <iostream>

using namespace std;

void read ()
{
    int n, a, i, j, p;
    for ( p = 1; p <= 9; p++ )
    {
	cin >> n;
	cout << n << endl;
	for ( i = 1; i <= n; i++ )
	{
	    for ( j = 1; j <= n - 1; j++ )
	    {
		cin >> a;
		cout << a << ' ';
	    }
	    cin >> a; 
	    cout << a << endl;
	}
    }
}

int main ()
{
    read ();
    return 0;
}