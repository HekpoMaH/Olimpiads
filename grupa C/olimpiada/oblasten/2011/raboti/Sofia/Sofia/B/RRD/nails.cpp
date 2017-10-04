#include <iostream>
#include <vector>

using namespace std;

#define F first
#define S second

struct point {
    int x, y;
};

const int MAXN = (1 << 10);
pair <point, point> a[MAXN];
int i = 1, n;
vector <int> b[MAXN];
int used[MAXN];

bool orient (point a, point b, point c) {
    if (a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) >= 0) return true;
    return false;
}

int orient2 (point a, point b, point c) {
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
}

bool checker (point a1, point a2, point b1, point b2) {
     bool R1, R2, R3, R4;
     R1 = orient (b1, a1, b2);
     R2 = orient (a1, b2, a2);
     R3 = orient (b2, a2, b1);
     R4 = orient (a2, b1, a1);
     if ((R1 == R2) && (R2 == R3) && (R3 == R4)) return true;
     if ((orient2 (a1, a2, b1) == 0) && a1.x <= b1.x && b1.x <= a2.x && a1.y >= b1.y && b1.y >= a2.y) return true;
     if ((orient2 (a1, a2, b2) == 0) && a1.x <= b2.x && b2.x <= a2.x && a1.y >= b2.y && b2.y >= a2.y) return true;
     if ((orient2 (b1, b2, a1) == 0) && b1.x <= a1.x && a1.x <= b2.x && b1.y >= a1.y && a1.y >= b2.y) return true;
     if ((orient2 (b1, b2, a2) == 0) && b1.x <= a2.x && a2.x <= b2.x && b1.y >= a2.y && a2.y >= b2.y) return true;
     return false;
}

void dfs (int x) {
    used[x] = 1;
    int k = b[x].size ();
    for (int i = 0; i < k; ++ i)
        if (used[b[x][i]] == 0) dfs (b[x][i]);
}

int main () {
    while (cin >> a[i].F.x >> a[i].F.y >> a[i].S.x >> a[i].S.y) {
        if (a[i].F.y < a[i].S.y) {swap (a[i].F.x, a[i].S.x); swap (a[i].F.y, a[i].S.y);}
        else if ((a[i].F.y == a[i].S.y) && (a[i].F.x > a[i].S.x)) {swap (a[i].F.x, a[i].S.x); swap (a[i].F.y, a[i].S.y);}
        ++ i;
    }
    n = i - 2;

    for (int i = 1; i <= n; ++ i)
        for (int j = i + 1; j <= n; ++ j)
            if (checker (a[i].F, a[i].S, a[j].F, a[j].S) == true) {
                b[i].push_back (j);
                b[j].push_back (i);
            }

    for (int i = 1; i <= n; ++ i)
        if (checker (a[n+1].F, a[n+1].S, a[i].F, a[i].S) == true) {
            if (used[i] == 0) dfs (i);
        }

    int cnt = 0;
    for (int i = 1; i <= n; ++ i)
        if (used[i] == 0) ++ cnt;

    cout << cnt << endl;


    return 0;
}

/*
5 2 8 2
3 4 3 1
7 1 6 4
3 3 0 3
6 3 1 1
*/

/*for (int i = 1; i <= n; ++ i)
        cout << a[i].F.x << " " << a[i].F.y << " " << a[i].S.x << " " << a[i].S.y << endl;*/

/*point A, B, C, D;
    cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;
    cout << checker (A, B, C, D) << endl;*/

 /*cout << "YES" << " " << i << " " << j << endl;*/

/*point A, B, C, D;
    cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;
    cout << checker (A, B, C, D) << endl;
    cout << orient2 (A, B, C) << " " << orient2 (A, B, D) << " " << orient2 (C, D, A) << " " << orient2 (C, D, B) << endl;*/
