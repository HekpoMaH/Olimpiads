#include <string>
#include <climits>
#include <cstdio>
#include <ctime>
#include <queue>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>

#include <set>
#include <iostream>
#include <cassert>
#include <utility>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

const int G = 7500;

typedef long long li;

int main()
{
    freopen("gift.in", "rt", stdin);
    freopen("gift.out", "wt", stdout);

    li n;
    cin >> n;
    n /= 2;

    li x = sqrt(n / 3.0);
    li result = 0;
    li ta = -1, tb = -1, tc = -1;

    for (li d = 0; d < G; d++)
    {
        li a = x - d;

        if (a > 0)
        {
            for (li b = a; b <= x + G; b++)
            {
                li c = (n - a * b) / (a + b);
                li v = a * b * c;
                if (v > result)
                {
                    result = v;
                    ta = a, tb = b, tc = c;
                }
            }

            if (clock() > 1.5 * CLOCKS_PER_SEC)
                break;
        }
    }

    cout << result << endl;
    cout << ta << " " << tb << " " << tc << endl;

    return 0;
}
