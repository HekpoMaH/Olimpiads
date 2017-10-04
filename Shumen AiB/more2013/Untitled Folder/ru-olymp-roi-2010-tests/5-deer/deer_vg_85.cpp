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

const double EPS = 1E-12;

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

struct point {
    point():x(0), y(0) {}
    point(double x, double y):x(x), y(y) {}
    double x, y;
};

point operator -(const point& p1, const point& p2)
{
    return point(p1.x - p2.x, p1.y - p2.y);
}

point operator +(const point& p1, const point& p2)
{
    return point(p1.x + p2.x, p1.y + p2.y);
}

struct line
{
    line(): a(0), b(0), c(0) {}
    line(double a, double b, double c): a(a), b(b), c(c) {}
    double a, b, c;
};

int n;
point p[200];
point s;
double l;

double ans;

struct circle {
    double x, y, r;
    circle() {};
    circle(double x, double y, double r) 
        :x(x), y(y), r(r)
    {}
};

int sign(double x) {
    if (x < -EPS) return -1;
    if (x > EPS) return 1;
    return 0;
}

inline double sqr(double x) {
    return x * x;
}

int cross(line l, circle c, vector<point> &res) {
    // -1 = infinity; 0 = Empty; n = number of points
    point centre(c.x, c.y);
    l.c += l.a * c.x + l.b * c.y;
    res.clear();
    double d = l.a * l.a + l.b * l.b;
    point r;
    if (sign(d) == 0) {
        if (sign(l.c) != 0) return 0;
        if (sign(c.r) > 0) return -1;
        r.x = r.y = 0;
        res.pb(r + centre);
        return 1;
    } else {
		if (abs(l.c) > c.r*sqrt(d) + EPS) {
            return 0;
		}
        double t=sqrt(fabs(c.r*c.r*d-l.c*l.c));
        r.x = (-l.c * l.a - l.b * t) / d;
        r.y = (-l.c * l.b + l.a * t) / d;
        res.pb(r + centre);
        if (abs(l.c)<c.r*sqrt(d) - EPS) {
            r.x = (-l.c * l.a + l.b * t)/d;
            r.y = (-l.c * l.b - l.a * t)/d;
            res.pb(r + centre);
            return 2;
        }
        return 1;
    }
}

int cross(circle c1, circle c2, vector<point> &res) {
    // -1 = infinity; 0 = Empty; n = number of points
    point centre(c1.x, c1.y);
    res.clear();
    c2.x -= c1.x;
    c2.y -= c1.y;
    line l(2 * c2.x, 2 * c2.y,
        sqr(c2.r) - sqr(c1.r) - sqr(c2.x) - sqr(c2.y));
    int ans = cross(l, circle(0, 0,c1.r), res);
    forv(i, res) {
        res[i] = res[i] + centre;
    }
    return ans;
}

double vmul(const point& p1, const point& p2)
{
    return p1.x * p2.y - p1.y * p2.x;
}

double smul(const point& p1, const point& p2)
{
    return p1.x * p2.x + p1.y * p2.y;
}

double dist(const point& p1, const point& p2)
{
    return hypot(0.0 + p1.x - p2.x, 0.0 + p1.y - p2.y);
}

double ugol(const point& p1, const point& p2)
{
    return std::fabs(std::atan2(1.0 * vmul(p1, p2), 1.0 * smul(p1, p2)));
}

void outdata() {
    printf("%0.10lf\n", ans);
}

struct StoreStep
{
    point pv;
    point nv;
    point p;
    double dst;
    double len;
    double ans;
    int pos;
};

map<int, vector<StoreStep> > memory;

bool between(point x, point a, point b)
{
    return sign(vmul(x, a)) <= 0 && sign(vmul(x, b)) >= 0;
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

        point cp = s, np = p[ct];

        point nv = p[t] - p[t + 1];
        if (dir == 1) nv = point(-nv.x, -nv.y);

        point v(-nv.y, nv.x);

        forn(i, n) {
            if (curlen <= 0.0) break;
            StoreStep step;            
            step.ans = ugol(v, nv) * curlen * curlen / 2.0;
            step.len = curlen;
            step.pv = v;
            step.nv = nv;
            step.p = cp;
            step.pos = ct;
            step.dst = dist(cp, np);
            memory[dir].pb(step);
            curlen -= dist(cp, np);

            v = nv;
            cp = np;
            ct = (ct + dir + n) % n;
            np = p[ct];
            nv = np - cp;
        }
    }

    vector<StoreStep> to = memory[1];
    vector<StoreStep> back = memory[-1];
    size_t ix, jx;
    ix = jx = 0;
    double toLen, backLen;
    toLen = backLen = 0;
    while (ix < to.size() && jx < back.size()) {
        StoreStep t = to[ix];
        StoreStep b = back[jx];
        circle f(t.p.x, t.p.y, t.len);
        circle s(b.p.x, b.p.y, b.len);
        vector<point> res, nres;
        int c = cross(f, s, res);
        if (c != -1 && c != 0 && ix != 0 && jx != 0) {
            forv(q, res) {
                if (between(res[q] - t.p, t.nv, t.pv) &&
                    between(res[q] - b.p, b.pv, b.nv)) {
                    nres.pb(res[q]);
                }
            }
            if (!nres.empty()) {
                assert(nres.size() == 1);
                point per = nres[0];
                point tv = per - t.p;
                point bv = per - b.p;
                ans += ugol(tv, t.pv) * t.len * t.len / 2.0;
                ans += ugol(bv, b.pv) * b.len * b.len / 2.0;
                int st = t.pos, fn = (b.pos + 2) % n;
                point prev = t.p;
                while (st != fn) {
                    ans += fabs(vmul(per - prev, per - p[st]) / 2.0);
                    prev = p[st];
                    st = (st + 1) % n;
                }
                return ;
            }
        }
        if (toLen < backLen) {
            ++ix;
            toLen += t.dst;
            ans += t.ans;
        } else {
            ++jx;
            backLen += b.dst;
            ans += b.ans;
        }
    }
	while (ix < to.size()) {
		ans += to[ix].ans;
		++ix;
	}
	while (jx < back.size()) {
		ans += back[jx].ans;
		++jx;
	}
}

void checkLength()
{
    double per = 0.0;
    forn(i, n) per += dist(p[i], p[i + 1]);
    assert(per >= l * 2);
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
    assert(abs(s.x) <= 10000);
    assert(abs(s.y) <= 10000);
    assert(0 <= l && l <= 10000);
}

int main() {
    freopen(C_IN_FILE, "rt", stdin);
    freopen(C_OUT_FILE, "wt", stdout);
	readdata();
	solve();
	outdata();
	return 0;
}

