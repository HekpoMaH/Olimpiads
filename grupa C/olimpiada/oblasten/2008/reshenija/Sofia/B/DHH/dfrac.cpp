#include <cstring>
#include <iostream>

using namespace std;

long long k,l;
int a,b,p,s;

int main ()
{
	cin >> a >> b >> k >> p;
	for (l=1;l<k;l++)
	{
		a*=10;
		a%=b;
	}
	for (l=0;l<p;l++)
	{
		a*=10;
		cout << a/b;
		a%=b;
	}
	cout << '\n';
	return 0;
}
