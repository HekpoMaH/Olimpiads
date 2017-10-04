#include <cstdio>
#include <cstring>
#include <utility>
#include <iostream>
#include <map>
using namespace std;

typedef unsigned long long ull;

map < ull , int > m;

ull ans[2];

int ap;
int n;

int main() {
        scanf ( "%d" , &n );

        ull a;
        int i;
        for (i = 0; i < n; ++i) {
                cin >> a;
                m[a]++;
        }
        for (map < ull , int >::iterator it = m.begin(); it != m.end(); ++it) {
                if ( it->second == 1 )
                        ans[ ap++ ] = it->first;
                if ( ap == 2 ) break;
        }
        cout << ans[0] << " " << ans[1] << endl;

        return 0;
}
