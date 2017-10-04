// FORMAT: input_file, competitor_out, solution, points_per_test

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

const double eps = 1e-5;

bool absEq(double a, double b)
{
	return abs(a-b) < eps;
}

bool relEq(double a, double b)
{
	return abs(a-b)/abs(a) < eps;
} 

int n;
double r, x[1<<17], y[1<<17], l[1<<17];

double dist(double X, double Y, double x, double y)
{
	return (X-x)*(X-x) + (Y-y)*(Y-y);
}

double dist(double X, double Y, int i)
{
	return dist(X, Y, x[i], y[i]);
}

double eval(double X, double Y)
{
	double val = 0;
	for (int i = 0; i < n; i++)
	{
		val = max(val, l[i] / dist(X, Y, i));
	}
	return val;
}

int evalp(double X, double Y)
{
	int p = 0;
	for (int i = 1; i < n; i++)
	{
		if (l[i] / dist(X, Y, i) > l[p] / dist(X, Y, p) + eps)
			p = i;
	}
	return p;
}

int main( int argc, char *argv[] )
{
	FILE* fin = fopen( argv[1], "r" ); //input file
	FILE* fc = fopen( argv[2], "r" );  //competitor file
	//FILE* fa = fopen( argv[3], "r" );  //solution file
	
	int points_per_test;
	sscanf(argv[4], "%d", &points_per_test);

	fscanf(fin, "%d %lf", &n, &r);
	for (int i = 0; i < n; i++)
	{
		fscanf(fin, "%lf %lf %lf", &x[i], &y[i], &l[i]);
	}

	double x1, y1, x2, y2;
	if (fscanf(fc, "%lf %lf %lf %lf", &x1, &y1, &x2, &y2) != 4)
	{
		printf("0\n");
		printf("Incorrect number of points in contestant output\n");
		return 0;
	}
	if (!absEq(dist(x1, y1, 0, 0), r*r) && !relEq(dist(x1, y1, 0, 0), r*r))
	{
		printf("0\n");
		printf("First satellite not on correct orbit r\n");
		return 0;
	}

	if (!absEq(dist(x2, y2, 0, 0), r*r) && !relEq(dist(x2, y2, 0, 0), r*r))
	{
		printf("0\n");
		printf("Second satellite not on correct orbit r\n");
		return 0;
	}
	if (!absEq(dist(x1, y1, x2, y2), 4.0*r*r) && !relEq(dist(x1, y1, x2, y2), 4.0*r*r))
	{
		printf("0\n");
		printf("Satellites not on maximum distance\n");
		return 0;
	}

	double e1, e2;
	e1 = eval(x1, y1);
	e2 = eval(x2, y2);
	if (!absEq(e1, e2) && !relEq(e1, e2))
	{
		printf("0\n");
		printf("Satellites on points with different luminosity %.12lf %.12lf\n", e1, e2);
		return 0;
	}
	
	printf("%d\n", points_per_test);
	printf("OK\n");
	
	fclose(fin);
	fclose(fc);
	return 0;
}
