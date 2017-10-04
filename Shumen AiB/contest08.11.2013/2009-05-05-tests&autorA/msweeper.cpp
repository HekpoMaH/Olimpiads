/*
TASK: msweeper
LANG: C++
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

#define MAX 10002
#define PI 3.1415926535897932384626433832795

using namespace std;

struct Point
{
	int x, y;
	Point (int cx = 0, int cy = 0) {x = cx; y = cy;}

	bool operator < (const Point& r) const
	{
		if (x != r.x) return x < r.x;
		return y < r.y;
	}
}; // End of struct Point

int n, r;
vector <Point> points;
vector <Point> convexHull;

inline int directedArea(Point& p1, Point& p2, Point& p3)
{
	return (long long)p1.x * p2.y + (long long)p2.x * p3.y + (long long)p3.x * p1.y -
		   (long long)p1.x * p3.y - (long long)p2.x * p1.y - (long long)p3.x * p2.y;
}

inline double dist(Point& p1, Point& p2)
{
	return sqrt((double)(p2.x - p1.x) * (double)(p2.x - p1.x)+
			    (double)(p2.y - p1.y) * (double)(p2.y - p1.y));
}

void createConvexHull()
{
	vector < Point > upperHull;
	vector < Point > lowerHull;

	convexHull.clear();
	sort(points.begin(), points.end());
	
	// Upper part of the hull
	for (int i=0; i<(int)points.size(); i++)
	{
		upperHull.push_back(points[i]);
		while (upperHull.size() >= 3)
		{
			if (directedArea(upperHull[upperHull.size() - 1],
							 upperHull[upperHull.size() - 2],
							 upperHull[upperHull.size() - 3]) <= 0)
			{
				upperHull.erase(upperHull.end() - 2);
			}
			else break;
		}
	}
	convexHull = upperHull;
	
	// Lower part of the hull
	for (int i=0; i<(int)points.size(); i++)
	{
		lowerHull.push_back(points[i]);
		while (lowerHull.size() >= 3)
		{
			if (directedArea(lowerHull[lowerHull.size() - 1],
							 lowerHull[lowerHull.size() - 2],
							 lowerHull[lowerHull.size() - 3]) >= 0)
			{
				lowerHull.erase(lowerHull.end() - 2);
			}
			else break;
		}
	}
	if (lowerHull.size() > 0) lowerHull.erase(lowerHull.begin());
	if (lowerHull.size() > 0) lowerHull.erase(lowerHull.end() - 1);
	
	convexHull.insert(convexHull.end(), lowerHull.rbegin(), lowerHull.rend());
	return;
}

int main(void)
{
	FILE *in = stdin, *out = stdout;
//	in = fopen("msweeper.in", "rt"); out = fopen("msweeper.out", "wt");
	
	fscanf(in, "%d %d", &n, &r);
	for (int i=0; i<n; i++)
	{
		int x, y;
		fscanf(in, "%d %d", &x, &y);
		points.push_back(Point(x, y));
	}
	
	double ans = 2.0 * PI * r;
	createConvexHull();
	
	for (int i=1; i<(int)convexHull.size(); i++)
		ans += dist(convexHull[i - 1], convexHull[i]);
	if (convexHull.size() > 1)
		ans += dist(convexHull[convexHull.size() - 1], convexHull[0]);
	
	fprintf(out, "%.3lf\n", ans);
	return 0;
};
