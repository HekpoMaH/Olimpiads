#include <iostream>
#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;

int main() {
    //freopen("conquest.in", "r", stdin);
    //freopen("conquest.out", "w", stdout);

    int n;
    cin >> n;
    pair<int, int> c[n];
    int total = 0;
    for (int i = 0; i < n; i++) {
        int ca, cc;
        cin >> ca >> cc;
        c[i] = make_pair(ca, cc);
        total += ca;
    }
    sort(c, c + n);

    int sum[n + 1];
    sum[0] = 0;
    for (int i = 0; i < n; i++) {
        sum[i + 1] = sum[i] + c[i].first;
    }

    int INF = 1000000000;
    int d[n + 1][total + 1];
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= total; j++) {
            d[i][j] = INF;
        }
    }

    for (int j = 0; j <= total; j++) {
        d[0][j] = 0;
    }
    

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= total; j++) {
            if (d[i][j] != INF) {
                for (int k = 0; k <= c[i].first && k <= j; k++) {
                    int cost = k * c[i].second;
                    int count = sum[i] + j;
                    
                    if (count > c[i].first - k && d[i][j] + cost < d[i + 1][j - k]) {
                         d[i + 1][j - k] = d[i][j] + cost;                     
                    }

 

                }
            }
        }
    }

    cout << d[n][0] << endl;

    return 0;
}
