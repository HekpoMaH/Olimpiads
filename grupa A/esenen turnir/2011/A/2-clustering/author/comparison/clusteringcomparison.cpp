/*
ID: espr1t
LANG: C++
TASK: Clustering
COMP: National Autumn Contest, 2011
KEYWORDS: Medium, NP, Geometry, K-Means Algorithm
*/

#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAX 1024
#define INF 999666333

#define MX 10000
#define MY 10000

#define MAX_EXEC_TIME 0.8
#define MAX_EXEC_TIME_DUMMY1 1.6
#define MAX_EXEC_TIME_DUMMY2 2.4
#define MAX_INNER 10
#define MAX_ITERATIONS 50

#define COMPARE 1

FILE* in; FILE* out;

struct Point
{
	double x, y;
	Point(double x_ = 0.0, double y_ = 0.0) : x(x_), y(y_) {}
};

int n, k;
Point a[MAX];

double best = INF;
Point ans[MAX];

double cur;
Point p[MAX], s[MAX];
int cnt[MAX], assigned[MAX], initial[MAX];

unsigned startTime;

double getTime()
{
	return (double)(clock() - startTime) / (double)CLOCKS_PER_SEC;
}

double fdist(Point a, Point b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

void eval()
{
	int numIters = 0;
	while (getTime() < MAX_EXEC_TIME)
	{
		if (++numIters > MAX_ITERATIONS) break;
		
		// Create initial configuration
		cur = INF;
		for (int i = 0; i < n; i++)
			initial[i] = i;
		std::random_shuffle(initial, initial + n);
		for (int i = 0; i < k; i++) p[i] = a[initial[i]];
		for (int i = 0; i < n; i++) assigned[i] = rand() % k;
		
		// Use K-means repeatedly to optimize
		int changeFlag = 1, inner = 0;
		while (changeFlag)
		{
			changeFlag = 0;
			if (++inner > MAX_INNER)
			{
				inner = 0;
				if (getTime() > MAX_EXEC_TIME) break;
			}
			
			cur = 0;
			for (int i = 0; i < k; i++)
				cnt[i] = 0, s[i].x = 0.0, s[i].y = 0.0;

			for (int i = 0; i < n; i++)
			{
				int closest = 0;
				double closestDist = INF;
				for (int c = 0; c < k; c++)
				{
					double cdist = fdist(a[i], p[c]);
					if (cdist < closestDist) closestDist = cdist, closest = c;
				}
				cnt[closest]++;
				cur += closestDist;
				s[closest].x += a[i].x; s[closest].y += a[i].y;
				if (assigned[i] != closest) {changeFlag = 1; assigned[i] = closest;}
			}
			for (int i = 0; i < k; i++)
				if (cnt[i] != 0) s[i].x /= cnt[i], s[i].y /= cnt[i];
			for (int i = 0; i < k; i++) p[i] = s[i];
		}
		
		if (cur < best)
		{
			best = cur;
			for (int i = 0; i < k; i++) ans[i] = p[i];
		}
	}
	
	for (int i = 0; i < k; i++)
		fprintf(out, "%lf %lf\n", ans[i].x ,ans[i].y);
#if COMPARE
	fprintf(stdout, "Best answer found by K-means was: %.6lf\n", best);
#endif
}

double getAnswer()
{
	double ret = 0;
	for (int i = 0; i < n; i++)
	{
		double closestDist = INF;
		for (int c = 0; c < k; c++)
			closestDist = std::min(closestDist, fdist(a[i], p[c]));
		ret += closestDist;
	}
	return ret;
}

void dummy1()
{
	int minX = MX, maxX = 0;
	int minY = MY, maxY = 0;
	for (int i = 0; i < n; i++)
	{
		if (minX > a[i].x) minX = (int)a[i].x;
		if (maxX < a[i].x) maxX = (int)a[i].x;
		if (minY > a[i].y) minY = (int)a[i].y;
		if (maxY < a[i].y) maxY = (int)a[i].y;
	}
	
	best = INF;
	while (getTime() < MAX_EXEC_TIME_DUMMY1)
	{
		for (int i = 0; i < k; i++)
		{
			p[i].x = minX + rand() % (maxX - minX + 1);
			p[i].y = minY + rand() % (maxY - minY + 1);
		}
		
		cur = getAnswer();		
		if (cur < best)
		{
			best = cur;
			for (int i = 0; i < k; i++) ans[i] = p[i];
		}
	}
#if COMPARE	
	fprintf(stdout, "Best answer found by dummy1 was: %.6lf\n", best);
#endif
}

void dummy2()
{
	int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

	int minX = MX, maxX = 0;
	int minY = MY, maxY = 0;
	for (int i = 0; i < n; i++)
	{
		if (minX > a[i].x) minX = (int)a[i].x;
		if (maxX < a[i].x) maxX = (int)a[i].x;
		if (minY > a[i].y) minY = (int)a[i].y;
		if (maxY < a[i].y) maxY = (int)a[i].y;
	}
	
	best = INF;
	while (getTime() < MAX_EXEC_TIME_DUMMY2)
	{
		for (int i = 0; i < k; i++)
		{
			p[i].x = minX + rand() % (maxX - minX + 1);
			p[i].y = minY + rand() % (maxY - minY + 1);
		}
		
		int step = 64;
		cur = getAnswer();
		while (step)
		{
			int inner = 0;
			for (int i = 0; i < k; i++)
			{
				if (++inner > MAX_INNER)
				{
					inner = 0;
					if (getTime() > MAX_EXEC_TIME_DUMMY2)
					{
						step = 0;
						break;
					}
				}
				int flag = 0;
				for (int c = 0; c < 4; c++)
				{
					p[i].x += dir[c][0] * step;
					p[i].y += dir[c][1] * step;
					double tmp = getAnswer();
					if (tmp < cur) {cur = tmp; flag = 1; break;}
					p[i].x -= dir[c][0] * step;
					p[i].y -= dir[c][1] * step;
				}
				if (flag) {i--; continue;}
			}
			step /= 2;
		}
		if (cur < best)
		{
			best = cur;
			for (int i = 0; i < k; i++) ans[i] = p[i];
		}
	}
#if COMPARE	
	fprintf(stdout, "Best answer found by dummy2 was: %.6lf\n", best);
#endif
}

void compare()
{
	eval();
	dummy1();
	dummy2();
	system("pause");
}

int main(void)
{
	in = stdin; out = stdout;
	in = fopen("Clustering.in", "rt"); out = fopen("Clustering.out", "wt");
	
	srand(42);
	startTime = clock();
	fscanf(in, "%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		fscanf(in, "%lf %lf", &a[i].x, &a[i].y);
	
#if COMPARE
	compare();
#else
	eval();
#endif

	return 0;
}
