/*
LANG: C++
TASK: riddles
ID: espr1t
TOUR: Dean's Cup 2009
*/

#include <iostream>
#define MAX 131072
#define MM 1048576

using namespace std;
FILE *in; FILE *out;

int main(void)
{
	out = fopen("riddles.in", "wt");
	
	int numTests = 10;
	int n[10] = { 10, 40, 100, 500, 1000, 5000, 20000, 30000, 50000, 100000 };
	int k[10] = { 12, 60, 201, 555, 1337, 4300, 42424, 33333, 50000, 1000000 };

	fprintf(out, "%d\n", numTests);
	for (int test = 0; test < numTests; test++)
	{
		fprintf(out, "%d %d\n", n[test], k[test]);
		for (int i=0; i<n[test]; i++) fprintf(out, "%d%c", rand() % (k[test] + 13) + 1, i + 1 == n[test] ? '\n' : ' ');
	}

	return 0;
}
