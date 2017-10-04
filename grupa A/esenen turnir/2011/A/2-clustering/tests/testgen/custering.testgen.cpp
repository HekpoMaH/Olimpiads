/*
ID: espr1t
LANG: C++
TASK: Clustering.Testgen
COMP: National Autumn Contest, 2011
KEYWORDS: Medium, Geometry, K-Means Algorithm, NP
*/

#include <cstdio>
#include <cstring>
#include <cstdlib>

#define MAX 1024
#define MX 10000
#define MY 10000
FILE* in; FILE* out;

struct Point
{
	double x, y;
	bool operator < (const Point& r) const
	{
		return x != r.x ? x < r.x : y < r.y;
	}
	Point(double x_ = 0, double y_ = 0) : x(x_), y(y_) {}
};

int n, k;
Point a[MAX];
int inCluster[MAX];
char vis[MX + 2][MY + 1];

void sampleInput()
{
	n = 7; k = 2;
	a[0] = Point(1, 2);
	a[1] = Point(1, 4);
	a[2] = Point(2, 5);
	a[3] = Point(3, 2);
	a[4] = Point(4, 4);
	a[5] = Point(5, 6);
	a[6] = Point(6, 5);
}

void randomTest(int numPoints, int numClusters)
{
	memset(vis, 0, sizeof(vis));

	n = numPoints; k = numClusters;
	for (int i = 0; i < n; i++)
	{
		int cx = 0, cy = 0;
		do {
			cx = rand() % MX + 1;
			cy = rand() % MY + 1;
		}
		while (cx < 0 || cx > MX || cy < 0 || cy > MY || vis[cx][cy]);
		a[i] = Point(cx, cy); vis[cx][cy] = 1;
	}
}

void clusteredTest(int numPoints, int numClusters)
{
	memset(vis, 0, sizeof(vis));
	memset(inCluster, 0, sizeof(inCluster));

	for (int i = 0; i < numPoints; i++)
		inCluster[rand() % numClusters]++;
	
	n = 0; k = numClusters;
	for (int i = 0; i < numClusters; i++)
	{
		int x = rand() % 9000 + 500;
		int y = rand() % 9000 + 500;
		
		int s = inCluster[i] > 20 ? inCluster[i] : 20;
		for (int c = 0; c < inCluster[i]; c++)
		{
			int cx = 0, cy = 0;
			do {
				cx = x + rand() % (4 * s) - 2 * s;
				cy = y + rand() % (4 * s) - 2 * s;
			}
			while (cx < 0 || cx > MX || cy < 0 || cy > MY || vis[cx][cy]);
			a[n++] = Point(cx, cy); vis[cx][cy] = 1;
		}
	}
}

void printTest(int test)
{
	char fileName[32];
	sprintf(fileName, "Clustering.%02d.in", test);
	FILE* out = fopen(fileName, "wt");
	fprintf(out, "%d %d\n", n, k);
	for (int i = 0; i < n; i++)
		fprintf(out, "%.0lf %.0lf\n", a[i].x, a[i].y);
	fclose(out);
}

int main(void)
{
	srand(42);
	int numTests = 20;
	int size[10] = {10, 20, 50, 70, 100, 200, 500, 800, 1000, 1000};
	int clusters[10] = {2, 3, 10, 2, 80, 5, 100, 20, 10, 100};
	
	for (int test = 0; test <= numTests; test++)
	{
		if (test == 0) sampleInput();
		else if (test <= 10) randomTest(size[test - 1], clusters[test - 1]);
		else if (test <= 20) clusteredTest(size[test - 11], clusters[test - 11]);
		printTest(test);
	}
	return 0;
}
