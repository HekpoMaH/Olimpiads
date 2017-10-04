/*
TASK: Clustering(checker)
LANG: C++
AUTHOR: Alexander Georgiev
COMPETITION: Autumn National Contest, 2011
*/

#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

#define MAX 1024

struct Point
{
	double x, y;
};

int n, k;
Point points[MAX];
Point author[MAX];
Point contestant[MAX];

double fdist(Point a, Point b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int check(char* inpFile, char* outFile, char* solFile)
{
	FILE* in = fopen(inpFile, "rt");
	fscanf(in, "%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		fscanf(in, "%lf %lf", &points[i].x, &points[i].y);
	fclose(in);

	FILE* sol = fopen(solFile, "rt");
	for (int i = 0; i < k; i++)
	{
		if (fscanf(sol, "%lf %lf", &author[i].x, &author[i].y) != 2)
		{
			fprintf(stderr, "Problem with author's solution!\n");
			return 1337;
		}
	}
	fclose(sol);

	FILE* out = fopen(outFile, "rt");
	for (int i = 0; i < k; i++)
	{
		if (fscanf(out, "%lf %lf", &contestant[i].x, &contestant[i].y) != 2)
		{
			fprintf(stderr, "Problem with contestants's solution!\n");
			return -1;
		}
	}
	fclose(out);

	double authScore = 0.0;
	for (int i = 0; i < n; i++)
	{
		double minDist = fdist(points[i], author[0]);
		for (int c = 0; c < k; c++)
			minDist = std::min(minDist, fdist(points[i], author[c]));
		authScore += minDist;
	}

	double contScore = 0.0;
	for (int i = 0; i < n; i++)
	{
		double minDist = fdist(points[i], contestant[0]);
		for (int c = 0; c < k; c++)
			minDist = std::min(minDist, fdist(points[i], contestant[c]));
		contScore += minDist;
	}

	double fract = std::min(1.0, authScore / contScore);
	return (int)round(fract * fract * 5.0);
}

int main(int argc, char* argv[])
{
	// Don't know which argument is which file, please fix
	// Also, can we have relative scoring? And what is the
	// formatting of score for test?
	// Talk to me if there are issues :) espr1t.net@gmail.com

//	char inpFile[] = "Clustering.in"; // Test input
//	char solFile[] = "Clustering.sol"; // Test solution
//	char outFile[] = "Clustering.out"; // Contestant solution

	int res = check(argv[1], argv[2], argv[3]);

	if (res > 0)
	  {
	      fprintf(stderr, "%d\n", res);
	      fprintf(stderr, "OK!\n");
	  }
	else
	  {
	      fprintf(stderr, "0\n");
	      fprintf(stderr, "Wrong Answer!\n");
	  }

	return 0;
}
