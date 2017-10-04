#include <iostream>
#include <vector>

using namespace std;

int a[10006], n, par[10006], Z = 0;
int minCNT = 2000000000;
int ans[10006];

bool checker (int s, int f) {
    if (f == s) return true;
    int br = f - s + 1;
    int k;
    if (br % 2 == 0) k = (int) (br / 2);
    else k = (int) (br / 2) + 1;

    for (int i = 1; i <= k; ++ i)
        if (a[s + i - 1] != a[f - i + 1]) return false;
    return true;
}

void rec (int x, int cnt, int Z) {
    if (x == n + 1) {
        if (minCNT > cnt) {
            minCNT = cnt;
            int r;
            for (r = 1; r <= Z - 1; ++ r)
                ans[r] = par[r];
            return;
        }
    }
    int j;
    for (j = x; j <= n; ++ j)
        if (checker (x, j) == true) {
            ++ Z;
            par[Z] = j;

            rec (j + 1, cnt + 1, Z);

            par[Z] = 0;
            -- Z;
        }
}

int main () {
    cin >> n;
    for (int i = 1; i <= n; ++ i)
        cin >> a[i];
    if (checker (1, n) == true) {
        cout << 1 << endl;
        return 0;
    }
    rec (1, 0, 0);
    cout << minCNT << endl;
    cout << ans[1];
    for (int i = 2; i <= minCNT - 1; ++ i)
        cout << " " <<ans[i];
    cout << endl;

    return 0;
}

/*
16
1 1 0 0 0 1 1 0 0 0 0 1 1 0 0 0
*/
