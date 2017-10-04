/*
ID: espr1t
LANG: C++
TASK: Clock
COMP: NOI Round 3, 2011
KEYWORDS: Simple Geometry/Math
*/

#include <cstdio>
#include <cmath>
#include <algorithm>
FILE *in; FILE *out;

int main(void)
{
	in = stdin; out = stdout;
//	in = fopen("Clock.in", "rt"); out = fopen("Clock.out", "wt");
	
	int hwr, mnt;
	fscanf(in, "%d:%d", &hwr, &mnt);
	
	if (hwr == 12) hwr = 0;
	double offsetLarge = (double)mnt / 60.0;
	double offsetSmall = (double)(hwr * 60 + mnt) / 720.0;
	
	double ans = std::min(fabs(offsetLarge - offsetSmall),
	                1.0 - fabs(offsetLarge - offsetSmall));
	fprintf(out, "%.3lf\n", ans * 360.0);
	return 0;
}
