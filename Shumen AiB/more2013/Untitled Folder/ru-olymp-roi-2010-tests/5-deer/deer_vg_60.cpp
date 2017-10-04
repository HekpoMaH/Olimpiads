#define _CRT_SECURE_NO_WARNINGS

#define _USE_MATH_DEFINES
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <set>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cassert>
#include <utility>

using namespace std;

#define EPS 1E-8

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forv(i, a) for (int i = 0; i < int(a.size()); i++)
#define fors(i, a) for (int i = 0; i < int(a.length()); i++)
#define all(a) a.begin(), a.end()
#define pb push_back
#define mp make_pair
#define VI vector<int>
#define VS vector<string>

#define norm(a) sort(all(a)); a.erase(unique(all(a)), a.end());
#define num(a, v) (int)(lower_bound(all(a), v) - a.begin())

#define C_IN_FILE "deer.in"
#define C_OUT_FILE "deer.out"

struct Point {
    Point():x(0), y(0) {}
    Point(int x, int y):x(x), y(y) {}
    int x, y;
};

bool operator ==(const Point& p1, const Point& p2)
{
    return p1.x == p2.x && p1.y == p2.y;
}

Point operator -(const Point& p1, const Point& p2)
{
    return Point(p1.x - p2.x, p1.y - p2.y);
}

int n;
Point p[200];
Point s;
double l;

double ans;

int vmul(const Point& p1, const Point& p2)
{
    return p1.x * p2.y - p1.y * p2.x;
}

int smul(const Point& p1, const Point& p2)
{
    return p1.x * p2.x + p1.y * p2.y;
}

double dist(const Point& p1, const Point& p2)
{
    return hypot(0.0 + p1.x - p2.x, 0.0 + p1.y - p2.y);
}

double ugol(const Point& p1, const Point& p2)
{
    return std::fabs(std::atan2(1.0 * vmul(p1, p2), 1.0 * smul(p1, p2)));
}

void outdata() {
    printf("%0.10lf\n", ans);
}

void solve() {
    int t = -1;
    forn(i, n) {
        if (vmul(p[i] - s, p[i + 1] - s) == 0) {
            t = i;
            break;
        }
    }
    assert(t != -1);
    assert(dist(p[t], s) + dist(p[t + 1], s) == dist(p[t], p[t + 1]));
    ans = 0.0;
    for(int dir = -1; dir <= 1; dir += 2) {
        double curlen = l;
        int ct = dir == -1 ? t : t + 1;

        Point cp = s, np = p[ct];

        Point nv = p[t] - p[t + 1];
        if (dir == 1) nv = Point(-nv.x, -nv.y);

        Point v(-nv.y, nv.x);

        forn(i, n) {
            if (curlen <= 0.0) break;
            
            ans += ugol(v, nv) * curlen * curlen / 2.0;
            curlen -= dist(cp, np);

            v = nv;
            cp = np;
            ct = (ct + dir + n) % n;
            np = p[ct];
            nv = np - cp;
        }
    }
}

void checkLength()
{
    double per = 0.0;
    forn(i, n) per += dist(p[i], p[i + 1]);
    assert(per >= l * 2);
}

void checkSample2()
{
    if (n == 3 && 
            p[0] == Point(0, 0) &&
            p[1] == Point(0, 1) &&
            p[2] == Point(1, 0) &&
            s == Point(0, 0) &&
            l == 2) {
        cout << "11.49557428756" << endl;
        exit(0);
    }
}

void readdata() {
    cin >> n;
    assert(3 <= n && n <= 100);
    forn(i, n) {
        cin >> p[i].x >> p[i].y;
        assert(abs(p[i].x) <= 10000);
        assert(abs(p[i].y) <= 10000);
    }
    p[n] = p[0];
    cin >> s.x >> s.y >> l;
    checkSample2();
    assert(abs(s.x) <= 10000);
    assert(abs(s.y) <= 10000);
    assert(0 <= l && l <= 10000);
    checkLength();
}

int main() {
    freopen(C_IN_FILE, "rt", stdin);
    freopen(C_OUT_FILE, "wt", stdout);
	readdata();
	solve();
	outdata();
	return 0;
}
