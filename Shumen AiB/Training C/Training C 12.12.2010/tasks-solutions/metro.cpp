#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <cassert>
#include <algorithm>

#define verbal

using namespace std;

const int vmax = 1000;
const double U = 10.0;
const double R = 15.71;

double cost[71] = {
0, 22, 44, 64.33, 84.67, 105, 124, 143, 162, 181, 200, 218, 236, 254, 272, 290, 308, 326, 344,
362, 380, 392.13, 404.25, 416.38, 428.5, 440.63, 452.75, 464.88, 477, 489.13, 501.25, 513.38, 525.5, 537.63, 549.75, 561.88, 574,
586.13, 598.25, 610.38, 622.5, 634.63, 646.75, 658.88, 671, 683.13, 695.25, 707.38, 719.5, 731.63, 743.75, 755.88, 768, 780.13, 792.25,
804.38, 816.5, 828.63, 840.75, 852.88, 865, 863.5, 862, 860.5, 859, 857.5, 856, 854.5, 853, 851.5, 850
};

double Cost(int n)
{
	return cost[min(70, n)] + U*(n > 0) + max(n - 70, 0)*R;
}

int main()
{
	freopen("d.in", "rt", stdin);
	freopen("d.out", "wt", stdout);

	for (int k = 70; k > 0; --k)
		if (cost[k] + 1e-9 < cost[k - 1]) cost[k - 1] = cost[k];

	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	assert(0 <= a && a <= 1000 && 0 <= b && b <= 1000 && 0 <= c && c <= 1000);

	double best = 1e+100;

	for (int k = 0; k <= 2*c; ++k)
	{
		double x = Cost(a + k);
		double y = Cost(b + 2*c - k);

	#ifdef verbal
		fprintf(stderr, "%d  %d = %0.2lf\n", a + k, b + 2*c - k, x + y);
    #endif

        if (best > x + y + 1e-9) best = x + y;
	}
    printf("%0.2lf\n", best);

	return 0;
}
