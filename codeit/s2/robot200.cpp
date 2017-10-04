/*
ID: espr1t
TASK:
KEYWORDS:
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;
FILE *in; FILE *out;

const int MAX = 131072;
const int INF = 1000000001;

struct Point
{
    int x, y;
    bool operator < (const Point& r) const
    {
        return x != r.x ? x < r.x : y < r.y;
    }
};
int n, sx, sy;
Point a[MAX];
bool canDoIt(int dist)
{
    int left = 0, right = 0;
    map <int, int> q;
    q[a[left].y] = 1;
    while (left < n)
    {
        while (right + 1 < n && a[right + 1].x - a[left].x <= dist)
        {
            right++;
            map <int, int> :: iterator it = q.lower_bound(a[right].y);
            if (it != q.end())
            {
                if (abs(it->first - a[right].y) <= dist)
                    return true;
            }
            if (it != q.begin())
            {
                it--;
                if (abs(it->first - a[right].y) <= dist)
                    return true;
            }
            q[a[right].y]++;
        }
        map <int, int>::iterator it = q.find(a[left].y);
        it->second--;
        if (it->second==0)q.erase(it);
        left++;
    }
    return false;
}
int eval()
{
    sort(a, a + n);
    int left = 0, right = INF;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (canDoIt(mid))
            right = mid - 1;
        else left = mid + 1;
    }
    return right + 1;
}
int main(void)
{
	in = stdin; out = stdout;
	in = fopen("robot.in", "rt"); out = fopen("robot.out", "wt");

	fscanf(in, "%d %d %d", &sx, &sy, &n);
	for (int i = 0; i < n; i++)
	    fscanf(in, "%d %d", &a[i].x, &a[i].y);
	fprintf(out, "%d\n", eval());
	return 0;
}
