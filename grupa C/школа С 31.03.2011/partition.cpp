/*
Contest:
Task:
*/
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <stdlib.h>
#include <iomanip>
#include <fstream>
#include <set>

#define SP system("pause");
#define x first
#define y second

int maxn = 99999;

typedef long long int lli;

using namespace std;

int main()
{
    long long int n;
    long long int a, b, c, d;
    a = 0;
    b = 1;
    c = 1;
    cin >> n;
    for ( int i = 5; i <= n; i++ )
    {
        d = ( a + c ) % 1000000007;
        a = b;
        b = c;
        c = d;
    }
    cout << c << endl;
        SP;
	return 0;
}
