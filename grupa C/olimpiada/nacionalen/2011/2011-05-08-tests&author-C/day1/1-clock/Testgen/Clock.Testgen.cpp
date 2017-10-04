#include <cstdio>
#include <algorithm>
#include <cmath>

char* times[21] = {
"04:23",
"06:30",
"01:40",
"06:00",
"12:00",
"01:11",
"02:22",
"03:33",
"04:44",
"05:55",
"06:06",
"07:07",
"10:51",
"11:45",
"05:24",
"02:20",
"12:30",
"11:45",
"12:59",
"01:42",
"11:11" };

double solve(int hwr, int mnt)
{
	if (hwr == 12) hwr = 0;
	double offsetLarge = (double)mnt / 60.0;
	double offsetSmall = (double)(hwr * 60 + mnt) / 720.0;
	
	double ans = std::min(fabs(offsetLarge - offsetSmall),
	                1.0 - fabs(offsetLarge - offsetSmall));
	return ans * 360.0;
}


int main(void)
{
	int numTests = 20;
	
	for (int test = 0; test <= numTests; test++)
	{
		char fileName[32];
		sprintf(fileName, "Clock.%02d.in", test);
		FILE *out = fopen(fileName, "wt");
		fprintf(out, "%s\n", times[test]);
		fclose(out);
		
		sprintf(fileName, "Clock.%02d.sol", test);
		out = fopen(fileName, "wt");
		int hwr, mnt;
		sscanf(times[test], "%d:%d", &hwr, &mnt);
		fprintf(out, "%.3lf\n", solve(hwr, mnt));
		fclose(out);
	}
	return 0;
}
