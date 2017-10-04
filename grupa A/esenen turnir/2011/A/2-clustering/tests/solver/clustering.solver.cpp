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
#define MAX_INNER 10
#define MAX_ITERATIONS 10

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
}

int solve(int test)
{
	in = stdin; out = stdout;
	char inpFile[32], outFile[32];
	sprintf(inpFile, "Clustering.%02d.in", test);
	sprintf(outFile, "Clustering.%02d.sol", test);
	in = fopen(inpFile, "rt"); out = fopen(outFile, "wt");
	
	srand(42);
	best = INF;
	startTime = clock();
	fscanf(in, "%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		fscanf(in, "%lf %lf", &a[i].x, &a[i].y);
	
	eval();

	fclose(in); fclose(out);
	return 0;
}

int main(void)
{
	int numTests = 20;
	for (int test = 0; test <= numTests; test++)
	{
		fprintf(stdout, "Currently solving testcase nr. %d\n", test);
		solve(test);
	}
	fprintf(stdout, "Solved all tests succesfully!\n");
	system("pause");
	return 0;
}
